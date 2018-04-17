#pragma once

#include <string>
#include <iostream>
#include "Property.h"
using namespace std;

class Commercial : public Property{
public:
	Commercial();
	Commercial(bool rental, double value, bool taxDiscounted, double discountRate, string address);
	string toString();
	void calculate_taxes();
	string toStringTax();

protected:
	bool discount;
	double discount_rate;
	double taxes;


};