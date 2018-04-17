#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Test cases
//					Case 1		Case2		Case3
//Miles per year =	50000		75000		25000
//price of gas =	$2.50		$3.00		$1.57
//cost of HYcar =	30000		45000		45995
//gas eff of HY =	45mpg		45mpg		50mpg
//resellval =		20000		30000		37927
//regcar cost =		15000		30000		10000
//gas eff. =		28			30			15
//resell val =		7000		15000		3000
//HY gal. used =	5555		8333.33		2500
//HY cost to own =	23889		40000		12443
//REg gal used =	8929		12500		8333.33
//reg cost to own = 30221		52500		21583

//MPG 104

int main(){
	double milesDrivenPerYear;
	double avgGasPrice;
	double CostOfHBCar;
	double GasEfficiencyOfHB;
	double ResaleValueHB;
	double CostOfRegCar;
	double gasEffOfRegCar;
	double resaleValueReg;
	string ratingPreff;
	//string carType;
	double totalGasConsumedHB;
	double totalGasConsumedReg;
	double costOfOwnerShipHB;
	double costOfOwnerShipReg;


	//part 1 recieving information 
	cout << "How many miles do you drive every year? " ;
	cin >> milesDrivenPerYear;
	if (milesDrivenPerYear <= 0){								//if statements to check or compatible numbers
		cout << "Enter a number greater than Zero please: " ;
		cin >> milesDrivenPerYear;
	}
	cout << "What do you think will be the average price of a gallon of gas for the next 5 years? ";
	cin >> avgGasPrice;
	if (avgGasPrice <= 0){
		cout << "Enter a number larger than 0 please:  ";
		cin >> avgGasPrice;
	}
	cout << "What is the cost of the hybrid car you are looking at? ";
	cin >> CostOfHBCar;
	if (CostOfHBCar <= 0){
		cout << "Enter a number larger than 0 please:  ";
		cin >> CostOfHBCar;
	}

	cout << "How many  miles per gallon does it get? ";
	cin >> GasEfficiencyOfHB;
	if (GasEfficiencyOfHB <= 0){
		cout << "Enter a number larger than 0 please:  ";
		cin >> GasEfficiencyOfHB;
	}

	cout << "What do you think the resale value will be in 5 years? ";
	cin >> ResaleValueHB;
	if (ResaleValueHB <= 0){
		cout << "Enter a number larger than 0 please:  ";
		cin >> ResaleValueHB;
	}

	cout << "What is the price of the non-hybrid car?" ;
	cin >> CostOfRegCar;
	if (CostOfRegCar <= 0){
		cout << "Enter a number larger than 0 please:  ";
		cin >> CostOfRegCar;
	}
	
	cout << "How many miles per gallon does that car get? ";
	cin >> gasEffOfRegCar;
	if (gasEffOfRegCar <= 0){
		cout << "Enter a number larger than 0 please:  ";
		cin >> gasEffOfRegCar;
	}
	cout << "What do you think the resale value will be in 5 years? ";
	cin >> resaleValueReg;
	if (resaleValueReg <= 0){
		cout << "Enter a number larger than 0 please:  ";
		cin >> resaleValueReg;
	}

	cout << "would you prefer to compair the the total cost of owning the car or the number of gallons of gas used? (type Total or Gas) ";
	cin >> ratingPreff;
	//part 2 

	//calculating the resulting variables

	double depreciationHB = CostOfHBCar - ResaleValueHB;
	double depreciatonReg = CostOfRegCar - resaleValueReg;

	totalGasConsumedHB = milesDrivenPerYear*5 / GasEfficiencyOfHB;
	totalGasConsumedReg = milesDrivenPerYear*5 / gasEffOfRegCar;

	costOfOwnerShipHB = totalGasConsumedHB*avgGasPrice + depreciationHB;

	costOfOwnerShipReg = totalGasConsumedReg*avgGasPrice + depreciatonReg;


	//printing out the results
	if (ratingPreff != "Gas" && ratingPreff != "Total"){
		cout << " I'm sorry do not understand your response enter either \"Total\" or \"Gas\" (check your spelling)";
		cin >> ratingPreff;
	}

	if (ratingPreff == "Total"){
		if (costOfOwnerShipHB < costOfOwnerShipReg){
			cout << "The hybrid car will cost $" << costOfOwnerShipHB << " over the next 5 years.\n";
			cout << "The hybrid car will use " << totalGasConsumedHB << " gallons of gas in 5 years\n";
			cout << "The non-hybrid car will cost $" << costOfOwnerShipReg << " over the next 5 years.\n";
			
			cout << "the non-hybrid car will use" << totalGasConsumedReg << " gallons of gas in 5 years\n";
		}
		else{
			cout << "The non-hybrid car will cost $" << costOfOwnerShipReg << " over the next 5 years.\n";
			cout << "the non-hybrid car will use " << totalGasConsumedReg << " gallons of gas in 5 years\n";
			cout << "The hybrid car will cost $" << costOfOwnerShipHB << " over the next 5 years.\n";
			
			cout << "The hybrid car will use " << totalGasConsumedHB << " gallons of gas in 5 years\n";
		}
		system("pause");
		return 0;

	}
	else if (ratingPreff == "Gas"){
		if (totalGasConsumedHB < totalGasConsumedReg){
			cout << "The hybrid car will use " << totalGasConsumedHB << " gallons of gas in 5 years\n";
			cout << "The hybrid car will cost $" << costOfOwnerShipHB << " over the next 5 years.\n";
			cout << "the non-hybrid car will use " << totalGasConsumedReg << " gallons of gas in 5 years\n";
			
			cout << "The non-hybrid car will cost $" << costOfOwnerShipReg << " over the next 5 years.\n";
		}
		else{
			cout << "the non-hybrid car will use " << totalGasConsumedReg << " gallons of gas in 5 years\n";
			cout << "The non-hybrid car will cost $" << costOfOwnerShipReg << " over the next 5 years.\n";
			cout << "The hybrid car will use " << totalGasConsumedHB << " gallons of gas in 5 years\n";
			
			cout << "The hybrid car will cost $" << costOfOwnerShipHB << " over the next 5 years.\n";
		}

		system("pause");
		return 0;

	} else{
		cout << "I'm sorry but that word you typed is not compatible. you have to start over know";
		system("pause");
		return 0;
	}
}