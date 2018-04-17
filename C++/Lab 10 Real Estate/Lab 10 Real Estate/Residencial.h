#pragma once

#include <string>
#include <iostream>
#include "Property.h"
using namespace std;

class Residencial: public Property{
public:
	Residencial();
	Residencial(bool rental, double value, bool occupied, string address);
	string toString();
	void calculate_taxes();
	string toStringTax();

protected:
	bool vacancy;
	double taxes;




};