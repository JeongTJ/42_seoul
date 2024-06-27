#include "Zombie.hpp"

void zombieArea(Zombie **bZombie) {
	Zombie aZombie("nameA");
	*bZombie = newZombie("nameB");
	aZombie.announce();
	(*bZombie)->announce();
}

int main( void ) {
	Zombie* bZombie;

	zombieArea(&bZombie);

	randomChump("randomZombie");

	delete bZombie;
	return (0);
}