#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("A");
	ClapTrap b("B");

	for (int i = 0; i < 10; i++)
		a.attack("B");
	a.attack("B");

	for (int i = 1; i < 10; i++) {
		b.takeDamage(i);
		b.beRepaired(i - 1);
	}
	return 0;
}
