#include "PmergeMe.hpp"
#include <sstream>
#include <ctime>

int main(int argc, char *argv[]) {
	std::vector<unsigned int> v;
	clock_t start;
	clock_t end;
	double elapsed;
	for (int i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		long long item;

		if (iss >> item && iss.eof() && item >= 0) {
			v.push_back(item);
		} else {
			return 1;
		}
	}
	PmergeMe pmergeme(v);

	start = clock();
	pmergeme.v_sorting();
	end = clock();
	elapsed = static_cast<double>(end - start);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << elapsed << " us" << std::endl;

	start = clock();
	pmergeme.l_sorting();
	end = clock();
	elapsed = static_cast<double>(end - start);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << elapsed << " us" << std::endl;

	std::cout << pmergeme.get_v_compare() << '\n';
	std::cout << pmergeme.get_l_compare() << '\n';
	return 0;
}