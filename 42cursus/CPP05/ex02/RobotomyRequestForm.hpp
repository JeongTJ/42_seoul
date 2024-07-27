#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
	public:
		RobotomyRequestForm(const std::string& name);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
};
#endif
