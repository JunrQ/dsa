/*
 * AVL Tree.
 * 
 */
#include "bst.hpp"

namespace dsa {

template <typename T>
bool AvlBalanced(BinNode<T>* x) {
  return (-2 < x->height) && (2 > x->height));
}

template <typename T> class AVL : public BST<T> {

public:
  BinNode<T>* insert(const T& e);
  bool remove(const T& e);
};

template <typename T>
BinNode<T>* AVL<T>::insert(const T& e) {
  BinNode<T>* & x = search(e);
  if (x) return x; // exist
  BinNode<T>* xx = x = new BinNode<T>(e, _hot);
  _size++;
  for (BinNode<T>* g = _hot; g; g = g->parent) {
    if (!AvlBalanced(g)) {
      FromParentToO(*g) = rotateAt(tallerChild(tallerChild(g)));
      break;
    } else {
      updateHeight(g);
    }
  }
  return xx;
}

} // namespace dsa
