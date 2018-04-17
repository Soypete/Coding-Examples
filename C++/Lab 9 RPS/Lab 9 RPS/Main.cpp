#include <iostream>
#include <string>
#include "Player.h"
#include <time.h>
#include <cstdlib>

using namespace std;


/*			Test cases
1.Create lineup wil smae player repeated 3 times			1. Run fight wiht 1player in lineup(print error)			1: Add player 1
2.add thre more players to lineup							2. Run Fight with 2 in lineup								2: add player 1 again (rejected)
3.Run 3 fights												3. Print out the line up(check stats)						3. add to more players
4.verify the random outputs									4. run fight again to see if removed						4. add a player tha tdoesn't exist to the line-up (rejected
5. print out win record.																								5. add two players to the lineup
																														6. print out all players
																														7. print out lineup


*/



//looks to see if player exists
int findPlayer(vector<Player*> players_vector, string NewPlayer){
	int toReturn = -1;													//default if player doesn't exist
	for (int i = 0; i < players_vector.size(); i++){
		if (NewPlayer == players_vector[i]->getName()){
			toReturn = i;
		}
	}
	return toReturn;
}

//prints out all player information
void showPlayers(vector<Player*> all_players){
	for (int i = 0; i < all_players.size(); i++){
		cout << all_players[i]->toString();
	}
}
//adds player to the player list
void addPlayer(vector<Player*>& players_vector){
	//variable needed to add player
	string NewPlayer;
	int exists;
	cout << "Enter the name of the player: ";
	cin.sync();
	getline(cin, NewPlayer);
	exists = findPlayer(players_vector, NewPlayer);										//use findPlayer to see if exists
	if (exists != -1){
		cout << "Sorry that player already exists.\n";
	}
	else{
		Player* player = new Player(NewPlayer);										//adds player
		players_vector.push_back(player);
		cout << NewPlayer << " was added to your list.\n";
	}
}
//adds existing player to the lineup
void addToLineUp(vector<Player*>all_players, vector<Player*>& line_up){
	//variables needed to add player
	string newPlayer;
	int exists;																	
	cout << "which one of you players would you like to you lineup?  ";
	cin.sync();
	getline(cin, newPlayer);
	exists = findPlayer(all_players, newPlayer);										//verifies that he player exists
	if (exists == -1){
		cout << "that player was not on your list, you will need to add them.\n";
	}
	else{
		line_up.push_back(all_players[exists]);								//add to lineup
		cout << newPlayer << " was added to your lineup.\n";
	}
}

