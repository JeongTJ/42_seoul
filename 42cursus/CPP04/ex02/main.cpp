#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	Animal *a = new Cat();

	a->makeSound();

	delete a;
	return 0;
}
