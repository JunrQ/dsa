#include "stack.hpp"

#include <iostream>

using namespace dsa;

int main() {
  Stack<int> s;

  s.push(2);
  s.push(5);

  std::cout << s;

  int p;
  p = s.pop();

  std::cout << "pop: " << p << " stack: " << s;

  std::cout << "size: " << s.size() << std::endl;

}


