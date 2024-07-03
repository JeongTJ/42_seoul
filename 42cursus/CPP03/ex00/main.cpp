#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("A"), b("B");

	a.attack("B");
	a.takeDamage(1);
	a.takeDamage(2);
	a.takeDamage(3);
	a.takeDamage(3);
	a.beRepaired(4);
	a.takeDamage(3);
	a.takeDamage(3);
	a.attack("B");
	a.takeDamage(3);
	return 0;
}
