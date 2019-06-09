/*
 * B树
 * m阶B树，即m阶平衡搜索树，每个内部节点都存有不超过m-1个关键码，以及用以指示
 * 对应分支的不超过m个引用, 除根以外的所有内部节点，都应满足：n+1 >= ceil(m / 2)
 * 
 */

#include "vector.hpp"

namespace dsa {
// B-Tree Node struct
template <typename T> struct BTNode {
  BTNode* parent;
  Vector<T> key;
  Vector<BTNode*> child;

  BTNode() {parent=nullptr; child.insert(0, nullptr);}
  BTNode(T e, BTNode* lc=nullptr, BTNode* rc=nullptr) {
    parent = nullptr;
    key.insert(0, e);
    child.insert(0, lc);
    child.insert(1, rc);
    if (lc) lc->parent = this;
    if (rc) rc->parent = this;
  }
};

template <typename T> class BTree {
protected:
  int _size; // number of keys
  int _order; // order, as least 3
  BTNode<T>* _;
  BTNode<T>* _hot;
  void solveOverflow(BTNode<T>*);
  void solveUnderflow(BTNode<T>*);
public:
  BTree(int order=3) : _order(order), _size(0) {
    _root = new BTNode<T>();
  }

  ~BTree() {
    if (_root) {
      delete _root;
      _root = nullptr;
    }
  }

  int const order() {return _order;}
  int const size() {return _size;}
  BTNode<T>* & root() {return _root;}
  bool empty() const {return !_root;}
  BTNode<T>* search(const T& e);
  bool insert(const T& e);
  bool remove(const T& e);

};

template <typename T>
BTNode<T>* BTree<T>::search(const T& e) {
  BTNode<T>* v = _root;
  _hot = nullptr;
  while (v) {
    int r = v->key.search(e);
    if ((0 <= r) && (e == v->key[r])) return v;
    _hot = v;
    v = v->child[r + 1];
  }
  return nullptr;
}

template <typename T>
bool BTree<T>::insert(const T& e) {
  BTNode<T>* v = search(e);
  if (v) return false;
  int r = _hot->key.search(e);
  _hot->key.insert(r + 1, e);
  _hot->child.insert(r + 2, nullptr);
  _size++;
  solveOverflow(_hot);
  return true;
}

template <typename T>
void BTree<T>::solveOverflow(BTNode<T>* v) {
  if (_order >= v->child.size()) return;
  int s = _order / 2;
  BTNode<T>* u = new BTNode<T>();
  for (int j = 0; j < _order - s - 1; j++) {
    u->child.insert(j, v->child.remove(s + 1));
    u->key.insert(j, v->key.remove(s + 1));
  }
  u->child[_order - s - 1] = v->child.remove(s + 1);
  if (u->child[0]) {
    for (int j = 0; j < _order; j++) {
      u->child[j]->parent = u;
    }
  }

  BTNode<T>* p = v->parent;
  if (!p) {
    _root = p = new BTNode<T>();
    p->child[0] = v;
    v->parent = p;
  }

  int r = 1 + p->key.search(v->key[0]);
  p->key.insert(r, v->key.remove(s));
  p->child.insert(r + 1, u);
  u->parent = p;
  solveOverflow(p);
}



} // namespace dsa


