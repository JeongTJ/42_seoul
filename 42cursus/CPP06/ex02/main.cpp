#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ex02.hpp"

int main() {
	Base* tmp;

	tmp = generate();
	identify(tmp);
	identify(*tmp);
}