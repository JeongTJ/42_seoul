#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[FragTrap] " << this->name << "객체를 기본 생성." << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "[FragTrap] " << this->name << "객체를 생성." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other) {
	std::cout << "[FragTrap] " << this->name << "객체를 복사 생성." << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "[FragTrap] " << this->name << "객체를 제거." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this == &other)
		return (*this);
	std::cout << "[FragTrap] " << other.name << "객체를 " << this->name << "객체에 복사 대입." << std::endl;
	ClapTrap::operator=(other);
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap] " << "우리 같이 하이파이브 해요!" << std::endl;
}
