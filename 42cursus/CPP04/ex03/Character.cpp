#include "Character.hpp"

Character::Character(): name("Gildong Hong") {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string &name): name(name) {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other): name(other.name) {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->inventory[i] = other.inventory[i]->clone();
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		delete this->inventory[i];
}

Character &Character::operator=(const Character &other) {
	if (this == &other)
		return *this;
	this->name = other.name;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		*this->inventory[i] = *other.inventory[i];
	return *this;
}


std::string const &Character::getName() const {
	return this->name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (inventory[i] == NULL) {
			inventory[i] = m;
			return ;
		}
}

void Character::unequip(int idx) {
	if (!(0 <= idx && idx < INVENTORY_SIZE))
		return ;
	if (inventory[idx])
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (!(0 <= idx && idx < INVENTORY_SIZE))
		return ;
	if (inventory[idx])
		inventory[idx]->use(target);
}

