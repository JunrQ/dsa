

namespace  dsa {

// BinNode
template <typename T>
struct BinNode {
  T data;
  BinNode* parent;
  BinNode* lc; // left child
  BinNode* rc; // right child

  int height;
  int npl; // Null Path Length

  typedef enum {
    RB_RED,
    RB_BLCK
  } RBColor;
  RBColor color;

  BinNode() : parent(nullptr), lc(nullptr), rc(nullptr),
              height(0), npl(1), color(RB_RED) {}
  
  BinNode(T e, BinNode* p=nullptr, BinNode* lc=nullptr,
          BinNode* rc=nullptr, int h=0, int l=1, RBColor c=RB_RED) :
          data(e), parent(p), lc(lc), rc(rc), height(h),
          npl(l), color(c) {}
  
  int size();
  BinNode* insertAsLC(T const &);
  BinNode* insertAsRC(T const &);

  // in traverse succ
  BinNode* succ();

  template <typename VST> void travLevel(VST& visit) {
    // TODO
  }

  // Recursive
  template <typename VST> void travPre(VST& visit) {
    visit(data);
    if (lc) lc->travPre(visit);
    if (rc) rc->travPre(visit);
  }
  template <typename VST> void travIn(VST& visit) {
    if (lc) lc->travIn(visit);
    visit(data);
    if (rc) rc->travIn(visit);
  }
  template <typename VST> void travPost(VST& visit) {
    if (lc) lc->travPost(visit);
    if (rc) rc->travPost(visit);
    visit(data);
  }

  bool operator< (BinNode const& bn) {return data < bn.data;}
  bool operator> (BinNode const& bn) {return data > bn.data;}
  bool operator== (BinNode const& bn) {return data == bn.data;}
  bool operator!= (BinNode const& bn) {return data != bn.data;}

  inline bool isRoot() { return !parent; }
  inline bool isLChild() { return !isRoot() && this == parent->lc; }
  inline bool isRChild() { return !isRoot() && this == parent->rc; }
  inline bool hasParent() { return !isRoot(); }
  inline bool hasLChild() { return lc ? true : false; }
  inline bool hasRChild() { return rc ? true : false; }
  inline bool hasChild() { return hasLChild() || hasRChild(); }
  inline bool hasBothChild() { return hasLChild() && hasRChild(); }
  inline bool isLeaf() { return !hasChild(); }
  inline bool sibling() { return isLChild()? parent->rc : parent->lc; }
  inline bool uncle() { return parent->isLChild()? parent->parent->rc : parent->parent->lc; }
  inline BinNode* fromParentTo() {
    return isRoot() ? this : (isLChild() ? parent->lc : parent->rc);
  }

}; // class BinNode


// BinTree
template <typename T>
class BinTree {

protected:
  int _size;
  BinNode<T>* _root;
  virtual int updateHeight(BinNode<T>* x);
  void updateHeightAbove(BinNode<T>* x);
public:
  BinTree() : _size(0), _root(nullptr) {}
  ~BinTree() {if (0 < _size) remove(_root);}
  int size() const {return _size;}
  bool empty() const {return !_root;}
  BinNode<T>* root() const {return _root;}
  // Insert e as root
  BinNode<T>* insertAsRoot(T const& e);
  // Insert e as x's child (not exist)
  BinNode<T>* insertAsLC(BinNode<T>* x, T const& e);
  BinNode<T>* insertAsRC(BinNode<T>* x, T const& e);
  // Attach bintree as x's child
  // If use pointer of BinTree, value of t is copied
  // so can not be modified, but we want to set
  // t to nullptr
  BinNode<T>* attachAsLC(BinNode<T>* x, BinTree* &t);
  BinNode<T>* attachAsRC(BinNode<T>* x, BinTree* &t);

  // Remove node and its de
  int remove(BinNode<T>* x);
  BinTree* secede(BinNode<T>* x);

  // traverse
  template <typename VST>
  void travLevel(VST& visit) {
    if (_root) _root->travLevel(visit);
  }
  template <typename VST>
  void travPre(VST& visit) {
    if (_root) _root->travPre(visit);
  }
  template <typename VST>
  void travIn(VST& visit) {
    if (_root) _root->travIn(visit);
  }
  template <typename VST>
  void travPost(VST& visit) {
    if (_root) _root->travPost(visit);
  }
}; // class BinTree

} // namespace dsa
