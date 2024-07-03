#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ):
	name("defaultName"),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	std::cout << "[ClapTrap] " << this->name << "이(가) 입장했습니다." << std::endl;
}

ClapTrap::ClapTrap( std::string name ):
	name(name),
	hitPoints(10),
	energyPoints(10),
	attackDamage(0) {
	std::cout << "[ClapTrap] " << this->name << "이(가) 입장했습니다." << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "[ClapTrap] " << this->name << "이(가) 퇴장했습니다." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap &ClapTrap ) {
	*this = ClapTrap;
	std::cout << "[ClapTrap] " << this->name << "이(가) 입장했습니다." << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &rValue ) {
	if (this != &rValue) {
		this->name = rValue.name;
		this->hitPoints = rValue.hitPoints;
		this->energyPoints = rValue.energyPoints;
		this->attackDamage = rValue.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack( std::string const &target ) {
	if (this->hitPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "의 생명은 꺼져있어서 데미지를 줄 수 없다." << std::endl;
	else if (this->energyPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "은 활동력(energyPoint)이 없어서 데미지를 줄 수 없다." << std::endl;
	else {
		std::cout << "[ClapTrap] " << this->name << "이(가) " << target << "에게 " << this->attackDamage << "의 데미지를 주었다!" << std::endl;
		this->energyPoints--;
	}
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->hitPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "의 생명은 이미 꺼져있다." << std::endl;
	else {
		std::cout << "[ClapTrap] " << this->name << "이(가) " << amount << "의 데미지를 입었다!" << std::endl;
		std::cout << "           " << this->name << "의 남은 체력은 " << (this->hitPoints < amount ? 0 : this->hitPoints - amount) << "이다." << std::endl;
		this->hitPoints = this->hitPoints < amount ? 0 : this->hitPoints - amount;
	}
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->energyPoints == 0)
		std::cout << "[ClapTrap] " << this->name << "은 활동력(energyPoint)이 없어서 회복할 수 없다." << std::endl;
	else {
		std::cout << "[ClapTrap] " << this->name << "은 " << amount << "만큼 회복했다!" << std::endl;
		std::cout << "           " << this->name << "의 남은 체력은 " << (this->hitPoints + amount) << "이다." << std::endl;
		this->hitPoints = this->hitPoints + amount;
		this->energyPoints--;
	}
}
