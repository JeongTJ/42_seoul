#include "Weapon.hpp"
#include <iostream>
Weapon::Weapon( void ) {

}

Weapon::Weapon( std::string type ) {
	this->type = type;
}

Weapon::~Weapon( void ) { }

void Weapon::setType( std::string type ) {
	this->type = type;
}

const std::string& Weapon::getType( void ) {
	const std::string& weaponREF = this->type;

	return (weaponREF);
}
