#pragma once
#ifndef LITERALTYPEDETECTER_HPP
# define LITERALTYPEDETECTER_HPP

# include <string>

enum Type {
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	ERROR
};

class LiteralTypeDetecter {
	private:
		LiteralTypeDetecter();
		~LiteralTypeDetecter();
		LiteralTypeDetecter(const LiteralTypeDetecter& other);
		LiteralTypeDetecter& operator=(const LiteralTypeDetecter& other);
		static bool isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
	public:
		static Type getLiteralType(const std::string& literal);
};

#endif
