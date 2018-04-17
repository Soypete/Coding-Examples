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

int main(){
	int user_input;
	//int user_input_int;
	//string path;

	double position_col;
	int position_row;
	int slot_number;
	double winnings = 0.0;
	srand(time(0));


	//loop that runs the program
	do{
		//print out the menu
		cout << "Menu: Please select one of the following\n\t1-Drop a single chips\n\t2-Drop multiple chips\n\t3-Quit the program\nEnter you selection here: ";
		cin >> user_input;
		winnings = 0.0;
		while (user_input != 1 && user_input != 2 && user_input != 3){
			cout << "Menu: Please select one of the following\n\t1-Drop a single chips\n\t2-Drop multiple chips\n\t3-Quit the program\nEnter you selection here: ";
			cin >> user_input;
		}
		//to run the program for a single slot
		if (user_input == 3){ cout << "GOODBYE"; }
		if (user_input == 1)
		{
			cout << "SINGLE\n";
			cout << "Please choose a slot between 0 and 8: ";
			cin >> slot_number;
			//verifies that is valid entry
			if (slot_number >= 0 && slot_number <= 8){
				position_col = slot_number; // changes it to the potl system


				cout << "your disks took the path :\n";

				cout << fixed << setprecision(1) << "[" << slot_number;


				//loop that controls the falling of the plinko disc
				for (position_row = 0; position_row < 12; position_row++)
				{
					int column_change = rand() % 2; //generates the movement of the disk randomly
					//limits the left boundry
					if (position_col == 0.0){
						position_col = 0.5;
					}
					//limits the right boundary
					else if (position_col == 8.0){
						position_col = 7.5;
					}
					//runs the fallings simulation 
					else{
						if (column_change == 1.0){ //sets zero as leftward movement
							position_col = position_col + 0.5;
						}
						else { //sets one as rightward movement
							position_col = position_col - 0.5;
						}
					}
					//fake array storing the path if the plinko disc
					
					cout << fixed << setprecision(1) << " " << position_col;
				}

				cout << "]"<< endl;

				if (position_col == 0 || position_col == 8){
					winnings = winnings + 100;

				}
				else if (position_col == 1 || position_col == 7){
					winnings = winnings + 500;

				}
				else if (position_col == 2 || position_col == 6){
					winnings = winnings + 1000;

				}
				else if (position_col == 4){
					winnings = winnings + 10000;

				}
				cout << fixed << setprecision(2) << "Winnings: $" << winnings << endl;
				//reset the game values
				//	path = "";
				//position = "";

			}
		}

		//begins calculating for multiple discs
		else if (user_input == 2){

			cout << "MULTIPLE\n";
			int number_of_chips;
			//choose number of chips
			cout << "How many chips would you like to use? (a number greater than 0): ";
			cin >> number_of_chips;
			if (number_of_chips > 0){
				//choose number of slots
				cout << "Please choose a slot between 0 and 8: ";
				cin >> slot_number;

				//verifies slot input
				if (slot_number >= 0 && slot_number <= 8){
					position_col = slot_number; // changes it to the potl system

					setprecision(1);
					//position = to_string(position_col);//initialize the initial position
					//path = path + position.substr(0, 3) + " ";//store the initila position in the makeshift array


					for (int i = 0; i < number_of_chips; i++)
					{
						//loop that controls the falling of the plinko disc
						for (position_row = 0; position_row < 12; position_row++)
						{
							int column_change = rand() % 2; //generates the movement of the disk randomly
							//limits the left boundry
							if (position_col == 0.0){
								position_col = 0.5;
							}
							//limits the right boundary
							else if (position_col == 8.0){
								position_col = 7.5;
							}
							//runs the fallings simulation 
							else
							{
								if (column_change == 1.0){ //sets zero as leftward movement
									position_col = position_col + 0.5;
								}
								else { //sets one as rightward movement
									position_col = position_col - 0.5;
								}

							}


						}


						if (position_col == 0 || position_col == 8){
							winnings = winnings + 100;

						}
						else if (position_col == 1 || position_col == 7){
							winnings = winnings + 500;

						}
						else if (position_col == 2 || position_col == 6){
							winnings = winnings + 1000;

						}
						else if (position_col == 4){
							winnings = winnings + 10000;

						}

						//reset the game values
						//path = "";
						//position = "";

					}
				}
				cout << fixed << setprecision(2) << "Winnings for " << number_of_chips << " of ships is: $" << winnings << endl;
				cout << fixed << setprecision(2) << "that is on average $" << winnings / number_of_chips << " per chip.\n";
			}
			else {
				cout << " Your input was invalid. it needed to be greater that 0.";
			}
		}

	} while (user_input != 3);
	//system("pause");
	return 0;
}
