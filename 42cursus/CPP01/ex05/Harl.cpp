#include "Harl.hpp"

Harl::Harl( void ) {
	this->f[0] = &Harl::debug;
	this->f[1] = &Harl::info;
	this->f[2] = &Harl::warning;
	this->f[3] = &Harl::error;
	this->f[4] = &Harl::excp;
	level[0] = "DEBUG";
	level[1] = "INFO";
	level[2] = "WARNING";
	level[3] = "ERROR";
	level[4] = "EXCP";
}

Harl::~Harl( void ) { }

void Harl::complain( std::string level ) {
	(this->*f[this->levelToIdx(level)])();
}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::excp( void ) {
	std::cout << "exception level" << std::endl;
}

int Harl::levelToIdx( std::string level ) {
	for (int i = 0; i < 4; i++)
		if (level.compare(this->level[i]) == 0)
			return (i);
	return (4);
}
