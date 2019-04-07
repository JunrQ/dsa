
#include "bst.hpp"

namespace dsa {


template <typename T> class Splay : public BST<T> {

protected:
  // splay node v to root
  BinNode<T>* splay(BinNode<T>* v);
public:
  BinNode<T>* & search(const T& e);
  BinNode<T>* insert(const T& e);
  bool remove(const T& e);
};

template <typename T>
BinNode<T>* Splay<T>::splay(BinNode<T>* v) {
  // TODO
}

template <typename T>
BinNode<T>* & Splay<T>::search(const T& e) {
  BinNode<T>* p = searchIn(_root, e, _hot=nullptr);
  _root = splay(p ? p : _hot);
  return _root;
}

// TODO insert

// TODO delete


} // namespace dsa



