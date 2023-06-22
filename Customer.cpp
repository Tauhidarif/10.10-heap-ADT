/* *~*~*
Implementation file for the Customer class
Written By: A. Student
Changed by:
IDE:
*~**/
#include <iostream>
#include <string> 
#include "Customer.h"

using namespace std;

int getSerial(const Customer& obj) {
    int prioNum;

    prioNum = getPrio(obj);

    return (prioNum * 100) + (100 - obj.seq);
}

int getPrio(const Customer& obj) {
    return (obj.mileage / 1000) + obj.year - obj.seq;
}