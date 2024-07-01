#include "Point.hpp"

Point::Point( void ) {
	this->x = 0;
	this->y = 0;
}

Point::Point( Fixed x, Fixed y ) {
	this->x = x;
	this->y = y;
}

Point::~Point( void ) { }

Point::Point( const Point &point ) {
	*this = point;
}

Point &Point::operator=( const Point &rValue ) {
	if (this != &rValue) {
		this->x = rValue.x;
		this->y = rValue.y;
	}
	return *this;
}

const Fixed &Point::getX( void ) const {
	return (this->x);
}

const Fixed &Point::getY( void ) const {
	return (this->y);
}

