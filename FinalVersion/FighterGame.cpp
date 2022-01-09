#include"FighterGame.h"
#include<Windows.h>

FighterGame::FighterGame(int NOF) {
	fighterList = new Fighter * [NOF];
	for (int i = 0; i < NOF; i++)
		fighterList[i] = new Fighter();

	originalNumFighters = numFighters = NOF;

}

FighterGame::~FighterGame() {
	for (int k = 0; k < originalNumFighters; k++)
		if (fighterList[k])
			delete fighterList[k];
	delete fighterList;
}

bool FighterGame::killFighter(Fighter* fighter) {
	if (fighter) {
		for (int k = 0; k < numFighters; k++) {
			if (fighterList[k] == fighter) {
				delete fighter;
				numFighters--;
				if (numFighters != 1) {
					fighterList[k] = fighterList[numFighters];
					fighterList[numFighters] = 0;
				}
				else
					fighterList[k] = nullptr;

				return true;
			}
		}
		return false;

	}
	else
		return false;
}

void FighterGame::round() {
	for (int i = 0; i < numFighters; i++) {
		fighterList[i]->setDefence(fighterList[i]->getSpeed());
		std::cout << "\n\n\n\n\n###########################################\n\n\n\n\n";

		std::cout << "Now then " << fighterList[i]->getName() << ". It is the beginning of your turn. Your stats are as follows:" << std::endl
			<< "Power: " << fighterList[i]->getPower() << std::endl
			<< "Stamina: " << fighterList[i]->getStamina() << std::endl
			<< "Speed: " << fighterList[i]->getSpeed() << std::endl
			<< "Health: " << fighterList[i]->getHealth() << std::endl
			<< "What do you want to do? " << std::endl
			<< "Attack(a), defend yourself(d), shop(s) or rest(r)? \n" << std::endl;

		std::string action;
		bool incoInput = true;

		while (incoInput) {
			incoInput = false;

			std::cin >> action; 
			switch(action.c_str()[0]) {
			case'r':
			case'R':
				fighterList[i]->rest();
				Sleep(3000);
				break;

			case's':
			case'S':
				fighterList[i]->shop();
				break;

			case'd':
			case'D':
				fighterList[i]->defend();
				Sleep(3000);
				break;

			case'a':
			case'A':
				if (fighterList[i]->getStamina() > 5) {
					std::cout << "Possible targets: " << std::endl;
					for (int k = 0; k < numFighters; k++)
						if (fighterList[i]->getName() != fighterList[k]->getName())
							std::cout << fighterList[k]->getName() << "     " << std::endl;


					while (true) {
						Fighter* ptr = getFighterByName(((std::cin >> action), action));
						if (ptr) {
							fighterList[i]->attack(ptr);
							Sleep(3000);
							break;
						}
						else
							std::cout << "Invalid target, try again" << std::endl;
					}
					Sleep(3000);
					break;
				}
				else
					std::cout << "You currently have " << fighterList[i]->getStamina() << " stamina. You need at least 5 stamina to attack someone."
					<< std::endl;
				break;

			default:
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Incorrect input. Try again." << std::endl;
				incoInput = true;

			}
		}
	}
}

Fighter* FighterGame::getFighterByName(std::string name) {
	for (int j = 0; j < numFighters; j++)
		if (fighterList[j]->getName() == name)
			return fighterList[j];
	return nullptr;
}