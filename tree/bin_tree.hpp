

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
  BinNode* succ();

  template <typename VST> void travLevel(VST&);
  template <typename VST> void travPre(VST&);
  template <typename VST> void travIn(VST&);
  template <typename VST> void travPost(VST&);

  bool operator< (BinNode const& bn) {return data < bn.data;}
  bool operator== (BinNode const& bn) {return data == bn.data;}

  bool isRoot() { return !parent; }
  bool isLChild() { return !isRoot() && this == parent->lc; }
  bool isRChild() { return !isRoot() && this == parent->rc; }
  bool hasParent() { return !isRoot(); }
  bool hasLChild() { return lc ? true : false; }
  bool hasRChild() { return rc ? true : false; }
  bool hasChild() { return hasLChild() || hasRChild(); }
  bool hasBothChild() { return hasLChild() && hasRChild(); }
  bool isLeaf() { return !hasChild(); }
  

};








} //  dsa


