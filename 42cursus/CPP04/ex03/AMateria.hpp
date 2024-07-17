#pragma once
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {
	public:
		AMateria(void);
		AMateria(const AMateria &other);
		AMateria(std::string const &type);
		virtual ~AMateria();
		AMateria &operator=(const AMateria &other);

		std::string const &getType(void) const; //Returns the materia type

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter &target);
	protected:
		std::string type;
};

#endif

