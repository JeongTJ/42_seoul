#include "Bureaucrat.hpp"
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                                 Bureaucrat                                 */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat(const std::string &name, const unsigned int& grade): name(name), grade(grade) {
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade) {
	// 구현체 없음
}

Bureaucrat::~Bureaucrat() {
	// 구현체 없음
}

const std::string &Bureaucrat::getName(void) const{
	return name;
}

unsigned int Bureaucrat::getGrade(void) const{
	return grade;
}

void Bureaucrat::increment(unsigned int incre) {
	if (this->grade <= incre)
		throw Bureaucrat::GradeTooHighException();
	this->grade -= incre;
}

void Bureaucrat::decrement(unsigned int decre) {
	if (this->grade + decre > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade += decre;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cerr << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) {
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cerr << this->name << " failed executed " << form.getName() << " because " << e.what() << std::endl;
	}
}

/* -------------------------------------------------------------------------- */
/*                            GradeTooHighException                           */
/* -------------------------------------------------------------------------- */

Bureaucrat::GradeTooHighException::GradeTooHighException(): std::exception() {
	// 구현체 없음
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
	// 구현체 없음
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const Bureaucrat::GradeTooHighException &other): std::exception(other) {
	// 구현체 없음
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(const Bureaucrat::GradeTooHighException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat::GradeTooHighException";
}

/* -------------------------------------------------------------------------- */
/*                            GradeTooLowException                            */
/* -------------------------------------------------------------------------- */

Bureaucrat::GradeTooLowException::GradeTooLowException(): std::exception() {
	// 구현체 없음
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
	// 구현체 없음
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const Bureaucrat::GradeTooLowException &other): std::exception(other) {
	// 구현체 없음
}

Bureaucrat::GradeTooLowException &Bureaucrat::GradeTooLowException::operator=(const Bureaucrat::GradeTooLowException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat::GradeTooLowException";
}

/* -------------------------------------------------------------------------- */
/*                                  insertion                                 */
/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &ostrm, const Bureaucrat &bureaucrat) {
	ostrm << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return ostrm;
}
