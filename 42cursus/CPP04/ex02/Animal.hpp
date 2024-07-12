#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &other);
		virtual ~Animal();
		Animal &operator=(const Animal &other);
		virtual void makeSound(void) const = 0;
		const std::string &getType(void) const;

	protected:
		std::string type;
};

#endif

