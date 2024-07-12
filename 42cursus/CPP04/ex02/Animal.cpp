#include "Animal.hpp"
#include <iostream>

Animal::Animal(void): type("Animal") {
	std::cout << "[Animal] " << this->type << "타입의 동물 기본 생성." << std::endl;
}

Animal::Animal(std::string type): type(type) {
	std::cout << "[Animal] " << this->type << "타입의 동물 생성." << std::endl;
}

Animal::Animal(const Animal &other): type(other.type) {
	std::cout << "[Animal] " << this->type << "타입의 동물 복사 생성." << std::endl;
}

Animal::~Animal() {
	std::cout << "[Animal] " << this->type << "타입의 동물 제거." << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	if (this == &other)
		return *this;
	std::cout << "[Animal] " << this->type << "타입의 동물 복사 대입." << std::endl;
	this->type = other.type;
	return *this;
}

const std::string &Animal::getType(void) const {
	return this->type;
}
