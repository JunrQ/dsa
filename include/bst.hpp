/*
 * 二叉搜索树
 * 二叉搜索树：中序遍历单调非降
 * 
 *
 */

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

// Not a memeber func
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
  // If no left child, we can replace x with its right child
  if (!x->hasLChild()) succ = x = x->rc;
  else if (!x->hasRChild()) succ = x = x->lc;
  else {
    // Find its succ
    w = w->succ();
    swap(x->data, w->data);
    // Remove w
    BinNode<T>* u = w->parent;
    ((u == x) ? u->rc : u -> lc) = succ = w->rc;
  }
  hot = w->parent;
  if (succ) succ->parent = hot;
  return succ;
}

template <typename T>
bool BST<T>::remove(const T& e) {
  BinNode<T>* & x = search(e);
  if (!x) return false;
  removeAt(x, _hot);
  _size--;
  updateHeight(_hot);
}

} // namespace dsa
