#include "stack.hpp"
#include <iostream>

using namespace dsa;

int main() {
  Stack<int> s;

  s.push(10);
  s.push(24);
  
  std::cout << s << std::endl;

  s.pop();
  std::cout << s << std::endl;

  std::cout << s.size() << std::endl;
  std::cout << s.top() << std::endl;

  std::cout << s.empty() << std::endl;

}