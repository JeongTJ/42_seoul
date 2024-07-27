#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
	public:
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		void execute(Bureaucrat const& executor) const;
	private:
		PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		std::string target;

};

#endif
