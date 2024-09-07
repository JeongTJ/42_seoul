#include "whatever.hpp"
#include <iostream>
#include <string>

class Dummy {
	public:
		Dummy(void): y(0), x(0) { }
		Dummy(int y, int x): y(y), x(x) { }
		~Dummy() { }
		int getY() const { return y; }
		int getX() const { return x; }
		int getScalar() const { return abs(y + x); }

		bool operator==(const Dummy& other) const {
			return this->getScalar() == other.getScalar();
		}
		bool operator<(const Dummy& other) const {
			return this->getScalar() < other.getScalar();
		}
		bool operator>(const Dummy& other) const {
			return this->getScalar() > other.getScalar();
		}
		bool operator<=(const Dummy& other) const {
			return this->getScalar() <= other.getScalar();
		}
		bool operator>=(const Dummy& other) const {
			return this->getScalar() >= other.getScalar();
		}
	private:
		int y;
		int x;
};

std::ostream& operator<<(std::ostream& os, Dummy& dummy) {
	os << dummy.getY() << " " << dummy.getX();
	return os;
}

int main() {
	{
		int a, b;
		std::cout << "input the int value a: ";
		std::cin >> a;
		std::cout << "input the int value b: ";
		std::cin >> b;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		::swap(a, b);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "min(a, b) is " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) is " << ::max(a, b) << std::endl;
	}
	{
		double a, b;
		std::cout << "input the double value a: ";
		std::cin >> a;
		std::cout << "input the double value b: ";
		std::cin >> b;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		::swap(a, b);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "min(a, b) is " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) is " << ::max(a, b) << std::endl;
	}
	{
		std::string a, b;
		std::cout << "input the string value a: ";
		std::cin >> a;
		std::cout << "input the string value b: ";
		std::cin >> b;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		::swap(a, b);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "min(a, b) is " << ::min(a, b) << std::endl;
		std::cout << "max(a, b) is " << ::max(a, b) << std::endl;
	}
	{
		Dummy a(1, 2), b(3, 4);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		swap(a, b);
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "min(a, b) is " << min(a, b) << std::endl;
		std::cout << "max(a, b) is " << max(a, b) << std::endl;
	}
}
