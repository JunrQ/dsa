#include "list.cpp"

using namespace dsa;

template <typename T>
class Queue : public List<T> {

public:
  bool empty() {return this->size() == 0;}
  void enqueue(const T& e) {this->append(e);}
  T dequeue() {return this->remove(this->first());}
  T& front() {return this->first()->data;}ss
};
