 
#pragma once
#include <string>
#include "Fighter.h"
class FighterGame {
public:
	FighterGame(int NOF);
	~FighterGame();
private:
	Fighter** fighterList;
	int numFighters;
	int originalNumFighters;
public:
	Fighter* getFighterByName(std::string name);
	bool killFighter(Fighter* fighter);
	int getNumberOfFighters() { return numFighters; }
	void round();
};