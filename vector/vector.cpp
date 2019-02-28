#include "vector.hpp"

namespace dsa {


template <typename T>
void Vector<T>::copyFrom(T const* A, int lo, int hi) {
  if (_elem) delete [] _elem;
  _elem = new T[_capacity = 2 * (hi - lo)];
  _size = hi - lo;
  for (int s = 0; s < _size; s++) _elem[s] = A[lo + s];
}

template <typename T>
Vector<T>::Vector(int capacity, int size, T init) {
  _elem = new T[_capacity = capacity];
  _size = size;
  for (int s = 0; s < size; s++) _elem[s] = init;
}

template <typename T>
Vector<T>::Vector(T const* A, int lo, int hi) {
  copyFrom(A, lo, hi);
}

template <typename T>
const T* Vector<T>::data() {
  return _elem;
}

template <typename T>
const int size() {
  return _size;
}

template <typename T>
Vector<T>& Vector<T>::operator= (Vector<T> const& v) {
  if (_elem) delete [] _elem;
  copyFrom(v.data(), v.size());
  return *this;
}






} // namespace dsa