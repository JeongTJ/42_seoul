#pragma once
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		~Cat();
		Cat &operator=(const Cat &other);
		void makeSound(void) const;
	private:
		Brain *brain;

};

#endif

