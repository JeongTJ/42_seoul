#include "Dog.hpp"
#include <iostream>

Dog::Dog(void): Animal("Dog"), brain(new Brain()) {
	std::cout << "[Dog] " << this->type << "타입의 동물 기본 생성." << std::endl;
}

Dog::Dog(std::string type): Animal(type), brain(new Brain()) {
	std::cout << "[Dog] " << this->type << "타입의 동물 생성." << std::endl;
}

Dog::Dog(const Dog &other): Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "[Dog] " << this->type << "타입의 동물 복사 생성." << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "[Dog] " << this->type << "타입의 동물 제거." << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	std::cout << "[Dog] " << this->type << "타입의 동물 복사 대입." << std::endl;
	Animal::operator=(other);
	*this->brain = *other.brain;
	return *this;
}

void Dog::makeSound(void) const{
	std::cout << "[Dog] " << this->type << ": 멍멍!" << std::endl;
}
