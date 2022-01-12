#include "Item.h"

class Consumable : public Item {
public:
	Consumable(int h, std::string n) : healing(h), Item(n, consumable ) { }

private:
	int healing;
};