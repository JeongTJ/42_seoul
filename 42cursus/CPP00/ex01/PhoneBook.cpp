#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	size = 0;
}

void PhoneBook::saveContact(void) {
	if (size == MAX_SIZE) {
		for (int i = 0; i < MAX_SIZE - 1 ; i++)
			contacts[i] = contacts[i + 1];
		contacts[size - 1].putInfo();
		return ;
	}
	contacts[size].putInfo();
	if (size != MAX_SIZE) size++;
}

void PhoneBook::printAllContact(void) {
	std::string tendashes = "----------";

	std::cout << "first_name" << '|' << " last_name" << '|' << " nick_name" << '|' << "phone_num." << std::endl;
	std::cout << tendashes << '|' << tendashes << '|' << tendashes << '|' << tendashes << std::endl;
	for (int i = 0; i < size; i++)
		if (i >= size)
			std::cout << "invalid idx" << std::endl;
		else
			this->contacts[i].printInfo();
	printContactDetail();
}

void PhoneBook::printContactDetail( void ) {
	int idx;
	std::string input;

	std::cout << "Please input contact idx" << std::endl;
	std::getline(std::cin, input);
	std::istringstream iss(input);
	std::cout << "========== Contact detail ==========" << std::endl;
	if (iss >> idx)
	{
		if (idx >= size)
			std::cout << "invalid idx" << std::endl;
		else
			this->contacts[idx].printInfoDetail();
	} else
		std::cout << "Invalid input" << std::endl;
	std::cout << "========== Contact detail ==========" << std::endl;
}
