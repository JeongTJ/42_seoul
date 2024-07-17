#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (int i = 0; i < SOURCE_SIZE; i++)
		this->source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (int i = 0; i < SOURCE_SIZE; i++)
		this->source[i] = other.source[i];
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < SOURCE_SIZE; i++)
		delete this->source[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < SOURCE_SIZE; i++)
		this->source[i] = other.source[i];
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
	for (int i = 0; i < SOURCE_SIZE; i++)
		if (this->source[i] == NULL) {
			this->source[i] = materia;
			return ;
		}
	delete materia;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < SOURCE_SIZE; i++)
		if (source[i]->getType() == type)
			return source[i]->clone();
	return NULL;
}

