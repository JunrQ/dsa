#include <vector>
#include <iostream>

#include "vector_a.hpp"

int main(int argc, char** argv) {
	std::vector<int> test_0 = {73, 0, 21, -2, 3, 14, 5};

	index_t r = 0, lo=0, hi=7;
	r = partition(test_0, lo, hi);

	for (auto it = test_0.begin(); it != test_0.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;	
}


