
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Property.h"
#include "Commercial.h"
#include "Residencial.h"
using namespace std;

int main(){
	string filename;
	vector < Property* >  propertyList;
	ifstream propertyFile;

	//prompt the user for the file address
	cout << "What file would you like to pull your properties from? ";
	cin.sync();
	getline(cin, filename);
	filename += ".txt";
	//read in file information
	ifstream in_file;
	in_file.open(filename);
	if (!in_file.fail()){
		string propertyInfo;
		while (getline(in_file, propertyInfo)){
			istringstream newProperty;
			newProperty.str(propertyInfo);
			string propertyType;
			int i = 0;
			//tests to see if residential of commercial
			while (isalpha(propertyInfo[i])){
				i++;
			}
			propertyType = propertyInfo.substr(0, i);

			if (propertyType == "Residential"){
				bool rental;
				double value;
				bool occupied;
				bool valid = true;
				string address;
				newProperty >> propertyType;
				newProperty >> rental;
				//verifies that is bool
				if (newProperty.fail()){
					newProperty.ignore();
					newProperty.clear();
					cout << "invalid file... " << propertyInfo << endl;
				}
				else{
					newProperty >> value;
					//verifies that is double
					if (newProperty.fail()){
						newProperty.ignore();
						newProperty.clear();
						cout << "invalid file... " << propertyInfo << endl;
					}
					else{
						//verifies that is boolean
						newProperty >> occupied;
						if (newProperty.fail()){
							newProperty.ignore();
							newProperty.clear();
							cout << "invalid file... " << propertyInfo << endl;
						}
						else{
							getline(newProperty, address);
							//address = address + " " + address2 + " " + address3;
							//add to vector
							propertyList.push_back(new Residencial(rental, value, occupied, address));

						}
					}
				}


			}
			//simiar set up to residential
			else if (propertyType == "Commercial"){
				bool rental;
				double value;
				bool taxDiscounted;
				double discountRate;
				string address;
				newProperty >> propertyType;
				newProperty >> rental;
				if (newProperty.fail()){
					newProperty.ignore();
					newProperty.clear();
					cout << "invalid file... " << propertyInfo << endl;
				}
				else{
					newProperty >> value;
					if (newProperty.fail()){
						newProperty.ignore();
						newProperty.clear();
						cout << "invalid file... " << propertyInfo << endl;
					}
					else{
						newProperty >> taxDiscounted;
						if (newProperty.fail()){
							newProperty.ignore();
							newProperty.clear();
							cout << "invalid file... " << propertyInfo << endl;
						}
						else{
							newProperty >> discountRate;
							if (newProperty.fail()){
								newProperty.ignore();
								newProperty.clear();
								cout << "invalid file... " << propertyInfo << endl;
							}
							else{
								getline(newProperty, address);
								//address = address + " " + address2 + " " + address3;
								propertyList.push_back(new Commercial(rental, value, taxDiscounted, discountRate, address));
						
							}
						}
					}
				}
			}
			else {
				// return error
				cout << "invalid file... " << propertyInfo << endl;
			}
		}
		in_file.close();
		//print out information
		for (int k = 0; k < propertyList.size(); k++){
			string toPrint = propertyList[k]->toString();
			cout << toPrint;
		}
		//print our taxes
		for (int k = 0; k < propertyList.size(); k++){
			propertyList[k]->calculate_taxes();
			string toPrint = propertyList[k]->toStringTax();
			cout << toPrint;
		}
	}
	//error if file doesn't exist
 else{ cout << " File DOES NOT EXIST\n"; }
 system("pause");
 return 0;
}