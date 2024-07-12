#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &other);
		void makeSound(void) const;
		const std::string &getType() const;

	protected:
		std::string type;
};

#endif

