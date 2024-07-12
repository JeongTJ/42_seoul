#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"

class MateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		virtual ~MateriaSource();
		MateriaSource &operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
