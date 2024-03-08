#include "Zombie.hpp"

void randomChump( std::string name ) {
	Zombie* tmpZombie = newZombie(name);
	tmpZombie->announce();
	delete tmpZombie;
}