#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap a("A");
	ScavTrap b;
	ClapTrap c;
	b = b;
	c = a;
	a.attack("ScavTrap target");
	b.attack("ClapTrap target");


	return 0;
}
