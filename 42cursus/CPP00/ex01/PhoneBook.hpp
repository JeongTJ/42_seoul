#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define LAST_IDX 7

class PhoneBook{
	public:
		PhoneBook( void );
		void saveContact( void );
		void printAllContact( void );
		void printContact( int idx );
	private:
		Contact contacts[8];
		int size;
};

#endif