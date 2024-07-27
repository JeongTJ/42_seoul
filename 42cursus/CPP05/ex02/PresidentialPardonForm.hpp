#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm(const std::string& name);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
	private:
		PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
};

#endif
