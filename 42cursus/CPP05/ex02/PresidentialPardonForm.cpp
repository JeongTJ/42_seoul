#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5), target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target) {

}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSign())
		throw AForm::NotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "Informs that " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
