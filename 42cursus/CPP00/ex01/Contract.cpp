#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact( void ){
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

void Contact::putInfo( void ) {
	std::string tmp = "";
	std::string *field[5] = {&firstName, &lastName, &nickName, &phoneNumber, &darkestSecret};
	std::string fieldName[5] = {"first_name", "last_name", "nick_name", "phone_number", "darkest_necret"};
	for (int i = 0; i < 5; i++) {
		while (!std::cin.eof()) {
			std::cout << "Put your " << fieldName[i] << ": ";
			std::getline(std::cin, tmp);

			if (std::cin.eof())
				break ;
			if (tmp.empty())
				std::cout << ERROR_MSG << std::endl;
			else
				break;
		}
		*field[i] = tmp;
		tmp = "";
	}
}

void Contact::printInfo( void ) {
	std::string tmp = "";
	std::string *field[4] = {&firstName, &lastName, &nickName, &phoneNumber};
	for (int i = 0; i < 4; i++) {
		tmp = *field[i];
		if (tmp.length() > 10)
			tmp = (*field[i]).substr(0, 9) + ".";
		std::cout << std::right << std::setw(10) << tmp;
		if (i == 3)
			std::cout << std::endl;
		else
			std::cout << '|';
	}
}

void Contact::printInfoDetail( void ) {
	std::string *field[5] = {&firstName, &lastName, &nickName, &phoneNumber, &darkestSecret};
	std::string fieldName[5] = {"first_name", "last_name", "nick_name", "phone_number", "darkest_necret"};
	for (int i = 0; i < 5; i++)
		std::cout << fieldName[i] << ": " << *field[i] << std::endl;
}
