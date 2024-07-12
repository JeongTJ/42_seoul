#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat &other);
		~WrongCat();
		WrongCat &operator=(const WrongCat &other);
		void makeSound(void) const;
	private:
		Brain *brain;
};

#endif

