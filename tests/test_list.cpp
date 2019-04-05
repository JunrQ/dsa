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

  l1.insertAsFirst(55);
  l1.insertAsLast(2);
  std::cout << "insert 55 as 1st, 2 as last: " << l1;

  l1.insertAfter(3, 5);
  l1.insertBefore(2, 3);
  std::cout << "insert 5 as 5th, 3 as 3th: " << l1;

  


}