#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int main(int argc, char *argv[]) {
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

		std::cout << "vector compare cnt: " << pmergeme.getVCnt() << std::endl;
		std::cout << "list   compare cnt: " << pmergeme.getLCnt() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
