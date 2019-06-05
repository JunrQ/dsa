#include "btree.hpp"

namespace dsa {


template <typename T>
BTNode<T>* BTree<T>::search(const T& e) {
  BTNode<T>* v = _root;
  _hot = nullptr;
  while (v) {
    int r = v->key.binary_search(e);
    if ((0 <= r) && (e == v->key[r])) return v;
    _hot = v;
    v = v->child[r+1];
  }
  return nullptr;
}

template <typename T>
bool BTree<T>::insert(const T& e) {
  BTNode<T>* v = search(e);
  if (v) return false;
  int r = _hot->key.binary_search(e);
  _hot->key.insert(r + 1, e);
  _hot->child.insert(r + 2, nullptr);
  _size++;
  solveOverflow(_hot);
  return true;
}

template <typename T>
void BTree<T>::solveOverflow(BTNode<T>* v) {
  // recursive base
  if (_order >= v->child.size()) return;
  // half
  int s = _order / 2;
  BTNode<T>* u = new BTNode<T>();
  // insert
  for (int j = 0; j < _order - s - 1; j++) {
    u->child.insert(j, v->child.remove(s + 1)); // TODO inefficient
    u->key.insert(j, v->key.remove(s + 1));
  }
  u->child[_order - s - 1] = v->child.remove(s + 1);
  // make u's children point to u
  if (u->child[0]) {
    for (int j = 0; j < _order - s; j++) {
      u->child[j]->parent = u;
    }
  }
  BTNode<T>* p = v->parent;
  // if v is root, make a new root
  if (!p) {
    _root = p = new BTNode<T>();
    p->child[0] = v;
    v->parent = p;
  }
  int r = 1 + p->key.binary_search(v->key[0]);
  p->key.insert(r, v->key.remove(s));
  p->child.insert(r + 1, u);
  u->parent = p;
  solveOverflow(p);
}

template <typename T>
bool BTree<T>::remove(const T& e) {
  BTNode<T>* v = search(e);
  if (!v) return false;
  int r = v->key.binary_search(e);
  // find succ
  if (v->child[0]) {
    BTNode<T>* u = v->child[r + 1];
    while (u->child[0]) u = u->child[0];
    v->key[r] = u->key[0];
    v = u;
    r = 0;
  }
  v->key.remove(r);
  v->child.remove(r + 1);
  _size--;
  solveUnderflow(v);
  return true;
}

// TODO solveUnderflow

}