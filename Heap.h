/* *~*~*
Heap template
Written By: A. Student
Changed by:
IDE:  
*~**/

#ifndef HEAP_H_
#define HEAP_H_
#include <iostream>

template<class ItemType>
class Heap
{
private:
	ItemType* heapAry;
	int heapSize;
	int count;

	// function pointer compare : 0 means equal, 1 means left > right, -1 means left < right
	void _reHeapUp(int lastndx, int compare(const ItemType &, const ItemType &));
	void _reHeapDown(int rootndx, int compare(const ItemType &, const ItemType &));
	int _findParent(int index) { return (index <= 0) ? (-1) : (index - 1) / 2; }
	int _findLeftChild(int index) { return (2 * index + 1 >= count) ? (-1) : (2 * index + 1); }
	int _findRightChild(int index) { return (2 * index + 2 >= count) ? (-1) : (2 * index + 2); }

public:
	Heap() { count = 0; heapSize = 128; heapAry = new ItemType[heapSize]; }
	Heap(int n) { count = 0; heapSize = n;	heapAry = new ItemType[heapSize]; }
	~Heap() { delete[] heapAry; }

	int getCount() const { return count; }
	int getSize() const { return heapSize; }
	bool isEmpty() const { return count == 0; }
	bool isFull()  const { return count == heapSize; }
	bool insertHeap(ItemType &itemIn, int compare(const ItemType &, const ItemType &));
	bool deleteHeap(ItemType &itemOut, int compare(const ItemType &, const ItemType &));

	void display() {
		for (int i = 0; i < count; i++) {
			std::cout << heapAry[i].getYear() << " " << heapAry[i].getMileage()
				<< " (" << getSerial(heapAry[i]) << ") ["
				<< heapAry[i].getName() << "]" << std::endl;
		}
	}

};

/* *~*~*
 The private member function _reHeapUp rearranges the heap after insert by moving the
 last item up to the correct location in the heap
 *~**/
template<class ItemType>
void Heap<ItemType>::_reHeapUp(int lastndx, int compare(const ItemType &, const ItemType &))
{
	if (lastndx) // means lastndx != 0, i.e. newElement is not heap's root
	{
		int parentIndx = _findParent(lastndx);
		if (compare(heapAry[parentIndx], heapAry[lastndx]) > 0) {
			ItemType tmp = heapAry[lastndx];
			heapAry[lastndx] = heapAry[parentIndx];
			heapAry[parentIndx] = tmp;
			_reHeapUp(parentIndx, compare);
		}
		return;
	}
}

/* *~*~*
 The private member function _reHeapDown rearranges the heap after delete by moving the
 data in the root down to the correct location in the heap
 *~**/
template<class ItemType>
void Heap<ItemType>::_reHeapDown(int rootdex, int compare(const ItemType &, const ItemType &))
{
	int left = _findLeftChild(rootdex);
	int right = _findRightChild(rootdex);
	if (left != -1) // if there's a left child
	{
		int comp = left;
		if (right != -1) //if there's a right child
		{
			if (compare(heapAry[left], heapAry[right]) > 0)
			{
				comp = right;    //makes comparison the right node
			}
		}
		if (compare(heapAry[rootdex], heapAry[comp]) > 0)
		{
			//swaps comparison node with rootdex
			ItemType temp = heapAry[rootdex];
			heapAry[rootdex] = heapAry[comp];
			heapAry[comp] = temp;

			//recursive call to move node down
			_reHeapDown(comp, compare);
		}
	}
}



/* *~*~*
 The public member function insertHeap inserts a new item into a heap.
 It calls _reheapUp.
 *~**/
template<class ItemType>
bool Heap<ItemType>::insertHeap(ItemType& newItem, int compare(const ItemType &, const ItemType &))
{
	if (isFull())
		return false;

	heapAry[count] = newItem;
	_reHeapUp(count, compare);
	count++;

	return true;
}

/* *~*~*
 The public member function deleteHeap deletes the root of the heap and
 passes back the root's data. It calls _reheapDown.
 *~**/
template<class ItemType>
bool Heap<ItemType>::deleteHeap(ItemType& returnItem, int compare(const ItemType &, const ItemType &))
{
	if (isEmpty())
		return false;

	count--;
	returnItem = heapAry[0];
	heapAry[0] = heapAry[count];
	_reHeapDown(0, compare);
	return true;
}

#endif   