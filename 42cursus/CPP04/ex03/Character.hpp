#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define INVENTORY_SIZE 4

class Character: public ICharacter {
	public:
		Character(void);
		Character(const std::string &name);
		Character(const Character &other);
		virtual ~Character();
		Character &operator=(const Character &other);

		virtual std::string const &getName(void) const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
	private:
		std::string name;
		AMateria *inventory[INVENTORY_SIZE];
};

#endif
