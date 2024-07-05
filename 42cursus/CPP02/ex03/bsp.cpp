#include "Point.hpp"

/**
 * | x1 x2 x3 x1 |
 * | y1 y2 y3 y1 |
 *
 * area = 0.5 * |x1 y2 + x2 y3 + x3 y1 - y1 x2 - y2 x3 - y3 x1|
*/
Fixed triangleArea( const Point &p1, const Point &p2, const Point &p3 ) {
	return Fixed(0.5f) * \
	Fixed::absF((p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY()) - \
	(p1.getY() * p2.getX() + p2.getY() * p3.getX() + p3.getY() * p1.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed abc, abp, bcp, cap;

	abc = triangleArea(a, b, c);
	abp = triangleArea(a, b, point);
	bcp = triangleArea(b, c, point);
	cap = triangleArea(c, a, point);
	return (abc / (abp + bcp + cap) >= 1);
}
