#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

/* Test cases:
1- test with the first scenario, run it three times placing the disc in slot 5 to see if the winnings are different
the winings were $500 the first time, $0 the second time and $0 the third, btu the paths were distinct.
2-test entering negative number in menu and if the disc and slot options:
result: it returns to the menu every time
3- test fuction two to make sure that nultiple discs are being used:
after testing for 1000, 100, and 10 it appears that the values coincide with the function running multiple times.

*/

int position_row;

int coutMenu(){
	int user_input;
	cout << "Menu: Please select one of the following\n\t1-Drop a single chips\n\t2-Drop multiple chips into one slot\n\t3-Drop multiple schips into every slot.\n\t4-Quit the program\nEnter you selection here: ";
	cin >> user_input;

	while (user_input != 1 || user_input != 2 || user_input != 3 || user_input != 4){
		cout << "Menu: Please select one of the following\n\t1-Drop a single chips\n\t2-Drop multiple chips\n\t3-Drop multiple schips into every slot.\n\t4-Quit the program\nEnter you selection here: ";
		cin >> user_input;
	}

	return user_input;
}

int find_start_position(){
	int start_position;
	cout << "Please choose a slot between 0 and 8: ";
	cin >> start_position;
	return start_position;

}

double changePosition(double start_position){
	double end_position;
	int column_change = rand() % 2; //generates the movement of the disk randomly
	//limits the left boundry
	if (start_position == 0.0){
		start_position = 0.5;
	}
	//limits the right boundary
	else if (start_position == 8.0){
		start_position = 7.5;
	}
	//runs the fallings simulation 
	else{
		if (column_change == 1.0){ //sets zero as leftward movement
			start_position = start_position + 0.5;
		}
		else { //sets one as rightward movement
			start_position = start_position - 0.5;
		}
	}
	return end_position;
}

double calculate_winnings(int position){
	double winnings;
	if (position == 0 || position == 8){
		winnings = 100;

	}
	else if (position == 1 || position == 7){
		winnings = 500;

	}
	else if (position == 2 || position == 6){
		winnings = 1000;

	}
	else if (position == 4){
		winnings = 10000;

	}
	return winnings;

}

void dropOnePlinko(int position){

	//verifies that is valid entry
	if (position >= 0 && position <= 8){
		double position_col;
		cout << "your disks took the path :\n";

		cout << fixed << setprecision(1) << "[" << position;


		//loop that controls the falling of the plinko disc
		for (position_row = 0; position_row < 12; position_row++)
		{
			position_col = changePosition(position);
			cout << fixed << setprecision(1) << " " << position_col;
		}

		cout << "]" << endl;

		double winnings = calculate_winnings(position_col);

		cout << fixed << setprecision(2) << "Winnings: $" << winnings << endl;
	}
}

void dropMultipleDisks(int poistion, int numberOfDiscs){
	double winnings;
	if (numberOfDiscs > 0){

		//verifies slot input
		if (poistion >= 0 && poistion <= 8){
			double position_col; // changes it to the potl system

			setprecision(1);
			for (int i = 0; i < numberOfDiscs; i++)
			{
				//loop that controls the falling of the plinko disc
				for (position_row = 0; position_row < 12; position_row++)
				{
					position_col = changePosition(poistion);

				}
				winnings += calculate_winnings(position_col);
			}
		}
		cout << fixed << setprecision(2) << "Winnings for " << numberOfDiscs << " of ships is: $" << winnings << endl;
		cout << fixed << setprecision(2) << "that is on average $" << winnings / numberOfDiscs << " per chip.\n";
	}
	else {
		cout << " Your input was invalid. it needed to be greater that 0.";
	}
}

int main(){
	srand(time(0));
	int user_input;
	int slot_number;

	//loop that runs the program
	do{
		//print out the menu
		user_input = coutMenu();
		while (user_input != 1 && user_input != 2 && user_input != 3 && user_input != 4){
			user_input = coutMenu();
		}
		//to run the program for a single slot
		if (user_input == 3){ cout << "GOODBYE"; }
		if (user_input == 1)
		{
			cout << "SINGLE\n";
			slot_number = find_start_position();
			dropOnePlinko(slot_number);
		}

		//begins calculating for multiple discs
		else if (user_input == 2){

			cout << "MULTIPLE\n";
			int number_of_chips;
			//choose number of chips
			cout << "How many chips would you like to use? (a number greater than 0): ";
			cin >> number_of_chips;

			//choose number of slots
			slot_number = find_start_position();
			dropMultipleDisks(slot_number, number_of_chips);

		}
		else if (user_input == 3){
			cout << "MULTIPLE in ALL SLOTS\n";
			int number_of_chips;

//choose number of chips
			cout << "How many chips would you like to use? (a number greater than 0): ";
			cin >> number_of_chips;

			//choose number of slots
			slot_number = find_start_position();
			for (int slot = 0; slot < 9; slot++){
				dropMultipleDisks(slot_number, number_of_chips);
			}
		}

	} while (user_input != 4);
	//system("pause");
	return 0;
}
