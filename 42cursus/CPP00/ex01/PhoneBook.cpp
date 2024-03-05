#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	size = 0;
}

void PhoneBook::saveContact(void) {
	if (size == LAST_IDX)
		for (int i = 0; i < LAST_IDX; i--)
			this->contacts[i] = this->contacts[i + 1];
	this->contacts[this->size].putInfo();
	if (this->size != LAST_IDX) this->size++;
}

void PhoneBook::printAllContact(void) {
	std::string tendashes = "----------";
	std::string input;
	int idx;

	std::cout << "first_name" << '|' << " last_name" << '|' << " nick_name" << '|' << "phone_num." << std::endl;
	std::cout << tendashes << '|' << tendashes << '|' << tendashes << '|' << tendashes << std::endl;
	for (int i = 0; i < this->size; i++)
		this->printContact(i);
	std::cout << "Please input contact idx" << std::endl;
	std::cin >> input;
	std::istringstream iss(input);
	if (iss >> idx) {
	{
		std::cout << tendashes << '|' << tendashes << '|' << tendashes << '|' << tendashes << std::endl;
		this->printContact(idx);
	}
	} else {
		std::cout << "Invalid input" << std::endl;
	}
}

void PhoneBook::printContact(int idx) {
	if (idx >= this->size)
		std::cout << "invalded idx" << std::endl;
	else
		this->contacts[idx].printInfo();
}