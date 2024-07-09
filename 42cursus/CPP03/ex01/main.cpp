#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap a("A");
	ScavTrap b("B");

	for (int i = 0; i < 4; i++) {
		a.attack("B");
		b.takeDamage(20);
	}

	ScavTrap c = a;

	for (int i = 0; i < 50; i++) {
		c.beRepaired(i);
	}
	for (int i = 0; i < 50; i++) {
		a.beRepaired(i);
	}
	return 0;
}
