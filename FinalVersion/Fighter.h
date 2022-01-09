#pragma once
#include<string>
#include<iostream>

class Fighter {
public:
	Fighter();

	void attack(Fighter* tar);
	void defend();
	void rest();
	void shop();

private:
	std::string name;
	unsigned short health;
	unsigned short power;
	unsigned short stamina;
	unsigned short speed;
	unsigned short defencePower;

public:

	unsigned int getDefence() { return defencePower; }
	unsigned int getPower() { return power; }
	unsigned int getSpeed() { return speed; }
	unsigned int getStamina() { return stamina; }
	unsigned int getHealth() { return health; }
	std::string getName() { return name; }

	void loseHealth(unsigned int x) { health -= x; }
	void loseStamina(unsigned int x) { stamina -= x; }
	void setDefence(unsigned int x) { defencePower = x; }
};