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
Vector<T>::Vector() {
  _elem = nullptr;
  _capacity = 0;
  _size = 0;
}

template <typename T>
T* const Vector<T>::data() const {
  return _elem;
}

template <typename T>
int Vector<T>::size() const {
  return _size;
}

template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& v) {
  if (_elem) delete [] _elem;
  copyFrom(v.data(), v.size());
  return *this;
}

template <typename T>
T& Vector<T>::operator[] (int idx) {
  return _elem[idx];
}

template <typename T>
inline int Vector<T>::capacity() const {
  return _capacity;
}

template <typename T>
Vector<T>::~Vector() {
  if (_elem) delete [] _elem;
}

template <typename T>
void Vector<T>::expand() {
  T* _e = new T[_capacity *= 2];
  for (int s = 0; s < _size; s++) _e[s] = _elem[s];
  delete [] _elem;
  _elem = _e;
}

template <typename T>
void Vector<T>::shrink() {
  T* _e = new T[_size];
  for (int s = 0; s < _size; s++) _e[s] = _elem[s];
  delete [] _elem;
  _elem = _e;
  _capacity = _size;
}

template <typename T>
void Vector<T>::reserve(unsigned int n) {
  if (_elem) {
    int s = _size > n ? n : _size;
    T* _e = new T[n];
    _capacity = n;
    for (int i = 0; i < s; i++) _e[i] = _elem[i];
    delete [] _elem;
    _elem = _e;
  }
  else {
    _elem = new T[n];
    _capacity = n;
    _size = 0;
  }
}


template <typename T>
void Vector<T>::push_back(const T& ele) {
  if (_size == _capacity) expand();
  _elem[++_size] = ele;
}

// Sort algorithms









} // namespace dsa