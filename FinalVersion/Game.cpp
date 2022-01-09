#include <iostream>
#include<Windows.h>
#include"Fighter.h"
#include"FighterGame.h"
using namespace std;

int numChecker();
int intChecker(int high, int low);

int main() {
	bool playAgain = true;

	while (playAgain) {
		cout << "How many players are you between 2 and 5?" << endl;
		FighterGame game(intChecker(2, 5));
		while (game.getNumberOfFighters() > 1)
			game.round();

		return 0;
	}
}

int numChecker(){
	int a;
	cin >> a;
	while (!cin.good()) {
		cin.clear();
		cin.ignore();
		cout << "Invalid input, try again" << endl;
		cin >> a;
	}
	return a;
}

int intChecker(int high, int low) {
	int a;
	cin >> a;
	while (!cin.good() || a > low || a < high) {
		cin.clear();
		cin.ignore();
		cout << "Invalid answer, try again" << endl;
		cin >> a;
	}
	return a;
}

