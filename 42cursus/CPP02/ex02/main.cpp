#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;

	std::cout << std::left << std::setw(15) << "a" << ": " << a << std::endl;
	std::cout << std::left << std::setw(15) << "a++" << ": " << a++ << std::endl;
	std::cout << std::left << std::setw(15) << "a" << ": " << a << std::endl;
	std::cout << std::left << std::setw(15) << "++a" << ": " << ++a << std::endl;
	std::cout << std::left << std::setw(15) << "a" << ": " << a << std::endl;
	std::cout << std::left << std::setw(15) << "b" << ": " << b << std::endl;
	std::cout << std::left << std::setw(15) << "a + b" << ": " << a + b << std::endl;
	c = a + b;
	std::cout << std::left << std::setw(15) << "c" << ": " << c << std::endl;
	c = Fixed((float)2.5);
	std::cout << std::left << std::setw(15) << "c" << ": " << c << std::endl;
	a = Fixed(100);
	std::cout << std::left << std::setw(15) << "a" << ": " << a << std::endl;
	std::cout << std::left << std::setw(15) << "a + c" << ": " << a + c << std::endl;
	std::cout << std::left << std::setw(15) << "a - c" << ": " << a - c << std::endl;
	std::cout << std::left << std::setw(15) << "a * c" << ": " << a * c << std::endl;
	std::cout << std::left << std::setw(15) << "a / c" << ": " << a / c << std::endl;


	std::cout << std::left << std::setw(15) << "max( a, b )" << ": " << Fixed::max( a, b ) << std::endl;
	std::cout << std::left << std::setw(15) << "min( a, b )" << ": " << Fixed::min( a, b ) << std::endl;
	std::cout << std::left << std::setw(15) << "max( 2.5, 2.4 )" << ": " << Fixed::max( (float)2.5, (float)2.4 ) << std::endl;
	std::cout << std::left << std::setw(15) << "min( 2.5, 2.4 )" << ": " << Fixed::min( (float)2.5, (float)2.4 ) << std::endl;

	return 0;
}
