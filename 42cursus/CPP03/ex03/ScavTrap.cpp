#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "[ScavTrap] " << this->name << "객체를 기본 생성." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "[ScavTrap] " << this->name << "객체를 생성." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other) {
	std::cout << "[ScavTrap] " << this->name << "객체를 복사 생성." << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "[ScavTrap] " << this->name << "객체를 제거." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this == &other)
		return *this;
	std::cout << "[ScavTrap] " << other.name << "객체를 " << this->name << "객체에 복사 대입." << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (this->hitPoints == 0)
		std::cout << "[ScavTrap] " << this->name << "객체의 생명은 꺼져있어서 데미지를 줄 수 없다." << std::endl;
	else if (this->energyPoints == 0)
		std::cout << "[ScavTrap] " << this->name << "객체의 활동력(energyPoint)이 없어서 데미지를 줄 수 없다." << std::endl;
	else {
		std::cout << "[ScavTrap] " << this->name << "객체가 " << target << "객체에게 " << this->attackDamage << "의 데미지를 주었다!" << std::endl;
		this->energyPoints--;
	}
}

void ScavTrap::guardGate(void) {
	std::cout << "[ScavTrap] " << this->name << "객체는 게이트 키퍼 모드(Gate Keeper mode)에 진입하였습니다." << std::endl;
}

