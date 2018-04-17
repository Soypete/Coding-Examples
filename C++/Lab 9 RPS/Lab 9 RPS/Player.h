#pragma once
#include <vector>
using namespace std;

#include "Player.h"

class Player{
public:
	Player();
	Player(string name);
	//functions
	int getRPSThrow();
	double getWinRecord();
	string toString();
	string getName();
	void addWin();
	void addLoss();
	void addDraw();

private:
	//variables
	double numberOfWins;
	double numberOfLoses;
	double numberOfDraws;
	double numberOfMatches;
	string player_name;
};

