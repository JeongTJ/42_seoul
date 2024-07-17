#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(): type("non-type") {
	// 구현체 없음
}

AMateria::AMateria(const AMateria &other): type(other.type) {
	// 구현체 없음
}

AMateria::AMateria(std::string const &type): type(type) {
	// 구현체 없음
}

AMateria::~AMateria() {
	// 구현체 없음
}

AMateria &AMateria::operator=(const AMateria &other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

std::string const &AMateria::getType() const {
	return this->type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "어쩔티비 " << target.getName() << std::endl;
}
