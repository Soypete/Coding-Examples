#pragma once

#include <string>
#include <iostream>
using namespace std;

class Property{
public:
	Property();
	Property(bool rental, double value, string address);
	//pure virtual for they must exist in the child function
	virtual string toString() = 0;
	virtual void calculate_taxes() = 0;
	virtual string toStringTax() = 0;

protected:
	static int propertyCounter;
	string propertyAddress;
	double propertyValue;
	bool rentProperty;
	int propertyID;





};