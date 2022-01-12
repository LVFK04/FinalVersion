#pragma once
#include <string>

enum ItemType
{
	none, consumable, weapon, armour
};

class Item {
public:
	Item(std::string n, ItemType t) : name(n), type(t) {}
protected:
	std::string name;
	ItemType type;
public:
	ItemType Type() { return type; }
};

