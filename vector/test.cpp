#include "vector.cpp"

#include <iostream>

using namespace dsa;

int main() {
  int data[] = {1, 5, 6, 2, 3, 5, 68, 23, 2, 52, 42, 18, 9, 20};
  Vector<int> v1(data, 14);
  std::cout << v1;

  int size = v1.size();
  v1.mergesort(0, size);
  std::cout << "Merge sort: " << v1;

  v1.insert(4, 52);
  std::cout << "Insert 12 at 4th " << v1;

  v1.shuffle();
  std::cout << "Shuffle: " << v1;

  v1.heapsort();
  std::cout << "Heap Sort: " << v1;

  v1.remove(5, 8);
  std::cout << "remove (5, 8) " << v1;

  v1.shuffle();
  std::cout << "Shuffle: " << v1;

  v1.quicksort();
  std::cout << "quicksort Sort: " << v1;

  v1.push_back(18);
  std::cout << "push back 18 " << v1;

  v1.deduplicate();
  std::cout << "deduplicate " << v1;

  v1.shuffle();
  std::cout << "Shuffle: " << v1;

  v1.bubblesort();
  std::cout << "Bubble sort" << v1;
  
  v1.shuffle();
  std::cout << "Shuffle: " << v1;

  size = v1.size();
  v1.bubblesort_v1(0, size - 1);
  std::cout << "Bubble sort v1 " << v1;

  v1.shuffle();
  std::cout << "Shuffle: " << v1;

  v1.traverse([](int& x) {x += 1;});
  std::cout << "traverse += 1 " << v1;

  v1.push_back(21);
  v1.push_back(43);
  v1.push_back(4);
  v1.quicksort();
  std::cout << "push 21, 43, 4 and quick sort " << v1;

  v1.ordered_uniquify();
  std::cout << "ordered uniquify " << v1;

  return 0;
}