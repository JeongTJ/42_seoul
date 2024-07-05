#include "Fixed.hpp"

Fixed::Fixed(void): fractionalBits(8), rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const num): fractionalBits(8), rawBits(num << this->fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const num): fractionalBits(8), rawBits(roundf(num * (1 << this->fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): fractionalBits(other.fractionalBits), rawBits(other.rawBits) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->rawBits = other.rawBits;
		this->fractionalBits = other.fractionalBits;
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits(int const rawBits) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits = rawBits;
}

float Fixed::toFloat(void) const {
	float res = rawBits;

	return res / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

