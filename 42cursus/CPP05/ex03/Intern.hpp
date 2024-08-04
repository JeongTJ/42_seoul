#pragma	once
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	public:
		class NotFormNameException: public std::exception {
			public:
				NotFormNameException(void);
				~NotFormNameException() throw();
				NotFormNameException(const NotFormNameException& other);
				NotFormNameException& operator=(const NotFormNameException& other);
				const char* what(void) const throw();
		};
		Intern(const std::string& name);
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		AForm *makeForm(const std::string& name, const std::string& target);
	private:
		Intern(void);
		int formNameToInt(const std::string& formName);
		std::string name;
		static const std::string formNames[3];
};

#endif
