#include "queue.hpp"

#include <iostream>

using namespace dsa;

int main() {
  Queue<int> q;

  q.enqueue(2);
  q.enqueue(5);

  std::cout << q;

  int p;
  p = q.dequeue();

  std::cout << "dequeue: " << p << " queue: " << q;

  std::cout << "size: " << q.size() << std::endl;

  std::cout << "front: " << q.front() << std::endl;

}


