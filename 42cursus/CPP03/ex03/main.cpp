#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	FragTrap a("A");
	ScavTrap b("B");

	a.highFivesGuys();
	b.guardGate();

	ClapTrap c;

	c = a;

	for (int i = 0; i < 200; i++) {
		std::cout << "=========== " << i << " ===========" << std::endl;
		c.beRepaired(1);
	}

	c = b;

	for (int i = 0; i < 200; i++) {
		std::cout << "=========== " << i << " ===========" << std::endl;
		c.beRepaired(2);
	}

	return 0;
}
