#include "Fixed.hpp"

Fixed::Fixed( void ) {
	fractionalBits = 8;
	rawBits = 0;
}

Fixed::Fixed( int const num ) {
	fractionalBits = 8;
	rawBits = num << fractionalBits;
}

Fixed::Fixed( float const num ) {
	fractionalBits = 8;
	rawBits = roundf(num * (1 << fractionalBits));
}

Fixed::~Fixed( void ) { }

Fixed::Fixed( const Fixed &fixed ) {
	*this = fixed;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	if (this != &fixed) {
		this->rawBits = fixed.rawBits;
		this->fractionalBits = fixed.fractionalBits;
	}
	return *this;
}

bool Fixed::operator>( const Fixed &fixed ) const {
	return this->rawBits > fixed.rawBits;
}

bool Fixed::operator<( const Fixed &fixed ) const {
	return this->rawBits < fixed.rawBits;
}

bool Fixed::operator>=( const Fixed &fixed ) const {
	return this->rawBits >= fixed.rawBits;
}

bool Fixed::operator<=( const Fixed &fixed ) const {
	return this->rawBits <= fixed.rawBits;
}

bool Fixed::operator==( const Fixed &fixed ) const {
	return this->rawBits == fixed.rawBits;
}

bool Fixed::operator!=( const Fixed &fixed ) const {
	return this->rawBits != fixed.rawBits;
}

Fixed Fixed::operator+( const Fixed &fixed ) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-( const Fixed &fixed ) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*( const Fixed &fixed ) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/( const Fixed &fixed ) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++( void ) {
	this->rawBits++;
	return (*this);
}

Fixed &Fixed::operator--( void ) {
	this->rawBits--;
	return (*this);
}

Fixed Fixed::operator++( int ) {
	Fixed tmp(*this);

	this->rawBits++;
	return (tmp);
}

Fixed Fixed::operator--( int ) {
	Fixed tmp(*this);

	this->rawBits--;
	return (tmp);
}

Fixed Fixed::operator-( void ) {
	Fixed tmp(*this);

	return (tmp * Fixed(-1));
}

Fixed &Fixed::max( Fixed &a, Fixed &b ) {
	if (a >= b)
		return a;
	return b;
}

const Fixed &Fixed::max( const Fixed &a, const Fixed &b ) {
	if (a >= b)
		return a;
	return b;
}

Fixed &Fixed::min( Fixed &a, Fixed &b ) {
	if (a <= b)
		return a;
	return b;
}

const Fixed &Fixed::min( const Fixed &a, const Fixed &b ) {
	if (a <= b)
		return a;
	return b;
}

const Fixed Fixed::absF( const Fixed &a ) {
	Fixed tmp(a);

	if (tmp < 0)
		return -tmp;
	return tmp;
}

int Fixed::getRawBits( void ) const {
	return this->rawBits;
}

void Fixed::setRawBits( int const rawBits ) {
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
