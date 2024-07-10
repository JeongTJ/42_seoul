#include "Cat.hpp"
#include <iostream>

Cat::Cat(void): Animal("Cat"), s(424242, 'x') {
	std::cout << "[Cat] " << this->type << "타입의 동물 기본 생성." << std::endl;
}

Cat::Cat(std::string type): Animal(type) {
	std::cout << "[Cat] " << this->type << "타입의 동물 생성." << std::endl;
}

Cat::Cat(const Cat &other): Animal(other) {
	std::cout << "[Cat] " << this->type << "타입의 동물 복사 생성." << std::endl;
}

Cat::~Cat() {
	std::cout << "[Cat] " << this->type << "타입의 동물 제거." << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this == &other)
		return *this;
	std::cout << "[Cat] " << this->type << "타입의 동물 복사 대입." << std::endl;
	Animal::operator=(other);
	return *this;
}

void Cat::makeSound(void) const{
	std::cout << "[Cat] " << this->type << ": 야옹~" << std::endl;
}
