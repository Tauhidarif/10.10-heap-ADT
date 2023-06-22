/*
  Heaps - ADT

  This program will read data about overbooked customers,
  find their priority and serial numbers, build a heap, then display
  customers in priority sequence
 
  Written By: A. Student
  Changed By: Tauhid Malik
  IDE: Visual Studio
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include "Customer.h"
#include "Heap.h"

using namespace std;

int compareSer(const Customer&, const Customer&);

int main()
{
    // Get input file name
    string inputFileName;
    cout << "Input file name: ";
    getline(cin, inputFileName);
    cout << endl;
    
    ifstream inFile;
    inFile.open(inputFileName);

    if (!inFile)
        exit(EXIT_FAILURE);

    string line;
    Heap<Customer> heap;
    int i = 1, served = 0, rejected = 0;

    while (getline(inFile, line)) {
        stringstream temp(line);
        char arrive_serve;
        int totalMileage, numberOfYears;
        string name;

        temp >> arrive_serve;
        
        if (arrive_serve == 'A') {
            temp >> numberOfYears;
            temp >> totalMileage;
            getline(temp, name);
            Customer customer(totalMileage, numberOfYears, i, name);

            //cout << numberOfYears << 
            heap.insertHeap(customer, compareSer);
            i++;
        }
        else {
            //heap.display();
            Customer dltCustomer;
            heap.deleteHeap(dltCustomer, compareSer);

            cout << dltCustomer.getYear() << " " << dltCustomer.getMileage()
                 << " (" << getSerial(dltCustomer) << ") [" 
                 << dltCustomer.getName() << "]" << endl;
            served++;
        }
    }

    cout << "Served overbooked customers: " << served << endl;
    cout << endl;
    
    heap.display();
    rejected = i - served - 1;
    std::cout << "Rejected overbooked customers: " << rejected << endl;
    inFile.close();

    return 0;
}

/*
  compare two data items: needed to build a min-heap
*/
int compareSer(const Customer& x, const Customer& y)
{
    int ser1, ser2;

    ser1 = getSerial(x);
    ser2 = getSerial(y);

    if (ser1 > ser2)
        return -1;
    if (ser1 == ser2)
        return 0;
    return 1;
}
