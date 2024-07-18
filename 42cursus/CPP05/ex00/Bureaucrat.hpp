#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string &getName(void);
		unsigned int getGrade(void);
	private:
		const std::string name;
		unsigned int grade;
};

#endif
