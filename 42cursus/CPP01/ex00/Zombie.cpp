#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) {
	this->name = name;
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " delete" << std::endl;
}

void Zombie::announce( void ) {
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}