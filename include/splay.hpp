/*
 * Splay Tree.
 */
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

template <typename T> inline
void attachAsLChild(T p, T lc) {
  p->lc = lc;
  if (lc) lc->parent = p;
}

template <typename T> inline
void attachAsRChild(T p, T rc) {
  p->rc = rc;
  if (rc) rc->parent = p;
}

template <typename T>
BinNode<T>* Splay<T>::splay(BinNode<T>* v) {
  if (!v) return nullptr;
  BinNode<T>* p;
  BinNode<T>* g;
  while ((p = v->parent) && (g = p->parent)) {
    BinNode<T>* gg = g->parent;
    if (IsLChild(*v)) {
      if (IsLChild(*p)) { // zig-zig
        attachAsLChild(g, p->rc);
        attachAsLChild(p, v->rc);
        attachAsRChild(p, g);
        attachAsRChild(v, p);
      } else { // zig-zag
        attachAsLChild(p, v->rc);
        attachAsRChild(p, v->rc);
        attachAsLChild(v, g);
        attachAsRChild(v, p);
      }
    } else {
      if () // TODO
    }
  }
  

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



