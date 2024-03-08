#include "Zombie.hpp"

int main( void ) {
	Zombie aZombie("nameA");
	Zombie* bZombie = newZombie("nameB");

	aZombie.announce();
	bZombie->announce();
	delete bZombie;
	return (0);
}