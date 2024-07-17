#pragma once
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define SOURCE_SIZE 4

class MateriaSource: public IMateriaSource {
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		virtual ~MateriaSource();
		MateriaSource &operator=(const MateriaSource &other);

		virtual void learnMateria(AMateria *materia);
		virtual AMateria* createMateria(std::string const &type);
	private:
		AMateria *source[SOURCE_SIZE];
};

#endif
