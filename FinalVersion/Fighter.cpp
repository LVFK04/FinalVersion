#include"Fighter.h"
#include<Windows.h>

Fighter::Fighter() {
	std::cout << "Enter name: ";
	std::cin >> name;

	std::cout << "Power: 20" << std::endl
		<< "Stamina: 20" << std::endl
		<< "Speed: 20" << std::endl
		<< "Health: 20" << std::endl
		<< "\n\n\n\n\n######################################################\n\n\n\n\n";
	power = 20;
	stamina = 20;
	speed = 20;
	health = 20;
}

void Fighter::attack(Fighter* tar) {
	std::cout << "." << std::endl;
	Sleep(1000);
	std::cout << ".." << std::endl;
	Sleep(1000);
	std::cout << "..." << std::endl;
	Sleep(1000);
	
		if ((speed + power) / 2 >= tar->getDefence()) {
			tar->loseHealth(power / 2);
			tar->loseStamina(power / 10);
			loseStamina(5);
			std::cout << name << " manage to hit " << tar->getName() << " with a strike!" << std::endl
				<< "This causes " << tar->getName() << " to lose " << power / 2 << " health, and " << power / 10 << " stamina!" << std::endl
				<< tar->getName() << " now have " << tar->getHealth() << " health, and " << tar->getStamina() << " stamina."
				<< std::endl << name << " has " << stamina << " stamina left." << std::endl;
			return;
		}

		std::cout << name << " misses with the attack!" << std::endl;
		return;
	
}

void Fighter::defend() {
	defencePower += 20;
	stamina -= 5;
	
	std::cout << "You have choosen to defend yourself. This increases your defences with 20, to a total of " << getDefence() << std::endl;

}

void Fighter::rest() {
	health += 20;
	stamina += 20;
	speed += 20;
	std::cout << "You have choosen to rest. This restores 20 health, 20 stamina, and 20 speed." << std::endl
		<< "Stamina: " << getStamina() << std::endl
		<< "Speed: " << getSpeed() << std::endl
		<< "Health: " << getHealth() << std::endl;
}

void Fighter::shop() {
	std::cout << "You have choosen to go buy something. You can choose between three different potions:" << std::endl
		<< "Rage potion: Increases your power by 35, decreases your stamina by 10. Type 'Rage' to buy this potion." << std::endl
		<< "Health potion: Increases your health by 40. Type 'Health' to buy this potion." << std::endl
		<< "Speed potion: Increases your speed by 40%. Type 'Speed' to buy this poiton." <<std::endl;

	std::string option;
	
	bool badInput = true;
	while (badInput) {
		badInput = false;
		std::cin >> option;


		switch (option.c_str()[0]) {
		case'R':
		case'r':
			if (stamina > 10) {
				power += 35;
				stamina -= 10;
				std::cout << "You have choosen the rage-potion." << std::endl
					<< "Power: " << power << std::endl
					<< "Stamina: " << stamina << std::endl;
				break;
			}

			else {
				std::cout << "Your stamina is to low to decrease by 10. Current stamina: " << stamina << std::endl;
				break;
			}

		case'h':
		case'H':
			health *= 1.4;
			std::cout << "You have choosen the health-potion. Current healt: " << health << std::endl;
			break;

		case's':
		case'S':
			speed *= 1.4;
			std::cout << "You have choosen the speed-potion. Current speed: " << speed << std::endl;
			break;

		default:
			badInput = true;
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Incorrect input. Try again." << std::endl;

		}
	}
}