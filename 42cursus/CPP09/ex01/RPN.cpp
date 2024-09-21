#include "RPN.hpp"
#include <sstream>
#include <iostream>

RPN::RPN(const char* input) {
	// iss = std::istringstream(std::string(input));
	iss.str(std::string(input));
}

RPN::~RPN() {

}

long RPN::run() {
	std::stack<long> stack;
	std::string oper("+-*/");

	char c, empty;
	long a, b;
	while (1) {
		if (!(iss.get(c)))
			break ;
		if ('0' <= c && c <= '9') {
			stack.push(c - '0');
		} else if (oper.find(c) != std::string::npos){
			if (stack.empty())
				throw ErrorException();
			b = stack.top();
			stack.pop();
			if (stack.empty())
				throw ErrorException();
			a = stack.top();
			stack.pop();
			stack.push(calc(a, b, c));
		} else
			throw ErrorException();
		if (!(iss.get(empty)))
			break ;
		if (empty != ' ')
			throw ErrorException();
	}
	if (stack.size() != 1)
		throw ErrorException();
	return stack.top();
}

long RPN::calc(long a, long b, char oper) {
	if (oper == '+')
		return a + b;
	if (oper == '-')
		return a - b;
	if (oper == '*')
		return a * b;
	if (b == 0)
		throw DivisionByZeroException();
	return a / b;
}

/* ************** */
/* ErrorException */
/* ************** */

RPN::ErrorException::ErrorException(void) {

}

RPN::ErrorException::~ErrorException() throw() {

}

RPN::ErrorException::ErrorException(const ErrorException& other): std::exception(other) {

}

RPN::ErrorException& RPN::ErrorException::operator=(const ErrorException& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* RPN::ErrorException::what(void) const throw() {
	return "Error";
}

/* *********************** */
/* DivisionByZeroException */
/* *********************** */

RPN::DivisionByZeroException::DivisionByZeroException(void) {

}

RPN::DivisionByZeroException::~DivisionByZeroException() throw() {

}

RPN::DivisionByZeroException::DivisionByZeroException(const DivisionByZeroException& other): std::exception(other) {

}

RPN::DivisionByZeroException& RPN::DivisionByZeroException::operator=(const DivisionByZeroException& other) {
	if (this == &other)
		return *this;
	return *this;
}

const char* RPN::DivisionByZeroException::what(void) const throw() {
	return "RPN::DivisionByZeroException";
}
