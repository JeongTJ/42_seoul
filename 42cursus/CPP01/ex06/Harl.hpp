#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void excp( void );
		void (Harl::*f[5])( void );
		int levelToIdx( std::string level );
		std::string level[5];
	public:
		Harl( void );
		~Harl( void );
		void complain( std::string level );
};

#endif
