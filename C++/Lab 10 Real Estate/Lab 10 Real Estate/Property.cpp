
#include <string>
#include <iostream>
#include <sstream>
#include "Property.h"
using namespace std;
int Property::propertyCounter = 0;
Property::Property(){


}
Property::Property( bool rental, double value, string address){
	propertyAddress = address;
	propertyValue = value;
	rentProperty = rental;
	propertyID = propertyCounter;
	propertyCounter++;
}

string Property::toString(){
	stringstream ss;
	ss << "HILLL\n";
	return ss.str();

}

void Property:: calculate_taxes(){

}

string  Property :: toStringTax(){
	return " haha";
}

