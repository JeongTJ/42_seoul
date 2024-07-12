#include "AMateria.hpp"

AMateria::AMateria(const AMateria &other): type(other.type) { }

AMateria::AMateria(std::string const &type): type(type) { }


AMateria::~AMateria() { }

AMateria &AMateria::operator=(const AMateria &other) { }
