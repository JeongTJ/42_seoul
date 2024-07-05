#pragma once
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {
	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		~Point(void);
		Point(const Point &other);
		Point &operator=(const Point &other);
		const Fixed &getX(void) const;
		const Fixed &getY(void) const;
	private:
		Fixed x;
		Fixed y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
