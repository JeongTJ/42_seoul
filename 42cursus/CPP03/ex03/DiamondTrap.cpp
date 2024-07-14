#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("DefaultName_clap_name"), name("DefaultName") {
	std::cout << "[DiamondTrap] " << this->name << "객체를 기본 생성." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name):
	ClapTrap(name + "_clap_trap"),
	ScavTrap(name), FragTrap(name),
	name(name) {
	std::cout << "[DiamondTrap] " << this->name << "객체를 생성." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other):
	ClapTrap(other.name + "_clap_trap"),
	ScavTrap(other), FragTrap(other),
	name(other.name) {
	std::cout << "[DiamondTrap] " << this->name << "객체를 복사 생성." << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "[DiamondTrap] " << this->name << "객체를 제거." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this == &other)
		return *this;
	std::cout << "[DiamondTrap] " << other.name << "객체를 " << this->name << "객체에 복사 대입." << std::endl;
	ScavTrap::operator=(other);
	FragTrap::operator=(other);
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "[DiamondTrap] " << this->name << std::endl;
	std::cout << "              " << this->ClapTrap::name << std::endl;
}

