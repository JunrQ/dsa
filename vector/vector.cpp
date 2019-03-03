#include "vector.hpp"

#include <stdlib.h>

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
  if (_size < _capacity) return;
  T* _e = new T[_capacity *= 2];
  for (int s = 0; s < _size; s++) _e[s] = _elem[s];
  delete [] _elem;
  _elem = _e;
}

template <typename T>
void Vector<T>::shrink() {
  if (_size << 2 > _capacity) return; // 25%
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
template <typename T>
void Vector<T>::max_heapify(T* array, int i, int size) {
  int l = left(i);
  int r = right(i);
  int largest;
  if (l < size && array[i] < array[l]) largest = l;
  else largest = i;
  if (r < size && array[largest] < array[r]) largest = r;
  if (largest != i) {
    exchange(array[i], array[largest]);
    max_heapify(array, largest, size);
  }
}

template <typename T>
void Vector<T>::build_max_heap(T*, int size) {
    for (int i = size / 2; i >= 0; i--)
      max_heapify(_elem, i, size);
}

template <typename T>
void Vector<T>::heapsort() {
  build_max_heap(_elem, _size);
  int s = _size;
  for (int i = _size - 1; i > 0; i++) {
    exchange(_elem[0], _elem[i]);
    max_heapify(_elem, 0, --s);
  }
}

template <typename T>
void Vector<T>::shuffle() {
  for (int i = _size; i >= 1; i++) {
    int tmp = rand() % _size;
    exchange(_elem[i], _elem[tmp]);
  }
}

template <typename T>
int Vector<T>::sequential_find(const T& key, int lo, int hi) const {
  int i = hi - lo;
  while (i >= 0) {
    if (_elem[lo + i--] == *key) return lo + i;
  }
  return i;
}

template <typename T>
int Vector<T>::binary_search(const T* key) const {
  int hi = _size - 1;
  int lo = 0;
  int mid;
  while (hi - lo > 0) {
    mid = (hi + lo) / 2;
    if (_elem[mid] > *key) {
      hi = mid - 1;
    } else {
      if (_elem[mid] == *key) return mid;
      else lo = mid + 1;
    }
  }
  return -1;
}

template <typename T>
int Vector<T>::binary_search_v1(const T& key, int lo, int hi) const {
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (key < _elem[mid]) hi = mid;
    else if (key > _elem[mid]) lo = mid + 1;
    else return mid;
  }
  return -1;
}

template <typename T>
int Vector<T>::binary_search_v2(const T& key, int lo, int hi) const {
  while (1 < hi - lo) {
    int mid = (hi + lo) >> 1;
    (key < _elem[mid]) ? hi = mid : lo = mid;
  }
  return (key == _elem[lo]) ? lo : -1;
}

template <typename T>
int Vector<T>::binary_search_v3(const T& key, int lo, int hi) const {
  while (lo < hi) {
    int mid = (hi + lo) >> 1;
    (key < _elem[mid]) ? hi = mid : lo = mid + 1;
  }
  return --lo;
}

template <typename T>
int Vector<T>::partition(T* array, int p, int r) {
  T x = array[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if (array[j] <= x) {
      exchange(array[++i], array[j]);
    }
  }
  exchange(array[i], array[r]);
}

template <typename T>
void Vector<T>::quicksort_imp(T* array, int p, int r) {
  if (p < r) {
    int q = partition(array, p, r);
    quicksort_imp(array, p, q - 1);
    quicksort_imp(array, q + 1, r);
  }
}

template <typename T>
void Vector<T>::quicksort() {
  quicksort_imp(_elem, 0, _size - 1);
}

template <typename T>
int Vector<T>::insert(int r, const T& ele) {
  expand(); // See if expand is needed
  for (int i = _size; i > r; i--) _elem[i] = _elem[i - 1];
  _elem[r] = ele;
  _size++;
  return r;
}

template <typename T>
int Vector<T>::remove(int lo, int hi) {
  if (lo == hi) return 0;
  while (hi < _size) _elem[lo++] = _elem[hi++];
  _size = lo;
  shrink();
  return (hi - lo);
}

template <typename T>
T Vector<T>::remove(int r) {
  T e = _elem[r];
  remove(r, r + 1);
  return e;
}

template <typename T>
int Vector<T>::deduplicate() {
  int s = _size;
  int r = 0;
  while (r < _size) {
    sequential_find(_elem[r] < 0) ?
      r++ : remove(_elem[r])
  }
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const Vector<T>& vec) {
  os << "size : " << vec._size << "elements: ";
  for (int i = 0; i < vec._size - 1; i++) {
    os << vec._elem[i] << " ";
  }
  os << vec._elem[vec._size - 1];
}

template <typename T>
int Vector<T>::disordered() const {
  int n = 0;
  for (int i = 1; i < _size; i++) {
    if (_elem[i - 1] > _elem[i]) n++;
  }
  return n;
}

template <typename T>
int Vector<T>::ordered_uniquify_v1() {
  int s = _size;
  int i = 0;
  while (i < _size) { /* remove is time consuming */
    (_elem[i] == _elem[i + 1]) ? remove(i + 1) : i++;
  }
  return s - _size;
}

template <typename T>
int Vector<T>::ordered_uniquify() {
  int i = 0, j = 0;
  while (++j < _size) {
    if (_elem[i] != _elem[j]) _elem[++i] = _elem[j];
  }
  _size = ++i;
  shrink();
  return j - i;
}






} // namespace dsa
