#include <iostream>
#include <string>

using namespace std;

bool isValidOption_YAHTZEE(int die1, int die2, int die3, int die4, int die5)
{
	//check the equivalence of a yahtzee
	if (die1 == die2 && die1 == die3 && die1 == die4 && die1 == die5){
		return true;
	}
	else { return false; }
}

char getCharInRange(char min, char max)
{
	char output;
	int position_max;
	int position_min;
	int position_input;
	char input;
	char alphabetCaps[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char alphabetLowers[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

	//const string ALPHABETCAPS  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//const string ALPHABETLOWERS = "abcdefghijklmnopqrstuvwxyz";
	

	//gets the range values
	for (int i = 0; i < 26; i++){

		if (min == alphabetCaps[i]){
			position_min = i;
		}if (max == alphabetCaps[i]){
			position_max = i;
		}
	}
	//prompt the user for the imput
	cout << "please enter a letter: ";
	cin >> input;
	//sets the position in th earray so that it can be more easily compared
	for (int i = 0; i < 26; i++){

		if (input == alphabetCaps[i] || input == alphabetLowers[i]){
			position_input = i;
			
		}
	}
	//checks to see if the letter is within range and repprompts if it is not

	while (position_input < position_min || position_input > position_max){
		cout << "enter a value within the range: ";
		cin >> input;
		//reinitializes values
		for (int i = 0; i < 26; i++){
			if (input == alphabetCaps[i]){
				position_input = i;
			}
			else if (input == alphabetLowers[i]){
				position_input = i;
			}

		}//sets the return value
	}
	if (position_input >= position_min && position_input <= position_max){
		output = alphabetCaps[position_input];
	}

	return output;  // TO BE CHANGED
}

char getYN(string prompt)
{	//variable of the function
	char inputY_or_N;
	char output;
	//recieve user input
	cout << prompt;
	cin >> inputY_or_N;

	//verify the user input
	while (inputY_or_N != 'n' && inputY_or_N != 'N' && inputY_or_N != 'y' && inputY_or_N != 'Y'){
		cout << "Sorry that was an invalid entry, please enter 'N' or 'Y:'";
		cin >> inputY_or_N;
	}
	//set return value
	if (inputY_or_N == 'y' || inputY_or_N == 'Y'){
		output = 'Y';
	}
	else if (inputY_or_N == 'n' || inputY_or_N == 'N'){
		output = 'N';
	}

	return output;
}

bool isValidOption_YAHTZEE(int die1, int die2, int die3, int die4, int die5)
{
	//check the equivalence of a yahtzee
	if (die1 == die2 && die1 == die3 && die1 == die4 && die1 == die5){
		return true;
	}
	else { return false; }

}

int main(){

	//test valid yahtzee
	/*cout << "hi";

	bool truth = isValidOption_YAHTZEE(1, 2, 3, 4, 5 );
	if (truth == true){
		cout << "true";
	}
	else{
		cout << "false";
	}*/

	//test getYN

	/*char value = getYN("do you liek pie: (YorN): ");
	cout << value;*/


	/*char value = getCharInRange('J', 'S');
	cout << value;
	
	system ("pause");
	return 0;*/
	

	//test isValidOptionYahtzee
	bool truth = isValidOption_YAHTZEE (1,2,3,4,5);
	if (truth){
		cout << true;
	}
	else {
		cout << false;
	}system("pause");
	return 0; 

}