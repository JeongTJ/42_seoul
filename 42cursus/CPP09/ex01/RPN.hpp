#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>

class RPN {
	public:
		class ErrorException: public std::exception {
			public:
				ErrorException(void);
				~ErrorException() throw();
				ErrorException(const ErrorException& other);
				ErrorException& operator=(const ErrorException& other);
				const char* what(void) const throw();
		};
		class DivisionByZeroException: public std::exception {
			public:
				DivisionByZeroException(void);
				~DivisionByZeroException() throw();
				DivisionByZeroException(const DivisionByZeroException& other);
				DivisionByZeroException& operator=(const DivisionByZeroException& other);
				const char* what(void) const throw();
		};
		RPN(const char* input);
		~RPN();
		long run();
	private:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		long calc(long a, long b, char oper);
		std::istringstream iss;

};



#endif
