#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {
	// 구현체 없음
}

Ice::Ice(const Ice &other): AMateria(other) {
	// 구현체 없음
}

Ice::~Ice() {
	// 구현체 없음
}

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
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
