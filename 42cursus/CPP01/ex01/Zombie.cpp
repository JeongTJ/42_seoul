#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ): name(name) {}

Zombie::Zombie( void ) {
	this->name = "init_name";
}

Zombie::~Zombie( void ) {
	std::cout << name << " delete" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name ) {
	this->name = name;
}