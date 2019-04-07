
#include "bin_tree.hpp"

namespace dsa {

template <typename K, typename V> struct Entry {
  K key;
  V value;
  Entry(K k=K(), V v=V()) : key(k), value(v) {}
  Entry(Entry const& e) : key(e.key), value(e.value) {}
  bool operator< (Entry const& e) {return key < e.key;}
  bool operator> (Entry const& e) {return key > e.key;}
  bool operator== (Entry const& e) {return key == e.key;}
  bool operator!= (Entry const& e) {return key != e.key;}
};

template <typename T> class BST : public BinTree<T> {
protected:
  BinNode<T>* _hot;
  BinNode<T>* connect34(BinNode<T>*, BinNode<T>*, BinNode<T>*,
                        BinNode<T>*, BinNode<T>*, BinNode<T>*, BinNode<T>*);
  BinNode<T>* rotateAt(BinNode<T>* x);
public:
  virtual BinNode<T>* & search(const T& e);
  virtual BinNode<T>* insert(const T& e);
  virtual bool remove(const T& e);
};

template <typename T>
static BinNode<T>* & searchIn(BinNode<T>* & v, const T& e, BinNode<T>& hot) {
  if (!v || (e == v->data)) return v;
  hot = v;
  return searchIn(((e < v->data)? v->lc : v->rc), e, hot);
}

template <typename T>
BinNode<T>* & BST<T>::search(const T& e) {
  return searchIn(_root, e, _hot=nullptr);
}

template <typename T>
BinNode<T>* BST<T>::insert(const T& e) {
  BinNode<T>* & x = search(e);
  if (x) return x;
  x = new BinNode<T>(e, _hot);
  _size++;
  updateHeightAbove(x);
  return x;
}

template <typename T>
static BinNode<T>* removeAt(BinNode<T>* & x, BinNode<T>& hot) {
  BinNode<T>* w = x;
  BinNode<T>* succ = nullptr;
  if (!x->hasLChild()) succ = x = x->rc;
  else if (!x->hasRChild()) succ = x = x->lc;
  else {
    w = w->succ();
    //
    // TODO
  }
}




} // namespace dsa





