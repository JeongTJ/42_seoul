#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Gildong Hong"), grade(0) {
	// 구현체 없음
}

Bureaucrat::Bureaucrat(const std::string &name): name(name), grade(0) {
	// 구현체 없음
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name), grade(other.grade) {
	// 구현체 없음
}

Bureaucrat::~Bureaucrat() {
	// 구현체 없음
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this == &other)
		return *this;
	this->grade = other.grade;
	return *this;
}

const std::string &Bureaucrat::getName(void) {
	return name;
}

unsigned int Bureaucrat::getGrade(void) {
	if (grade < 1)
		throw 
}
