#pragma once
#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		class GradeTooHighException: public std::exception {
			public:
				GradeTooHighException(void);
				~GradeTooHighException() throw();
				GradeTooHighException(const GradeTooHighException& other);
				GradeTooHighException& operator=(const GradeTooHighException& other);
				const char* what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				GradeTooLowException(void);
				~GradeTooLowException() throw();
				GradeTooLowException(const GradeTooLowException& other);
				GradeTooLowException& operator=(const GradeTooLowException& other);
				const char* what(void) const throw();
		};
		AForm(const std::string& name, const unsigned int& gradeToSign, const unsigned int& gradeToExecute);
		~AForm();
		AForm(const std::string& name);
		AForm(const AForm& other);
		const std::string& getName(void) const;
		unsigned int getGradeToSign(void) const;
		unsigned int getGradeToExecute(void) const;
		bool getIsSign(void) const;
		void beSigned(const Bureaucrat& bureaucrat);
	private:
		AForm(void);
		AForm& operator=(const AForm& other);
		const std::string name;
		const unsigned int gradeToSign;
		const unsigned int gradeToExecute;
		bool isSign;
};

std::ostream &operator<<(std::ostream &ostrm, const AForm &aForm);

#endif
