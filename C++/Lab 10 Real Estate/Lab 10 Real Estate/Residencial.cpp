
#include <string>
#include <iostream>
#include <sstream>
#include "Residencial.h"
using namespace std;

Residencial::Residencial(){


}
Residencial::Residencial(bool rental, double value, bool occupied, string address) : Property(rental, value, address){
	
	vacancy = !occupied;
	taxes = 0;

}
//calculate taxes
void Residencial :: calculate_taxes(){
	if (!vacancy){
		taxes = propertyValue *(.006);
	}
	else{
		taxes = propertyValue *(.009);
	}
}
//prints out tax information
string Residencial :: toStringTax(){
	stringstream streamPrint;
	streamPrint << "\nTaxes due frothe property at: " << propertyAddress << "\n";
	streamPrint << "Property id: " << propertyID << "\n";
	streamPrint << "This property has an estimated value of: " << propertyValue << "\n";
	streamPrint << "Taxes due on this property are: $" << taxes << "\n";
	return streamPrint.str();
}
//print out property information
string Residencial::toString(){

	stringstream streamPrint;
	streamPrint << "Property id: " << propertyID << "\tAddress : " << propertyAddress;
	if (rentProperty){
		streamPrint << "\tRental ";
	}
	else {
		streamPrint << "\tNOT Rental ";
	}
	streamPrint << "\tEstimate Value : $" << propertyValue;
	if (vacancy){
		streamPrint << "\tNOT occupied\n ";
	}
	else{
		streamPrint << "Occupied\n";
	}
	return streamPrint.str();
}