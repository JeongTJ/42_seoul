#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
	public:
		class FileNotOpenException: public std::exception {
			public:
				FileNotOpenException(void);
				~FileNotOpenException() throw();
				FileNotOpenException(const FileNotOpenException& other);
				FileNotOpenException& operator=(const FileNotOpenException& other);
				const char* what(void) const throw();
		};
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		void execute(Bureaucrat const& executor) const;
	private:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		std::string target;

};
#endif
