/* *~*~*
  Specification file for the Customer class
  Written By: A. Student
  Changed by: Tauhid Malik
  IDE: Visual Studio
  *~**/
#ifndef CUSTOMER_H_
#define CUSTOMER_H_

using std::string;

class  Customer; // Forward Declaration

// Function Prototypes for friend functions
int getSerial(const Customer&);
int getPrio(const Customer&);


class Customer
{
private:
    int year;
    int mileage;
    int seq;
	string name;
	
public:
    Customer() {
        year = 0;
        mileage = 0;
        seq = 0;
        name = "";
   }
    Customer(int m, int y, int s, string n) {
        mileage = m;
        year = y;
        seq = s;
        name = n;
    }

    int getYear() const { return year; }
    int getMileage() const { return mileage; }
    int getSeq() const { return seq; }
    string getName() const { return name; }

    friend int getSerial(const Customer&);
    friend int getPrio(const Customer& obj);

};

#endif