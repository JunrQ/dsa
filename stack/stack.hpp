#include "../vector/vector.hpp"

namespace dsa {

template <typename T>
class Stack : public Vector<T> {

public:
  Stack();
  void push(T const& e) { insert( size(), e); }
  T pop() { return remove( size() - 1 ); }
  T& top() { return (*this)[size() - 1]}
};

}



