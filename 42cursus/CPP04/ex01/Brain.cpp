#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "[Brain] " << "뇌 생성." << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &other) {
	std::cout << "[Brain] " << "뇌 복사 생성." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain::~Brain() {
	std::cout << "[Brain] " << "뇌 제거." << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	std::cout << "[Brain] " << "뇌 복사 대입." << std::endl;
	return *this;
}

