#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

const std::string Intern::formNames[3] =
	{"ShrubberyCreationForm",
	"RobotomyRequestForm",
	"PresidentialPardonForm"};

Intern::Intern(const std::string& name): name(name) {
	// 구현체 없음
}

Intern::~Intern() {
	// 구현체 없음
}

Intern::Intern(const Intern& other): name(other.name) {
	// 구현체 없음
}

Intern& Intern::operator=(const Intern& other) {
	if (this == &other)
		return *this;
	this->name = other.name;
	return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	AForm* form;
	switch(formNameToInt(name)){
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			std::cerr << name << " form not exist" << std::endl;
			return NULL;
	}
	std::cout << this->name << " creates " << form->getName() << std::endl;
	return form;
}

int	Intern::formNameToInt(const std::string& formName) {
	int i = 0;
	for (i = 0; i < 3 && formNames[i].compare(formName) != 0; i++);
	return i;
}
/* -------------------------------------------------------------------------- */
/*                                 FileNotOpen                                */
/* -------------------------------------------------------------------------- */

Intern::NotFormNameException::NotFormNameException(): std::exception() {
	// 구현체 없음
}

Intern::NotFormNameException::~NotFormNameException() throw() {
	// 구현체 없음
}

Intern::NotFormNameException::NotFormNameException(const Intern::NotFormNameException &other): std::exception(other) {
	// 구현체 없음
}

Intern::NotFormNameException &Intern::NotFormNameException::operator=(const Intern::NotFormNameException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *Intern::NotFormNameException::what() const throw() {
	return "Intern::NotFormNameException";
}
