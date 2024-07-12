#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	f(void) {system("leaks CPP04_ex02");}

int main() {
	atexit(f);

	// Animal *a = new Animal();
	Animal *a = new Cat();

	a->makeSound();

	delete a;
	return 0;
}
