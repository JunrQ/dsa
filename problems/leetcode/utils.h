
#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <algorithm>

using namespace std;

/**
 * \brief Print std::vector<int>
 */
void printIntVector(vector<int>& input) {
    for (int i = 0; i < input.size(); ++i) {
        printf("%d ", input[i]);
    }
}


/**
 * \brief argsort, like numpy.argsort
 */
template<typename T>
vector<int> argsort(const vector<T>& array) {
	const int array_len(array.size());
	vector<int> array_index(array_len, 0);
	for (int i = 0; i < array_len; ++i)
		array_index[i] = i;

	sort(array_index.begin(), array_index.end(),
		[&array](int pos1, int pos2) {return (array[pos1] < array[pos2]);});

	return array_index;
}





#endif
