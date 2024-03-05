#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(){
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

void Contact::putInfo() {
	std::string tmp = "";
	while (!std::cin.eof()) {
		std::cout << "Put your first_name: ";
		std::getline(std::cin, tmp);

		if (std::cin.eof())
			break ;
		if (tmp.empty()) {
			std::cout << "Please input a non-empty string." << std::endl;
		} else {
			break;
		} 
	}
	firstName = tmp;
	tmp = "";
	while (!std::cin.eof()) {
		std::cout << "Put your last_name: ";
		std::getline(std::cin, tmp);

		if (std::cin.eof())
			break ;
		if (tmp.empty()) {
			std::cout << "Please input a non-empty string." << std::endl;
		} else {
			break;
		} 
	}
	lastName = tmp;
	tmp = "";
	while (!std::cin.eof()) {
		std::cout << "Put your nick_name: ";
		std::getline(std::cin, tmp);

		if (std::cin.eof())
			break ;
		if (tmp.empty()) {
			std::cout << "Please input a non-empty string." << std::endl;
		} else {
			break;
		} 
	}
	nickName = tmp;
	tmp = "";
	while (!std::cin.eof()) {
		std::cout << "Put your phone_number: ";
		std::getline(std::cin, tmp);

		if (std::cin.eof())
			break ;
		if (tmp.empty()) {
			std::cout << "Please input a non-empty string." << std::endl;
		} else {
			break;
		} 
	}
	phoneNumber = tmp;
	tmp = "";
	while (!std::cin.eof()) {
		std::cout << "Put your darkest_secret: ";
		std::getline(std::cin, tmp);

		if (std::cin.eof())
			break ;
		if (tmp.empty()) {
			std::cout << "Please input a non-empty string." << std::endl;
		} else {
			break;
		} 
	}
	darkestSecret = tmp;
	tmp = "";
}

void Contact::printInfo() {
	std::string tmp = "";
	
	tmp = this->firstName;
	if (this->firstName.length() > 10)
		tmp = this->firstName.substr(0, 9) + ".";
	std::cout << std::right << std::setw(10) << tmp << '|';

	tmp = this->lastName;
	if (this->lastName.length() > 10)
		tmp = this->lastName.substr(0, 9) + ".";
	std::cout << std::right << std::setw(10) << tmp << '|';

	tmp = this->nickName;
	if (this->nickName.length() > 10)
		tmp = this->nickName.substr(0, 9) + ".";
	std::cout << std::right << std::setw(10) << tmp << '|';

	tmp = this->phoneNumber;
	if (this->phoneNumber.length() > 10)
		tmp = this->phoneNumber.substr(0, 9) + ".";
	std::cout << std::right << std::setw(10) << tmp << std::endl;
}