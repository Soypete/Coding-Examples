#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <math.h>


using namespace std;


/*
Testcases

Case 1				 Case 2				Case3
option 1 printout	option1 print		option 2 X8
option 4			option 2 add		option 4 shuffle
option 1 print to	option 2 add		option 3 remove not on list and erroe thrown
confirm shuffle		option 5 recieve	option 3 remove on list
Option 5 run		an error			option 2 remove on list and recieve error
tournament and		option 3 remove		option 5 to receive error
close				option 3 remove		option 6 close
					option 5 run and 
					close

all of the test cases showed positive results

*/					


//funtion that prints out the menu
int printMenu(){
	int userInput = 0;

	//menu
	cout << "\n1 - Display all restaurants\n";
	cout << "2 - Add a restaurant\n";
	cout << "3 - Remove a restaurant\n";
	cout << "4 - Shuffle the vector\n";
	cout << "5 - Begin the tournament\n";
	cout << "6 - Quit the program\n";
	cout << "Select one of the the above options options: ";

	//the users choice
	cin >> userInput;

	if (cin.fail()){
		cin.clear();
		cin.ignore();
	}
	return userInput;

}

//prints out the current restaurants of the string
void printRestaurantes(vector<string> restaurantes){
	cout << restaurantes[0];
	for (int i = 1; i < restaurantes.size(); i++){
		cout << "," << restaurantes[i];
	}
	cout << endl;
}
int findRestaurante(vector<string> restaurantes, string nombreDelRestaurante){
	for (int i = 0; i< restaurantes.size(); i++){
		if (nombreDelRestaurante == restaurantes[i]){
			return i;
		}
	}
	return -1;
}


//add a restaurant
void addRestaurante(vector<string>& restaurantes){
	string name;
	int alreadyExists;
	cout << "Enter the restaurant's name: ";
	cin.sync();
	getline(cin, name);
	alreadyExists = findRestaurante(restaurantes, name);
	if (alreadyExists != -1){
		cout << name << " is already on your list.\n";
	}
	else {
		restaurantes.push_back(name);
		cout << name << " a added to your restaurant list.\n";
	}
}

//remove the restaurant
void removeElRestaurante(vector<string>&restaurantes){
	string name;
	int alreadyExists;
	cout << "Enter the restaurant's name: ";
	cin.sync();
	getline(cin, name);
	alreadyExists = findRestaurante(restaurantes, name);
	if (alreadyExists != -1){
		restaurantes.erase(restaurantes.begin() + alreadyExists);
		cout << name << " was removed from the list\n";
	}
	else {
		cout << name << " was not on the list \n";
	}
}

//shuffle the order
void shuffleLosRestaurantes(vector<string>&restaurantes){
	srand(time(0));
	for (int i = 0; i < 100; i++){
		int positionDelRestaurante = rand() % 6;
		restaurantes.push_back(restaurantes[positionDelRestaurante]);
		restaurantes.erase(restaurantes.begin() + positionDelRestaurante);
	}
	cout << "Your restaurants have been shuffled.\n";
}

string runTorneo(vector<string>& restaurantes, int size, double power){
	
	int powerOfTwo = power;
	vector<string> winners;

	//runs through the rounds
	for (int i = 0; i < power; i++){
		int vectorSize = restaurantes.size();
		for (int k = 0; k < vectorSize / 2;  k++ ){
			//two competators
			int restOne = k * 2;
			int restTwo = k * 2 + 1;
			int input;
			bool incorrectValue;

			do {
				cout << "Match " << k +1 << "/" << vectorSize/2 << " --- Round " << i +1 << "/" << power << " enter 1 if you prefer " << restaurantes[restOne] << " or 2  for " << restaurantes[restTwo] << ": ";
				cin >> input;

				if (cin.fail()){
					cin.clear();
					cin.ignore();
					incorrectValue = true;
					cout << "Invalid Response " << input << endl;
				}
				else if (input == 1){
					winners.push_back(restaurantes[restOne]);
					incorrectValue = false;
				}
				else if (input == 2){
					winners.push_back(restaurantes[restTwo]);
					incorrectValue = false;

				}
				else{
					incorrectValue = true;
					cout << "Invalid Response " << input << endl;
				}
			} while (incorrectValue);
		}
		//change vector removing the loser
		restaurantes.erase(restaurantes.begin(), restaurantes.begin()+restaurantes.size());
		for (int m = 0; m < winners.size(); m++){
			restaurantes.push_back(winners[m]);
		}
		winners.erase(winners.begin(), winners.begin() + winners.size());
	}
	string winner = restaurantes[0];
	return winner;
}

int tournamentDeLosRestaurantes(vector<string>&restaurantes){
	//verify that the size is a power of 2
	int vectorSize;
	int powerOfTwo;
	int runTournament = 2;
	string winner;
	int ValueToReturn = 2;
	
	for (double i = 0.0; i < 20.0; i++){
		double size = restaurantes.size();
		if (pow(2.0, i) == size){
			vectorSize = restaurantes.size();
			powerOfTwo = i;
			runTournament = 1;	//value that tells the computer to run (I would have used a bool but it would not initialize
			ValueToReturn = 1;	//return values that closes the program
		}
		
	}
	//run tornament if power of two
	if (runTournament == 1){
		winner = runTorneo(restaurantes, vectorSize, powerOfTwo);
		cout << winner << " won!!\n";	
	}
	else {
		//runTournament = 2;
		cout << "incorrect number of restaurants. It has to be a power of 2 and less than 2^20 (that is just too many options).\n";
		//ValueToReturn = 2;
	}
	return ValueToReturn;

}


int main(){
	//user input to proceed
	int menuOption;
	

	//vector and 8 initial resaurants
	vector<string> restaurantes;
	restaurantes.push_back("McDonalds");
	restaurantes.push_back("Firehouse Subs");
	restaurantes.push_back("Red Robbin");
	restaurantes.push_back("Cafe Zuppas");
	restaurantes.push_back("Brick Oven Pizza");
	restaurantes.push_back("Cafe Rio");
	restaurantes.push_back("Outback Steakhouse");
	restaurantes.push_back("Olive Garden");

	do{
		menuOption = printMenu();
		if(menuOption == 1){
			if (restaurantes.size() != 0){
				printRestaurantes(restaurantes);
			}
		}
		else if (menuOption == 2){
			addRestaurante(restaurantes);
		}
		else if (menuOption == 3){
			removeElRestaurante(restaurantes);
		}
		else if (menuOption == 4){
			shuffleLosRestaurantes(restaurantes);
		}
		else if (menuOption == 5){
			int playedElJuego = tournamentDeLosRestaurantes(restaurantes); 
			if (playedElJuego == 1){
				menuOption = 6;
			}
			else {
				menuOption = menuOption;
			}
			
		}

	} while (menuOption != 6);

	system("pause");
	return 0;
}