#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void): WrongAnimal("WrongCat"), brain(new Brain()) {
	std::cout << "[WrongCat] " << this->type << "타입의 동물 기본 생성." << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type), brain(new Brain()) {
	std::cout << "[WrongCat] " << this->type << "타입의 동물 생성." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "[WrongCat] " << this->type << "타입의 동물 복사 생성." << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "[WrongCat] " << this->type << "타입의 동물 제거." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this == &other)
		return *this;
	std::cout << "[WrongCat] " << this->type << "타입의 동물 복사 대입." << std::endl;
	WrongAnimal::operator=(other);
	*this->brain = *other.brain;
	return *this;
}

void WrongCat::makeSound(void) const{
	std::cout << "[WrongCat] " << this->type << ": 야옹~" << std::endl;
}
