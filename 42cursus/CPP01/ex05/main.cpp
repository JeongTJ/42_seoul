#include "Harl.hpp"

int main( void ) {
	Harl harl = Harl();

	void (Harl::*f)(std::string level) = &Harl::complain;

	(harl.*f)("DEBUG");
	// harl.complain("DEBUG");
	// harl.complain("INFO");
	// harl.complain("WARNING");
	// harl.complain("ERROR");
	// harl.complain("jiohsfale");
	return (0);
}
