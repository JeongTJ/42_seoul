#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") { }

Cure::Cure(const Cure &other): AMateria(other) { }

Cure::~Cure() { }

Cure &Cure::operator=(const Cure &other) {
	if (this == &other)
		return *this;
	AMateria::operator=(other);
	return *this;
}

AMateria *Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
