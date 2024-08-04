#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target) {

}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (!this->getIsSign())
		throw AForm::NotSignedException();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	std::ofstream outFile((this->target + "_shrubbery").c_str());
	if (outFile.is_open()) {
		outFile << "     / \\" << std::endl;
		outFile << "    /   \\" << std::endl;
		outFile << "   / | | \\" << std::endl;
		outFile << "   / | | \\" << std::endl;
		outFile << "   / | | \\" << std::endl;
		outFile << "   / | | \\" << std::endl;
		outFile << "     | |" << std::endl;
		outFile << "     | |" << std::endl;
		outFile << "     | |" << std::endl;
		outFile << "    /| |\\" << std::endl;
		outFile.close();
	} else {
		throw ShrubberyCreationForm::FileNotOpenException();
	}
}

/* -------------------------------------------------------------------------- */
/*                            FileNotOpenException                            */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::FileNotOpenException::FileNotOpenException(): std::exception() {
	// 구현체 없음
}

ShrubberyCreationForm::FileNotOpenException::~FileNotOpenException() throw() {
	// 구현체 없음
}

ShrubberyCreationForm::FileNotOpenException::FileNotOpenException(const ShrubberyCreationForm::FileNotOpenException &other): std::exception(other) {
	// 구현체 없음
}

ShrubberyCreationForm::FileNotOpenException &ShrubberyCreationForm::FileNotOpenException::operator=(const ShrubberyCreationForm::FileNotOpenException &other) {
	if (this == &other)
		return *this;
	std::exception::operator=(other);
	return *this;
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return "ShrubberyCreationForm::FileNotOpenException";
}

