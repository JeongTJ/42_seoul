#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("robotomyRequestForm", 72, 45), target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target) {

}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSign())
		throw AForm::NotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::srand(std::time(0));

	if (std::rand() % 2){
		std::cout << "Vrrrrrrr... " << std::endl;
		std::cout << "informs that has been robotomized successfully" << std::endl;
	}
	else
		std::cout << "informs that the robotomy failed" << std::endl;

}
