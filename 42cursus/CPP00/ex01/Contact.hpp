#pragma once
#include <string>

class Contact{
	public:
		Contact(void);
		void putInfo(void);
		void printInfo(void);
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
};