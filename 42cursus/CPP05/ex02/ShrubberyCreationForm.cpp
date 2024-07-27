#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name): AForm(name, 145, 137) {
	std::ofstream writeFile;

	writeFile.open((name + "_shrubbery").c_str(), std::ios_base::trunc);
	if (!writeFile.is_open()) {
		throw 
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (std::remove((this->getName() + "_shrubbery").c_str()))
		std::cout << "File not exist" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other) {

}


