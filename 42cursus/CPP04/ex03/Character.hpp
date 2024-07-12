#pragma once
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"


class Character {
	public:
		Character(void);
		Character(const Character &other);
		virtual ~Character();
		Character &operator=(const Character &other);

		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
	private:
		std::string name;
		AMateria *inventory[4];
};

#endif
