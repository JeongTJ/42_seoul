#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.cpp"
#include "Intern.hpp"

int main() {
	try {
		Intern internA("A");
		Bureaucrat A("tajeong", 100);
		AForm* rff;

		rff = internA.makeForm("ShrubberyCreationForm", "tajeong's tree");
		A.executeForm(*rff);
		A.signForm(*rff);
		A.executeForm(*rff);

		delete rff;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
