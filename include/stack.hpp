#include "vector.hpp"

namespace dsa {

template <typename T>
class Stack : public Vector<T> {

public:
  void push(T const& e) { Vector<T>::insert( Vector<T>::size(), e); }
  T pop() { return Vector<T>::remove( Vector<T>::size() - 1 ); }
  T& top() { return (*this)[Vector<T>::size() - 1]; }
  bool empty() { return (Vector<T>::size() == 0); }
};

}
