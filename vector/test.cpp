#include "vector.hpp"
#include <iostream>

using namespace dsa;

int main() {
  int data[] = {1, 5, 6, 2, 3, 5, 68, 23, 2, 52, 42, 18, 9, 20};
  Vector<int> v1(data, 14);

  std::cout << v1;
}