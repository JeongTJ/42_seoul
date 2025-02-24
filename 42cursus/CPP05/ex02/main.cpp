#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.cpp"

#include <unistd.h>

int main() {
	try {
		Bureaucrat a("tajeong", 1);
		ShrubberyCreationForm b("home");
		RobotomyRequestForm c("robot");
		PresidentialPardonForm d("presi");
		a.signForm(c);
		a.executeForm(c);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
