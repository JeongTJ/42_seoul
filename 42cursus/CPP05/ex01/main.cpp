#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form a("ex01", 10, 5);
		Bureaucrat b("tajeong", 15);

		b.signForm(a);
		std::cout << a;
		b.increment(5);
		b.signForm(a);
		std::cout << a;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
