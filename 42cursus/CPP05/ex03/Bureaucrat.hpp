#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
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
	public:
		Bureaucrat(const std::string& name, const unsigned int& grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		const std::string &getName(void) const;
		unsigned int getGrade(void) const;
		void increment(const unsigned int& incre);
		void decrement(const unsigned int& decre);
		void signForm(AForm& form);
		void executeForm(AForm const& form);
	private:
		Bureaucrat(void); // 사용하지 않음.
		Bureaucrat& operator=(const Bureaucrat& other); // 사용하지 않음.
		const std::string name;
		unsigned int grade;
};

std::ostream& operator<<(std::ostream& ostrm, const Bureaucrat& bureaucrat);

#endif
