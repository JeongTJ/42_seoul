#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{
	public:
		HumanB( std::string name );
		~HumanB( void );
		void attack( void );
		void setWeapon( Weapon& weapon );
	private:
		Weapon* weapon;
		std::string name;


};

#endif
