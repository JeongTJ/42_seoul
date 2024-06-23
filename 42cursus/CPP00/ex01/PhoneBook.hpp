#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_SIZE 8

class PhoneBook{
	public:
		PhoneBook( void );
		void saveContact( void );
		void printAllContact( void );
		void printContactDetail( void );
	private:
		Contact contacts[8];
		int size;
};

#endif
