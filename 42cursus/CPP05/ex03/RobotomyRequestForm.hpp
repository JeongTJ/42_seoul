#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		void execute(Bureaucrat const& executor) const;
	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		std::string target;

};
#endif
