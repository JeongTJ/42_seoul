#include <iostream>
#include <sstream>
#include "PhoneBook.hpp"

int main(void) {
	Contact contact;
	PhoneBook phonebook;
	std::string cmd;

	while (!std::cin.eof()) {
		std::cout << "Please input (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, cmd);
		if (cmd.compare("ADD") == 0)
			phonebook.saveContact();
		else if (cmd.compare("SEARCH") == 0)
			phonebook.printAllContact();
		else if (cmd.compare("EXIT") == 0)
			break ;
	}
}