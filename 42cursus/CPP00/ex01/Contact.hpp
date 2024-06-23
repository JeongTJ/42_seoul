#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#define ERROR_MSG "Please input a non-empty string."
#include <string>

class Contact{
	public:
		Contact( void );
		void putInfo( void );
		void printInfo( void );
		void printInfoDetail( void );
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif
