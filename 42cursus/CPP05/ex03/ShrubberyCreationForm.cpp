#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (std::remove((this->target + "_shrubbery").c_str()))
		throw std::runtime_error("Failed to delete file: " + (this->target + "_shrubbery") + ", error: " + std::string(strerror(errno)));
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
		throw std::runtime_error("Unable to open file for writing: " + (this->target + "_shrubbery") + ", error: " + std::string(strerror(errno)));
	}

}

