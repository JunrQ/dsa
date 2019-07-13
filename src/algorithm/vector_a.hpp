#ifndef VECTOR_A_HPP_
#define VECTOR_A_HPP_

#include <vector>

typedef int index_t;

/*
 * Partition algorithm for vector.
 */
template <typename T>
index_t partition(std::vector<T>& v, index_t lo, index_t hi);

#endif
