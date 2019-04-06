
#include "bin_tree.hpp"
#include <algorithm>

namespace dsa {

template <typename T>
BinNode<T>* BinNode<T>::insertAsLC(T const& e) {
  return lc = new BinNode(e, this);
}

template <typename T>
BinNode<T>* BinNode<T>::insertAsRC(T const& e) {
  return rc = new BinNode(e, this);
}

template <typename T>
BinNode<T>* BinNode<T>::succ() {
  BinNode* s = this;
  if (rc) {
    // right subtree
    s = rc;
    while (s->hasLChild()) s = s->lc;
  } else {
    // has no right child, so succ should
    // be the lowest left subtree
    while (s->isRChild()) s = s->parent;
    s = s->parent;
  }
  return s;
}

template <typename T>
int BinTree<T>::updateHeight(BinNode<T>* x) {
  int lc_height = x->lc ? x->lc->height : 0;
  int rc_height = x->rc ? x->rc->height : 0;
  return x->height = 1 + max(lc_height, rc_height);
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNode<T>* x) {
  while (x) {
    updateHeight(x);
    x = x->parent;
  }
}

template <typename T>
BinNode<T>* BinTree<T>::insertAsRoot(T const& e) {
  _size = 1;
  return _root = new BinNode<T>(e);
}

template <typename T>
BinNode<T>* BinTree<T>::insertAsLC(BinNode<T>* x, T const& e) {
  _size++;
  x->insertAsLC(e);
  updateHeightAbove(x);
  return x->lc;
}

template <typename T>
BinNode<T>* BinTree<T>::insertAsRC(BinNode<T>* x, T const& e) {
  _size++;
  x->insertAsRC(e);
  updateHeightAbove(x);
  return x->lc;
}

template <typename T>
BinNode<T>* BinTree<T>::attachAsLC(BinNode<T>* x, BinTree* &S) {
  if (x->lc = S->_root) x->lc->parent = x; // if S->_root is nullptr
  _size += S->_size;
  updateHeightAbove(x);
  S->_root = nullptr;
  S->_size = 0;
  // TODO release, delete S
  S = nullptr;
  return x;
}

template <typename T>
BinNode<T>* BinTree<T>::attachAsRC(BinNode<T>* x, BinTree* &S) {
  if (x->rc = S->_root) x->rc->parent = x; // if S->_root is nullptr
  _size += S->_size;
  updateHeightAbove(x);
  S->_root = nullptr;
  S->_size = 0;
  // TODO release, delete S
  S = nullptr;
  return x;
}

template <typename T>
int BinTree<T>::remove(BinNode<T>* x) {
  x->fromParentTo() = nullptr;
  updateHeightAbove(x->parent);
  int n = removeAt(x);
  _size -= n;
  return n;
}

// non member
template <typename T>
static int removeAt(BinNode<T>* x) {
  if (!x) return 0; //recursive base
  int n = 1 + removeAt(x->lc) + removeAt(x_rc);
  // TODO release data
  delete x;
  x = nullptr;
  return n;
}

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNode<T>* x) {
  x->fromParentTo() = nullptr;
  updateHeightAbove(x->parent);
  BinTree* S = new BinTree;
  S->_root = x;
  x->parent = nullptr;
  S->_size = x->size();
  _size = S->_size;
  return S;
}





} // namespace dsa