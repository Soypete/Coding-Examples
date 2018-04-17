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

bool isValidOption_SmStraight(int die1, int die2, int die3, int die4, int die5)
{
	bool truth = false;
	//array to hold the die vlaues for a better comparision
	int die_value_array[] = { die1, die2, die3, die4, die5 };
	for (int i = 0; i < 5; i++){
		if (1 == die_value_array[i]){

			for (int k = 0; k < 5; k++){									//looks for 2nd value of small straight
				if (die_value_array[k] == 2){
					for (int j = 0; j < 5; j++){							//looks for 3rd value of small straight
						if (die_value_array[j] == 3){
							for (int l = 0; l < 5; l++){					//looks for the last valuue of a smal straight
								if (die_value_array[l] == 4){
									truth = true;
								}

							}

						}


					}
				}
			}
		}
		else if (die_value_array[i] == 2){
			for (int k = 0; k < 5; k++){									//looks for 2nd value of combination								
				if (die_value_array[k] == 3){
					for (int j = 0; j < 5; j++){							//third value of the combination		
						if (die_value_array[j] == 4){
							for (int l = 0; l < 5; l++){					//4th vlaue of the combination
								if (die_value_array[l] == 5){
									truth = true;
								}

							}

						}
					}
				}
			}
		}
		else if (die_value_array[i] == 3){
			for (int k = 0; k < 5; k++){								//looks for 2nd value of last combination
				if (die_value_array[k] == 4){
					for (int j = 0; j < 5; j++){						//third value
						if (die_value_array[j] == 5){
							for (int l = 0; l < 5; l++){				//4th value
								if (die_value_array[l] == 6){
									truth = true;
								}
							}

						}
					}
				}

			}
			//returns false is not combination possible
		}
		
	}
	return truth;
}

bool isValidOption_3OfAKind(int die1, int die2, int die3, int die4, int die5)
{
	int die_values_array[] {die1, die2, die3, die4, die5};
	bool truth = false;

	for (int i = 0; i < 5; i++){												//looks through everyvalue of the array
		
		if (die_values_array[i] == 1){
			die_values_array[i] = 8;												//change to value to a non comparable so that it will not get compared to itself
			for (int k = 0; k < 5; k++){												//looks through everyvalue of the array
				if (die_values_array[k] == 1){
					die_values_array[k] = 8;
					for (int j = 0; j < 5; j++){												//looks through everyvalue of the array
						if (die_values_array[j] == 1){
							die_values_array[j] = 8;												//change to value to a non comparable so that it will not get compared to itself
							truth = true;
						}

					}
				}

			}
		}
		else if (die_values_array[i] == 2){
			die_values_array[i] = 8;												//change to value to a non comparable so that it will not get compared to itself
			for (int k = 0; k < 5; k++){												//looks through everyvalue of the array
				if (die_values_array[k] == 2){
					die_values_array[k] = 8;
					for (int j = 0; j < 5; j++){												//looks through everyvalue of the array
						if (die_values_array[j] == 2){
							die_values_array[j] = 8;												//change to value to a non comparable so that it will not get compared to itself
							truth = true;
						}

					}
				}

			}

		}
		else if (die_values_array[i] == 3){
			die_values_array[i] = 8;												//change to value to a non comparable so that it will not get compared to itself
			for (int k = 0; k < 5; k++){												//looks through everyvalue of the array
				if (die_values_array[k] == 3){
					die_values_array[k] = 8;
					for (int j = 0; j < 5; j++){												//looks through everyvalue of the array
						if (die_values_array[j] == 3){
							die_values_array[j] = 8;												//change to value to a non comparable so that it will not get compared to itself
							truth =  true;
						}

					}
				}

			}

		}
		else if (die_values_array[i] == 4){
			die_values_array[i] = 8;												//change to value to a non comparable so that it will not get compared to itself
			for (int k = 0; k < 5; k++){												//looks through everyvalue of the array
				if (die_values_array[k] == 4){
					die_values_array[k] = 8;
					for (int j = 0; j < 5; j++){												//looks through everyvalue of the array
						if (die_values_array[j] == 4){
							die_values_array[j] = 8;												//change to value to a non comparable so that it will not get compared to itself
							truth = true;
						}

					}
				}
			}
		}
		else if (die_values_array[i] == 5){
			die_values_array[i] = 8;												//change to value to a non comparable so that it will not get compared to itself
			for (int k = 0; k < 5; k++){												//looks through everyvalue of the array
				if (die_values_array[k] == 5){
					die_values_array[k] = 8;
					for (int j = 0; j < 5; j++){												//looks through everyvalue of the array
						if (die_values_array[j] == 5){
							die_values_array[j] = 8;												//change to value to a non comparable so that it will not get compared to itself
							truth = true;
						}
					}
				}

			}
		}
		else if (die_values_array[i] == 6){
			die_values_array[i] = 8;												//change to value to a non comparable so that it will not get compared to itself
			for (int k = 0; k < 5; k++){												//looks through everyvalue of the array
				if (die_values_array[k] == 6){
					die_values_array[k] = 8;
					for (int j = 0; j < 5; j++){												//looks through everyvalue of the array
						if (die_values_array[j] == 6){
							die_values_array[j] = 8;
							truth = true;					//change to value to a non comparable so that it will not get compared to itself
						}

					}
				}

			}
		}
		
	}
	return truth;
}

int main(){
	/*bool truth = isValidOption_YAHTZEE(2,2,3,3,3);
	if (truth == true){
	cout << "true";
	}
	else {
	cout << "false";
	}
*/
	/*bool truth = isValidOption_SmStraight(3,3,3,3,3);
	if (truth == true){
	cout << "true";
	}
	else {
	cout << "false";
	}*/

	bool truth = isValidOption_3OfAKind(6,5,5,6,6);
	if (truth == true){
		cout << "true";
	}
	else {
		cout << "false";		

	}
	system("pause");
	return 0;
}
