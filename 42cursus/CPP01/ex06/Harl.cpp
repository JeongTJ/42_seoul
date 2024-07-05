#include "Harl.hpp"

Harl::Harl( void ) {
	f[0] = &Harl::debug;
	f[1] = &Harl::info;
	f[2] = &Harl::warning;
	f[3] = &Harl::error;
	f[4] = &Harl::excp;
	level[0] = "DEBUG";
	level[1] = "INFO";
	level[2] = "WARNING";
	level[3] = "ERROR";
	level[4] = "EXCP";
}

Harl::~Harl( void ) { }

void Harl::complain( std::string level ) {
	int idx = this->levelToIdx(level);

	switch (idx) {
		case 4:
			(this->*f[4])();
			break ;
		case 0:
			(this->*f[0])();
		case 1:
			(this->*f[1])();
		case 2:
			(this->*f[2])();
		case 3:
			(this->*f[3])();
	}
}

void Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::excp( void ) {
	std::cout << "[ EXCP ]" << std::endl;
	std::cout << "exception level" << std::endl;
	std::cout << std::endl;
}

int Harl::levelToIdx( std::string level ) {
	for (int i = 0; i < 4; i++)
		if (level.compare(this->level[i]) == 0)
			return (i);
	return (4);
}
