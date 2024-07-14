#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	name("defaultName"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	std::cout << "[ClapTrap] " << this->name << "객체를 기본 생성." << std::endl;
}

ClapTrap::ClapTrap(const std::string &name):
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	std::cout << "[ClapTrap] " << this->name << "객체를 생성." << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "[ClapTrap] " << this->name << "객체를 제거." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other):
	name(other.name),
	hitPoints(other.hitPoints),
	energyPoints(other.energyPoints),
	attackDamage(other.attackDamage) {
	std::cout << "[ClapTrap] " << this->name << "객체를 복사 생성." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this == &other)
		return (*this);
	std::cout << "[ClapTrap] " << other.name << "객체를 " << this->name << "객체에 복사 대입." << std::endl;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return (*this);
}

void ClapTrap::attack(std::string const &target) {
	if (this->hitPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "객체의 생명은 꺼져있어서 데미지를 줄 수 없다." << std::endl;
	else if (this->energyPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "객체의 활동력(energyPoint)이 없어서 데미지를 줄 수 없다." << std::endl;
	else {
		std::cout << "[ClapTrap] " << this->name << "객체가 " << target << "객체에게 " << this->attackDamage << "의 데미지를 주었다!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "[ClapTrap] " << this->name << "객체가 " << amount << "의 데미지를 입었다!" << std::endl;
	if (this->hitPoints == 0)
		std::cout << "           " << "하지만 " << this->name << "객체의 생명은 이미 꺼져있다." << std::endl;
	else {
		std::cout << "           " << this->name << "객체의 남은 체력은 " << (this->hitPoints < amount ? 0 : this->hitPoints - amount) << "이다." << std::endl;
		this->hitPoints = this->hitPoints < amount ? 0 : this->hitPoints - amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "객체의 생명은 꺼져있어서 회복할 수 없다." << std::endl;
	else if (this->energyPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "객체의 활동력(energyPoint)이 없어서 회복할 수 없다." << std::endl;
	else {
		std::cout << "[ClapTrap] " << this->name << "객체는 " << amount << "만큼 회복했다!" << std::endl;
		std::cout << "           " << this->name << "객체의 남은 체력은 " << (this->hitPoints + amount) << "이다." << std::endl;
		this->hitPoints = this->hitPoints + amount;
		this->energyPoints--;
	}
}
