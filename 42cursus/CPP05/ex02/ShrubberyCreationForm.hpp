#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: AForm {
	public:
		ShrubberyCreationForm(const std::string& name);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
	private:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);

};
#endif