//run the RPS war
void fight(vector<Player*>& lineUp, vector<Player*>& all_players){

	//1 = rock
	//2 = paper 
	//3 = scissors
	if (lineUp.size() >= 2){										//check to see if there are enough for a match
			
		cout << "lets go between " << lineUp[0]->getName() << " and " << lineUp[1]->getName() << endl;
		int rollPlayerOne = lineUp[0]->getRPSThrow();				//get roll
		int rollPlayerTwo = lineUp[1]->getRPSThrow();
		if (rollPlayerOne == 1 && rollPlayerTwo == 2){				//compare roll
			cout << lineUp[1]->getName() << " threw paper.\n";
			cout << lineUp[0]->getName() << " threw rock. \n";
			cout << lineUp[1]->getName() << " Wins!!\n";
			//to findPlayer the location of the player in the vector
			int player1 = findPlayer(all_players, lineUp[0]->getName());
			int player2 = findPlayer(all_players, lineUp[1]->getName());
			//changes win total
			all_players[player1]->addLoss();
			all_players[player2]->addWin();
			//removes from the lineup
			lineUp.erase(lineUp.begin());
			lineUp.erase(lineUp.begin());
		}

		//the coding style repeats until the last option
		else if (rollPlayerOne == 1 && rollPlayerTwo == 3){
			cout << lineUp[0]->getName() << " threw rock.\n";
			cout << lineUp[1]->getName() << " threw scissors. \n";
			cout << lineUp[0]->getName() << " Wins!!\n";
			int player1 = findPlayer(all_players, lineUp[0]->getName());
			int player2 = findPlayer(all_players, lineUp[1]->getName());
			all_players[player2]->addLoss();
			all_players[player1]->addWin();
			lineUp.erase(lineUp.begin());
			lineUp.erase(lineUp.begin());
		}
		else if (rollPlayerOne == 2 && rollPlayerTwo == 1){
			cout << lineUp[1]->getName() << " threw rock.\n";
			cout << lineUp[0]->getName() << " threw scissors. \n";
			cout << lineUp[1]->getName() << " Wins!!\n";
			int player1 = findPlayer(all_players, lineUp[0]->getName());
			int player2 = findPlayer(all_players, lineUp[1]->getName());
			all_players[player1]->addLoss();
			all_players[player2]->addWin();
			lineUp.erase(lineUp.begin());
			lineUp.erase(lineUp.begin());
		}
		else if (rollPlayerOne == 2 && rollPlayerTwo == 3){
			cout << lineUp[0]->getName() << " threw scissors.\n";
			cout << lineUp[1]->getName() << " threw paper. \n";
			cout << lineUp[0]->getName() << " Wins!!\n";
			int player1 = findPlayer(all_players, lineUp[0]->getName());
			int player2 = findPlayer(all_players, lineUp[1]->getName());
			all_players[player2]->addLoss();
			all_players[player1]->addWin();
			lineUp.erase(lineUp.begin());
			lineUp.erase(lineUp.begin());
		}
		else if (rollPlayerOne == 3 && rollPlayerTwo == 1){
			cout << lineUp[0]->getName() << " threw paper.\n";
			cout << lineUp[1]->getName() << " threw rock. \n";
			cout << lineUp[0]->getName() << " Wins!!\n";
			int player1 = findPlayer(all_players, lineUp[0]->getName());
			int player2 = findPlayer(all_players, lineUp[1]->getName());
			all_players[player2]->addLoss();
			all_players[player1]->addWin();
			lineUp.erase(lineUp.begin());
			lineUp.erase(lineUp.begin());
		}
		else if (rollPlayerOne == 3 && rollPlayerTwo == 2){
			cout << lineUp[1]->getName() << " threw scissor.\n";
			cout << lineUp[0]->getName() << " threw paper. \n";
			cout << lineUp[1]->getName() << " Wins!!\n";
			int player1 = findPlayer(all_players, lineUp[0]->getName());
			int player2 = findPlayer(all_players, lineUp[1]->getName());
			all_players[player1]->addLoss();
			all_players[player2]->addWin();
			lineUp.erase(lineUp.begin());
			lineUp.erase(lineUp.begin());
		}//if it is a draw
		else if (rollPlayerOne == rollPlayerTwo){
			cout << "it is a draw!!\n";
			//fins player location
			int player1 = findPlayer(all_players, lineUp[0]->getName());
			int player2 = findPlayer(all_players, lineUp[1]->getName());
			//add draw
			all_players[player1]->addDraw();
			all_players[player2]->addDraw();
			//erase form lineup
			lineUp.erase(lineUp.begin());
			lineUp.erase(lineUp.begin());
		}
	}
	else{
		cout << "Your vector is too small.\n";
	}
}
////prtints out menu and recieves input
int printMenu(){
	cout << "Choose one of the following options: (enter the number) \n";
	cout << "1. Show all Players\n2. Add a Player\n3. Add to line-up\n4. Show line-up\n5. Fight\n6.Quit\n";
	int input;
	cin >> input;
	if (cin.fail()){
		cin.clear();
		cin.ignore(1000, '\n');
		input = 0;
	}
	return input;
}


int main(){
	srand(time(0));
	//Player* player;
	vector<Player*> all_players;
	vector<Player*> line_up;
	int input;
	//prompt the user for options
	do{
		input = printMenu();
		if (input == 1){
			cout << "Your players:\n";
			showPlayers(all_players);
		}
		else if (input == 2){
			addPlayer(all_players);
		}
		else if (input == 3){
			addToLineUp(all_players, line_up);
		}
		else if (input == 4){
			cout << "your lineup:\n";
			showPlayers(line_up);
		}
		else if (input == 5){
			fight(line_up, all_players);
		}
		
	} while (input != 6);

	return 0;
}