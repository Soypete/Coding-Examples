
#include <string>
#include <iostream>
#include <sstream>
#include "Commercial.h"
using namespace std;

Commercial::Commercial(){


}
Commercial::Commercial(bool rental, double value, bool taxDiscounted, double discountRate, string address) : Property(rental, value, address){
	discount = taxDiscounted;
	discount_rate = discountRate;
	//taxes = 0;
}
//calcualte taxes
void Commercial :: calculate_taxes(){
	if (rentProperty){
		taxes = propertyValue *(.012 - .012*discount_rate);
	}
	else{
		taxes = propertyValue *(.01 - .01*discount_rate);
	}

}
//print out tax information
string Commercial :: toStringTax(){
	stringstream streamPrint;
	streamPrint << "\nTaxes due for the property at: " << propertyAddress << "\n";
	streamPrint << "Property id: " << propertyID << "\n";
	streamPrint << "This property has an estimated value of: " << propertyValue << "\n";
	streamPrint << "Taxes due on this property are: $" << taxes << "\n";
	return streamPrint.str();
}
//print out property information
string Commercial::toString(){

	stringstream streamPrint;
		streamPrint << "Property id: " << propertyID << "\tAddress : " << propertyAddress;
	if (rentProperty){
		streamPrint << "\tRental ";
	}
	else {
		streamPrint << "\tNOT Rental ";
	}
	streamPrint << "\tEstimate Value : $" << propertyValue; 
	if (discount){
	streamPrint << "\tTax discount : $" << discount_rate << "\n";
	}
	else {
		streamPrint << "\tNOT discounted\n";
	}
	return streamPrint.str();
}