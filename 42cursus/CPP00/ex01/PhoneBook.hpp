#pragma once
#include <string>
#include "Contact.hpp"
#define LAST_IDX 7


class PhoneBook{
	public:
		PhoneBook(void);
		void saveContact(void);
		void printAllContact(void);
		void printContact(int idx);
	private:
		Contact contacts[8];
		int size;
};