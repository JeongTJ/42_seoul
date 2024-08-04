#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
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
				GradeTooLowException &operator=(const GradeTooLowException& other);
				const char* what(void) const throw();
		};
		Bureaucrat(const std::string &name, const unsigned int& grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		const std::string &getName(void) const;
		unsigned int getGrade(void) const;
		void increment(unsigned int incre);
		void decrement(unsigned int decre);
	private:
		Bureaucrat(void); // 사용하지 않음.
		Bureaucrat &operator=(const Bureaucrat &other); // 사용하지 않음.
		const std::string name;
		unsigned int grade;
};

std::ostream &operator<<(std::ostream &ostrm, const Bureaucrat &bureaucrat);

#endif
