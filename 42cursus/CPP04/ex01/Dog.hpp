#pragma once
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &other);
		~Dog();
		Dog &operator=(const Dog &other);
		void makeSound(void) const;
	private:
		Brain *brain;
};

#endif

