#include "LiteralTypeDetecter.hpp"
#include <sstream>

bool LiteralTypeDetecter::isChar(const std::string& literal) {
	std::istringstream iss(literal);
	char c;
	return (iss >> c) && !std::isdigit(c) && !(iss >> c);
}

bool LiteralTypeDetecter::isInt(const std::string& literal) {
	std::istringstream iss(literal);
	int i;
	return (iss >> i) && (iss.eof());
}

#include <iostream>

bool LiteralTypeDetecter::isFloat(const std::string& literal) {
	std::istringstream iss;
	if (*(literal.end() - 1) == 'f')
		iss.str(literal.substr(0, literal.size() - 1));
	else
		return false;
	float f;
	return (iss >> f) && (iss.eof());
}

bool LiteralTypeDetecter::isDouble(const std::string& literal) {
	std::istringstream iss(literal);
	double d;
	return (iss >> d) && (iss.eof());
}

Type LiteralTypeDetecter::getLiteralType(const std::string& literal) {
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return ERROR;
}
