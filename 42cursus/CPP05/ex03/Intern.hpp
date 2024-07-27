#pragma	once
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {
	public:
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
