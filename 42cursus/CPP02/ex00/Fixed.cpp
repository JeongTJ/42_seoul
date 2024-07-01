#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	rawBits = 0;
	fractionalBits = 8;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->rawBits = fixed.rawBits;
		this->fractionalBits = fixed.fractionalBits;
	}
	return *this;
}

Fixed::Fixed( const Fixed &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits( int const rawBits ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = rawBits;
}

