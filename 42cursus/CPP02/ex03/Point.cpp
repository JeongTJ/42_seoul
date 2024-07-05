#include "Point.hpp"

Point::Point(void): x(0), y(0) { }

Point::Point( Fixed x, Fixed y ): x(x), y(y) { }

Point::~Point( void ) { }

Point::Point( const Point &other ): x(other.x), y(other.y) { }

Point &Point::operator=( const Point &other ) {
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
	}
	return *this;
}

const Fixed &Point::getX(void) const {
	return (this->x);
}

const Fixed &Point::getY(void) const {
	return (this->y);
}

