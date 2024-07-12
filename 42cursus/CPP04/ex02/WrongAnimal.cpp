#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void): type("WrongAnimal") {
	std::cout << "[WrongAnimal] " << this->type << "타입의 동물 기본 생성." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type) {
	std::cout << "[WrongAnimal] " << this->type << "타입의 동물 생성." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other): type(other.type) {
	std::cout << "[WrongAnimal] " << this->type << "타입의 동물 복사 생성." << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] " << this->type << "타입의 동물 제거." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other)
		return *this;
	std::cout << "[WrongAnimal] " << this->type << "타입의 동물 복사 대입." << std::endl;
	this->type = other.type;
	return *this;
}

void WrongAnimal::makeSound(void) const{
	std::cout << "[WrongAnimal] " << this->type << "타입의 동물은 울 수 없어요." << std::endl;
}

const std::string &WrongAnimal::getType(void) const {
	return this->type;
}

