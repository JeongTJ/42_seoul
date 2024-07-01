#include "Fixed.hpp"

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	fractionalBits = 8;
	rawBits = 0;
}

Fixed::Fixed( int const num ) {
	std::cout << "Int constructor called" << std::endl;
	fractionalBits = 8;
	rawBits = num << fractionalBits;
}

Fixed::Fixed( float const num ) {
	std::cout << "Float constructor called" << std::endl;
	fractionalBits = 8;
	rawBits = roundf(num * (1 << fractionalBits));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->rawBits = fixed.rawBits;
		this->fractionalBits = fixed.fractionalBits;
	}
	return *this;
}


int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits( int const rawBits ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = rawBits;
}

float Fixed::toFloat( void ) const {
	float res = rawBits;

	return res / (1 << fractionalBits);
}

int Fixed::toInt( void ) const {
	return rawBits >> fractionalBits;
}

std::ostream &operator<<( std::ostream &out, const Fixed &fixed ) {
	out << fixed.toFloat();
	return out;
}

