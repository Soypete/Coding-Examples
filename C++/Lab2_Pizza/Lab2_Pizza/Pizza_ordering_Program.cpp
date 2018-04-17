#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

//examples scenarios
//ppl: 27  tip: 15   Lrg : 3  med:2 sm:0 Tarea:1344.60 area/per:49.8  cost $77
//ppl: 92  tip: 18.5 Lrg : 13 med:0 sm:1 Tarea:4197.17 area/per:45.62 cost $235
//ppl: 186 tip: 7    Lrg : 26 med:1 sm:1 Tarea:8482.29 area/per:45.6 cost $428

int main()
{
	//part1
	//intializing variable for this part
	int numberOfGuests;
	int numberOfLargePizzas;
	int numberOfMedPizzas;
	int numberOfSmallPizzas;
	int numberOfTotalPizzas;
	string name = "Friend";						//users name	
	//ask user for the number of guests
	cout << "Hi, I am your Fred the Pizza Machine.\nLet's figure out how much pizza you need tonight!\n ";
	
	cout << "How many guests are you expecting tonight? : " ;
	cin >> numberOfGuests;

	//caculate the number of pizzas to buy
	numberOfLargePizzas = numberOfGuests / 7;
	numberOfMedPizzas = (numberOfGuests % 7) / 3;
	numberOfSmallPizzas = (numberOfGuests % 7) % 3;
	numberOfTotalPizzas = numberOfLargePizzas + numberOfMedPizzas + numberOfSmallPizzas;


	//print out result

	cout << "The number of large pizzas you need ot order : " << numberOfLargePizzas << endl;
	cout << "The number of medium pizzas you need to order : " << numberOfMedPizzas << endl;
	cout << "The number of small pizzas you need to order : " << numberOfSmallPizzas << endl;
	cout << "That's gonna be " << numberOfTotalPizzas <<" pizzas total you need to order\n" << endl;
	 

	//Part 2
	//values needed
	const double RADLARGE = 10;
	const double RADMED = 8;
	const double RADSMALL =  6;
	const double PI = 3.14159;

	//solve for pizza areas
	double areaLarge = PI*(pow(RADLARGE, 2.0));
	double areaMed = PI*(pow(RADMED, 2.0));
	double areaSmall = PI*(pow(RADSMALL, 2.0));

	//solve for total area which is area of individual pizza x number of pizzas we are ordering
	double totalArea = areaLarge*numberOfLargePizzas + areaMed*numberOfMedPizzas + areaSmall*numberOfSmallPizzas;

	//solve for area per guest
	double areaPerGuest = totalArea / numberOfGuests;
	//playful banter
	cout <<  name << ", you are ordering " << totalArea << " square inches of pizza.\nThat is "
		<< areaPerGuest << " square inches person.\nThat should be plenty of pizza!.\n";
	
	//part3
	//initializing the variables for this part
	const double LARGEPIZZAPRICE = 14.68;
	const double MEDPIZZAPRICE = 11.48;
	const double SMALLPIZZAPRICE = 7.28;
	double tip;
	double totalPizzaCost;
	double totalBill;

	//calcutate the price of buying just pizza
	totalPizzaCost = LARGEPIZZAPRICE*numberOfLargePizzas + MEDPIZZAPRICE*numberOfMedPizzas + SMALLPIZZAPRICE*numberOfSmallPizzas;
	//ask customer how much her wants to tip
	cout << "How much to you plan on tipping the delivery man " << name << "? (enter percent) ";
	cin >> tip;
	//calculate the total bill price
	totalBill = totalPizzaCost + totalPizzaCost*(tip / 100);
	cout << fixed <<setprecision(0) <<								//setprecision(0) should round to the nearest dollar
	name << ", your total for the pizza and tip going to be $" << totalBill << endl; 
	system("pause");
	return 0;


}