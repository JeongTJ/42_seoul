#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap a;

	a.whoAmI();
	a.attack("B");
	a.beRepaired(10);
	a.takeDamage(10);
	return 0;
}
