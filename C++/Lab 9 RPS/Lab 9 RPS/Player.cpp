#include "Player.h"
#include <iostream>
#include <sstream>



using namespace std;

//default values
const double DEFAULTWIN = 0.0;
const double DEFAULTDRAW = 0.0;
const double DEFAULTLOSS = 0.0;
const double DEFAULTMATCHES = 0.0;


Player::Player(){
	numberOfWins = DEFAULTWIN;
	numberOfDraws = DEFAULTDRAW;
	numberOfLoses = DEFAULTLOSS;
	numberOfMatches = DEFAULTMATCHES;
	//srand(time(0));
}
//constructor
Player::Player(string name){
	player_name = name;
	numberOfWins = DEFAULTWIN;
	numberOfDraws = DEFAULTDRAW;
	numberOfLoses = DEFAULTLOSS;
	numberOfMatches = DEFAULTMATCHES;
	
}

//gets all information ready to print
string Player::toString(){
	stringstream toPrint;
	toPrint << "Name: " << player_name << endl;
	toPrint << "Number of Wins: " << numberOfWins << endl;
	toPrint << "Number of Draws: " << numberOfDraws << endl;
	toPrint << "Number of Losses: " << numberOfLoses << endl;
	toPrint << "Win record is: " << getWinRecord() << "%" << endl << endl;
	return toPrint.str();
}
//returns the player name
string Player::getName(){
	return player_name;
}
//calculates and gives record
double Player::getWinRecord(){
	double record;
	if (numberOfMatches != 0){
		record = (numberOfWins / numberOfMatches)*100;
	}
	else{ record = 0.0; }
	return record;
}
//randomly find roll
int Player::getRPSThrow(){
	
	int roll = rand() % 3 + 1;
	return roll;
}

//functions add win, add loss, and draw
void Player::addWin(){
	numberOfWins++;
	numberOfMatches++;
}
void Player::addLoss(){
	numberOfLoses++;
	numberOfMatches++;
}
void Player::addDraw(){
	numberOfDraws++;
	numberOfMatches++;
}
