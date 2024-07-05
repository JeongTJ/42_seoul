#include "HumanB.hpp"

HumanB::HumanB( std::string name ): name(name), weapon(NULL) { }

HumanB::~HumanB( void ) { }

void HumanB::attack( void ) {
	if (this->weapon == NULL)
		std::cout << this->name << " have no weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& weapon ) {
	this->weapon = &weapon;
}
