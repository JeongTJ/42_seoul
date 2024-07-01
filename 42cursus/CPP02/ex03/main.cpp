#include "Point.hpp"
#include <string>

int main( void ) {
	std::string tmp1 = "";
	std::string tmp2 = "";
	std::string result = "";
	Point a(0.25f, 0.75f), b(4.99f, 9.2f), c(0.5f, 4);

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			tmp1.append(bsp(a, b, c, Point(i / 10.0f, j / 10.0f)) ? "*" : ".");
		tmp2.append(tmp1);
		tmp2.append("\n");
		tmp2.append(result);
		result = tmp2;
		tmp2 = "";
		tmp1 = "";
	}
	std::cout << result;
	return 0;
}
