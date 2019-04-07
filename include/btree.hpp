

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
  BTNode<T>* _root;
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



} // namespace dsa


