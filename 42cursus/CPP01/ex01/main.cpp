#include "Zombie.hpp"

int main( void ) {
	Zombie *zombies = zombieHorde(10, "test zombie");
	Zombie *zombiesP = zombies + 1;
	zombiesP->setName("kk");
	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	delete []zombies;
	return (0);
}
