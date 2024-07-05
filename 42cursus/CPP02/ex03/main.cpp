#include "Point.hpp"
#include <string>

int main( void ) {
	std::string tmp1 = "";
	std::string tmp2 = "";
	std::string result[100];
	Point a(0.25f, 0.75f), b(4.99f, 9.2f), c(0.5f, 4);

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			tmp1.append(bsp(a, b, c, Point(i / 10.0f, j / 10.0f)) ? "*" : ".");
		result[99 - i] = tmp1;
		tmp1 = "";
	}
	for (int i = 0; i < 100; i++)
		std::cout << result[i] << std::endl;
	return 0;
}
