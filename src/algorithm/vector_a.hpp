#ifndef VECTOR_A_HPP_
#define VECTOR_A_HPP_

#include <vector>

using namespace std;

typedef int index_t;

/*
 * Partition algorithm for vector.
 */
template <typename T>
index_t partition(vector<T>& v, index_t lo, index_t hi);

/*
 * Median.
 * 
 * Given two ordered vector, return median of their
 * combination.
 *
 */
template <typename T>
T median(vector<T>& s1, index_t lo1, int n1, vector<T>& s2, int lo2, int n2);

#endif
