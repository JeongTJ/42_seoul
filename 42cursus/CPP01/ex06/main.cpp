#include "Harl.hpp"

int main( int argc, char *argv[] ) {
	Harl harl = Harl();

	if (argc != 2)
		return (1);
	harl.complain(argv[1]);
	return (0);
}