#include "vector_a.hpp"

/*
 * Swap two elements in a vector.
 */
template <typename T>
inline void swap_(vector<T> v, index_t m, index_t n) {
  auto t = v[m];
  v[m] = v[n];
  v[n] = t;
}

template <typename T>
index_t partition(vector<T> v, index_t lo, index_t hi) {
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

template <typename T>
T trivialMedian(vector<T>& s1, int lo1, int n1, 
                vector<T>& s2, int lo2, int n2) {
  int hi1 = lo1 + n1, hi2 = lo2 + n2;
  vector<T> res;
  while ((lo1 < hi1) && (lo2 < hi2)) {
    while ((lo1 < hi1) && (s1[lo1] <= s2[lo2])) res.insert([s1[lo1++]]);
    while ((lo2 < hi2) && (s1[lo1] >= s2[lo2])) res.insert([s2[lo2++]]);
  }
  while (lo1 < hi1) res.insert(s1[lo1++]);
  while (lo2 < hi2) res.insert(s2[lo2++]);
  return res[(n1 + n2) / 2];
}

template <typename T>
T median(vecotr<T>& s1, index_t lo1, int n1, vector<T>& s2, int lo2, int n2) {
  // recursive implementation
  if (n1 > n2) return median(s2, lo2, n2, s1, lo1, n1);
  if (n2 < 6) return trivialMedian(s1, lo1, n1, s2, lo2, n2);
  if (2 * n1 < n2) return median(s1, lo1, n1, s2, lo2 + (n2 - n1 - 1) / 2,
                                 n1 + 2 - (n2 - n1) % 2);
  int mi1 = lo1 + n1 / 2;
  int mi2a = lo2 + (n1 - 1 ) / 2;
  int mi2b = lo2 + n2 - 1 - n1 / 2;
  if (s1[mi1] > s2[mi2a]) return median(s1, lo1, n1 / 2 + 1,
                                        s2, mi2a, n2 - (21 - 1) / 2);
  else if (s1[mi1] < s2[mi2a]) {
    // TODO
  }

}
