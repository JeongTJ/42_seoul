#include "Harl.hpp"

int main( void ) {
	Harl harl = Harl();

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("jiohsfale");
	return (0);
}