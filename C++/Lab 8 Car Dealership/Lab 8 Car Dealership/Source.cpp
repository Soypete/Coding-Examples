
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
#include "Car.h"

//Test Cases
//Case1															Case2										Case3
//option 3 buy car $10001										import cars2								import cars2
//recieve error													sell Lemon									import cars1
//paint Pinto blue												sell Lemon									print out balance
//paint pinto													Lemon doesn't exist							sell Lemon
//pinto doesn't exist											buy carola $200								export file "test"
//																print out inventory
//																opiton 8 exit
//all test cases performed as expected

int printOurMenu(){
	int input;
	

	cout << "Choose one of the following options:\n";
	cout << "1 - Show Current Inventory\n";
	cout << "2 - Show Current Balance\n";
	cout << "3 - Buy a Car\n";
	cout << "4 - Sell a Car\n";
	cout << "5 - Paint a Car\n";
	cout << "6 - Load File\n";
	cout << "7 - Save File\n";
	cout << "8 - Quit Program\n";

	cin >> input;

	return input;
}
double buyCar(double totalBalance, vector<Car>& currentInventory){

	//ask user for car information
	cout << "What kind of car would you like to buy? ";
	string carType;
	cin >> carType;
	cout << "What color is it? ";
	string color;
	cin >> color;
	cout << "How much is it? ";
	double price;
	cin >> price;
	bool carExists = false;
	
	
	//check to see if exists
	for (int i = 0; i < currentInventory.size(); i++){
		if (carType == currentInventory[i].getName()){
			carExists = true;
		}
	}
	if (carExists){
		cout << "Car already in stock\n";
	}
	else{
		
		//compare the price with balance and print out error
		if (price > totalBalance){
			cout << "that price is too high.\n";
		}
		//add item to vector by calling constrictor
		//substract from balance
		else {
			currentInventory.push_back(Car(carType, color, price));
			totalBalance -= price;
		}
	}
	
	return totalBalance;
}
double sellCar(double totalBalance, vector<Car>& currentInventory){
	//ask user for the car name
	cout << "what car would you like to sell?: ";
	string carType;
	cin >> carType;
	bool carExists = false;
	//remove item from array based on name
	//getprice and add it to the balance
	for (int i = 0; i < currentInventory.size(); i++){
		if (carType == currentInventory[i].getName() && !carExists){
			totalBalance += currentInventory[i].getPrice();
			currentInventory.erase(currentInventory.begin() + i);
			carExists = true;
		}
	}if (!carExists){
		cout << "car not found.\n";
	}
	return totalBalance;
}
void paintCar(vector<Car>& currentInventory){
	//prompt user for name of existing car and paint color
	cout << "What car would you like to paint? ";
	string carType;
	cin >> carType;
	cout << "What color would you like to paint your car? ";
	string color;
	cin >> color;
	bool exists = false;
	//use for loop to search for the car
	for (int i = 0; i < currentInventory.size(); i++){
		if (carType == currentInventory[i].getName()){
			//change the color
			currentInventory[i].paint(color);
			exists = true;
		}
	}if (!exists){
		cout << "Car not found\n";
	}
}


int main(){

	//part1 displays the menu while the user doesn'e want to leave
	int input;
	double totalBalance = 10000.00;
	vector<Car> currentInventory;
	//Car Car;
	do{
		input = printOurMenu();
		//print out inventory
		if (input == 1){
			//for loop through vector and use to string to print out each item
			string printOut;
			for (int i = 0; i < currentInventory.size(); i++){
				string currentCar = currentInventory[i].toString();
				cout << currentCar << endl;
			}
		}
		//print out ballance
		else if (input == 2){
			//print out balance
			cout << fixed << setprecision(2) << "$" << totalBalance << endl;
		}
		else if (input == 3){
			totalBalance = buyCar(totalBalance, currentInventory);
		}
		else if (input == 4){
			totalBalance = sellCar(totalBalance, currentInventory);
		}
		else if (input == 5){
			paintCar(currentInventory);
			
		}
		else if (input == 6){
			//ask user for file name
			string fileName;
			cout << "What is the file you would like to import called? ";
			
			cin >> fileName;
			fileName += ".txt";
			//load file
			ifstream in_file;
			in_file.open(fileName);
			string balance;
			getline(in_file, balance);
			string carInfo;
			while (getline(in_file, carInfo)){
				 
				istringstream inputCar;
				inputCar.str(carInfo);
				string carType;
				string color;
				double price;
				inputCar >> carType >> color >> price;

				totalBalance = stod(balance.substr(0));

				currentInventory.push_back(Car(carType, color, price));
			}

			in_file.close();
		}
		else if (input == 7){
			//ask user for filename 
			cout << "What would you like to call you inventory file? ";
			string fileName;
			cin >> fileName;
			fileName += ".txt";
			//save file
			ofstream out_file;
			out_file.open(fileName);
			out_file << fixed << setprecision(2) << totalBalance << endl;
			for (int i = 0; i < currentInventory.size(); i++){
				out_file << currentInventory[i].getName() << " " << currentInventory[i].getColor() << " " << fixed <<setprecision(2) << currentInventory[i].getPrice() << endl;
			}
			out_file.close();
		}

	} while(input != 8);


	return 0;
}