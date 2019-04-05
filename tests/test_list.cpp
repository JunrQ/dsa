#include "list.cpp"

#include <iostream>

using namespace dsa;

int main() {
  int data[] = {1, 5, 6, 2, 3, 5, 68, 20};
  List<int> l1;

  for (int i = 0; i < 8; i++) {
    l1.append(data[i]);
  }

  std::cout << l1;
  std::cout << "remove 1st ele: " << l1.remove(0) << " list: " << l1;

  l1.deduplicate();
  std::cout << "deduplicate: " << l1;

  l1.insertAsFirst(55);
  l1.insertAsLast(2);
  std::cout << "insert 55 as 1st, 2 as last: " << l1;

  l1.insertAfter(3, 5);
  l1.insertBefore(2, 3);
  std::cout << "insert 5 as 5th, 3 as 3th: " << l1;

  std::cout << "size: " << l1.size() << std::endl;

  l1.selectionSort();
  std::cout << "Selection sort: " << l1;

  l1.uniquify();
  std::cout << "uniquify: " << l1;

  l1.shuffle();
  std::cout << "shuffle: " << l1;

  l1.insertionSort();
  std::cout << "Insertion sort: " << l1;

  l1.shuffle();
  std::cout << "shuffle: " << l1;

  // TODO segmentation fault
  l1.mergeSort();
  std::cout << "Merge sort: " << l1;

}