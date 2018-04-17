#include <iostream>
using namespace std;

int main(){
	const int COW = 10;		//set number of cows
	const int CARROTSCOWSEAT = 15;		//set number of carrots that the cos eat	
	int carrotsdelivered; //value recieve by user
	

	cout << "How many carrots were delivered?" <<endl;	//question to promted to use
	cin >> carrotsdelivered;	//reads the input and set is as the vaule of the carrotdeliviered
	int leftovercarrot = carrotsdelivered - (COW*CARROTSCOWSEAT);		//set number of carrots that the cos eat
	cout << "You have " << leftovercarrot << " carrots leftover" << endl;
	
	
	system("PAUSE");
	
	
	return(0);

}
