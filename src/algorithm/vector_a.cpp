#include "vector_a.hpp"

/*
 * Swap two elements in a vector.
 */
template <typename T>
inline void swap_(std::vector<T> v, index_t m, index_t n) {
  auto t = v[m];
  v[m] = v[n];
  v[n] = t;
}

template <typename T>
index_t partition(std::vector<T> v, index_t lo, index_t hi) {
  index_t mi = lo;
  index_t k = lo + 1;
  while (k < hi) {
    if (v[k] < v[lo]) {
      mi++;
      swap_(v, mi, k);
    }
    k++;
  }
  swap_(v, lo, mi);
  return mi;
}
