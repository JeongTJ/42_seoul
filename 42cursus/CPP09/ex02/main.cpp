#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

void f() {system("leaks `PmergeMe");}

void test(int argc, char *argv[]) {
	try {
		clock_t start;
		clock_t end;
		double elapsed;

		PmergeMe pmergeme(argc - 1, argv + 1);
		start = clock();
		pmergeme.merge(pmergeme.getVector());
		end = clock();
		pmergeme.printVector();
		elapsed = static_cast<double>(end - start);
		std::cout << "Time to process a range of " << pmergeme.getVector().size() << " elements with std::vector : " << elapsed << " us" << std::endl;


		start = clock();
		pmergeme.merge(pmergeme.getList());
		end = clock();
		elapsed = static_cast<double>(end - start);
		std::cout << "Time to process a range of " << pmergeme.getVector().size() << " elements with std::list : " << elapsed << " us" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main(int argc, char *argv[]) {
	test(argc, argv);
	while (1)
		;
	return 0;
}