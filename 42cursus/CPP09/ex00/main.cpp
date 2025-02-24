#include "BitcoinExchange.hpp"
#include <sstream>
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc != 2)
		return 1;
	try {
		BitcoinExchange btc(argv[1]);
		btc.run();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
