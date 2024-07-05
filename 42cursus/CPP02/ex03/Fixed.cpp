#include "Fixed.hpp"

Fixed::Fixed(void): fractionalBits(8), rawBits(0) { }

Fixed::Fixed(int const num): fractionalBits(8), rawBits(num << this->fractionalBits) { }

Fixed::Fixed(float const num): fractionalBits(8), rawBits(roundf(num * (1 << this->fractionalBits))) { }

Fixed::~Fixed(void) { }

Fixed::Fixed(const Fixed &other): fractionalBits(other.fractionalBits), rawBits(other.rawBits) { }

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		this->rawBits = other.rawBits;
		this->fractionalBits = other.fractionalBits;
	}
	return *this;
}

bool Fixed::operator>(const Fixed &other) const {
	return this->rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->rawBits != other.rawBits;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/( const Fixed &other ) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void) {
	this->rawBits++;
	return (*this);
}

Fixed &Fixed::operator--(void) {
	this->rawBits--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);

	this->rawBits++;
	return (tmp);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(this->toFloat());

	this->rawBits--;
	return (tmp);
}

Fixed Fixed::operator-(void) {
	Fixed tmp(*this);

	return (tmp * Fixed(-1));
}

const Fixed Fixed::absF(const Fixed &a) {
	Fixed tmp(a);

	if (tmp < 0)
		return -tmp;
	return tmp;
}


Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

int Fixed::getRawBits(void) const {
	return this->rawBits;
}

void Fixed::setRawBits(int const rawBits) {
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


