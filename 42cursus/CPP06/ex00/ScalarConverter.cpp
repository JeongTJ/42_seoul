#include "ScalarConverter.hpp"
#include "LiteralTypeDetecter.hpp"
#include <iostream>
#include <sstream>
#include <limits>

void ScalarConverter::convert(const std::string& literal) {
	std::istringstream iss;
	switch(LiteralTypeDetecter::getLiteralType(literal)) {
		case CHAR:
			char c;
			iss.str(literal);
			iss >> c;
			std::cout << "char: " << "'" << c << "'" << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
			break ;
		case INT:
			int i;
			iss.str(literal);
			iss >> i;
			if (040 <= i && i <= 0176)
				std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
			else if (-128 <= i && i <= 127)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
			break ;
		case FLOAT:
			float f;
			iss.str(literal.substr(0, literal.size() - 1));
			iss >> f;
			if (040 <= f && f <= 0176)
				std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
			else if (-128 <= f && f <= 127)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "impossible" << std::endl;
			if (-2148364748 <= f && f <= 2147483647)
				std::cout << "int: " << static_cast<int>(f) << std::endl;
			else
				std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(f) << std::endl;
			break ;
		case DOUBLE:
			double d;
			iss.str(literal);
			iss >> d;
			if (040 <= d && d <= 0176)
				std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
			else if (-128 <= d && d <= 127)
				std::cout << "char: " << "Non displayable" << std::endl;
			else
				std::cout << "char: " << "impossible" << std::endl;

			if (-2148364748 <= d && d <= 2147483647)
				std::cout << "int: " << static_cast<int>(d) << std::endl;
			else
				std::cout << "int: " << "impossible" << std::endl;

			if (std::numeric_limits<float>::min() <= d && d <= std::numeric_limits<float>::max())
				std::cout << "float: " << static_cast<float>(d) << std::endl;
			else if (d < std::numeric_limits<float>::min())
				std::cout << "float: " << "-inff" << std::endl;
			else if (std::numeric_limits<float>::max() < d)
				std::cout << "float: " << "+inff" << std::endl;
			else
				std::cout << "float: " << "nan" << std::endl;
			std::cout << "double: " << d << std::endl;
			break ;
		default:
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: " << "nanf" << std::endl;
			std::cout << "double: " << "nan" << std::endl;
			break ;
	}
}
