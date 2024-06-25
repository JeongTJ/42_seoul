#include "Zombie.hpp"

void f( void ) { system("sudo leaks zombie"); }

int main( int argc, char *argv[]) {
	atexit(f);
	if (argc != 1 && argv)
		return (0);
	Zombie* zombies = zombieHorde(10, "test zombie");
	for (int i = 0; i < 10; i++) {
		zombies[i].announce();
	}
	delete []zombies;
	return (0);
}