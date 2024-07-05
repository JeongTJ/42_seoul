#include "Fixed.hpp"

Fixed::Fixed(void): fractionalBits(8), rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->rawBits = fixed.rawBits;
		this->fractionalBits = fixed.fractionalBits;
	}
	return *this;
}

Fixed::Fixed(const Fixed &other): fractionalBits(other.fractionalBits), rawBits(other.rawBits) {
	std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits(int const rawBits) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = rawBits;
}

