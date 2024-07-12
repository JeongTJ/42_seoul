#include "Ice.hpp"

Ice::Ice(): AMateria("ice") { }

Ice::Ice(const Ice &other): AMateria(other) { }

Ice::~Ice() { }

Ice &Ice::operator=(const Ice &other) {
	if (this == &other)
		return *this;
	AMateria::operator=(other);
	return *this;
}

AMateria *Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	
}
