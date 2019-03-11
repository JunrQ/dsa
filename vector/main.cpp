#include "vector.cpp"

#include <iostream>

using namespace dsa;

int main() {
  int data[] = {1, 5, 6, 2, 3, 5, 68, 23, 2, 52, 42, 18, 9, 20};
  Vector<int> v1(data, 14);
  std::cout << v1;

  v1.mergesort(0, 14);
  std::cout << "Merge sort: " << v1;

  v1.shuffle();
  std::cout << "Shuffle: " << v1;

  v1.heapsort();
  std::cout << "Heap Sort: " << v1;

  v1.shuffle();
  std::cout << "Shuffle: " << v1;

  v1.quicksort();
  std::cout << "quicksort Sort: " << v1;

  v1.shuffle();
  std::cout << "Shuffle: " << v1;







  return 0;
}