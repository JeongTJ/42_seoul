#include "ex02.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void) {
	std::srand(std::time(0));

	switch (std::rand() % 3) {
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "A" << std::endl;
	} catch (std::exception& e) {
	}
	try {
		B& b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "B" << std::endl;
	} catch (std::exception& e) {
	}
	try {
		C& c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "C" << std::endl;
	} catch (std::exception& e) {
	}
}
