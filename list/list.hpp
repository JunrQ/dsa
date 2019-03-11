
#include <iostream>

namespace dsa {

// ListNode
template <typename T>
struct ListNode {
  T data;
  ListNode<T>* pred;
  ListNode<T>* succ;

  ListNode() {}
  ListNode (T e, ListNode<T>* p=nullptr, ListNode<T>* s=nullptr)
    : data(e), pred(p), succ(s) {}
  
  ListNode<T>* insertAsPred(T const& e);
  ListNode<T>* insertAsSucc(T const& e);
};

// List
template <typename T>
class List {
private:
  int _size;
  ListNode<T>* header;
  ListNode<T>* trailer;

protected:
  void init();
  int clear();
  void copyNodes(ListNode<T>*, int);
  void merge(ListNode<T>*, int, List<T>&, ListNode<T>*, int);

  // mergesort
  
  // selectionSort

  // insertionSort

public:
  // Constructor
  List() { init(); }
  List(List<T> const& L);
  List(List<T> const& L, int lo, int n);
  List(ListNode<T>* p, int n);
  
  // Destructor
  ~List();

  int size() { return _size; }
  ListNode<T>* first();
  ListNode<T>* last();
  T remove(ListNode<T>* p); // TODO

  // Operator
  T& operator[] (int r) const;

  // Insert
  ListNode<T>* insertAsFirst(T const& e);
  ListNode<T>* insertAsLast(T const& e);
  ListNode<T>* insertAfter(ListNode<T>* p, T const& e);
  ListNode<T>* insertBefore(ListNode<T>* p, T const& e);
  
};


} // namespace dsa