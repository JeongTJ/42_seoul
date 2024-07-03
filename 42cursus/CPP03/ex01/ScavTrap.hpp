#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap( std::string );
		~ScavTrap( void );
		ScavTrap( const ScavTrap &scavTrap );
		ScavTrap &operator=( const ScavTrap &rValue );
};

#endif
