
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

  inline void exchange(T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
  }

protected:
  // init header and trailer
  void init();
  // Return size
  int clear();
  void copyNodes(ListNode<T>*, int);
  void merge(ListNode<T>*, int, List<T>&, ListNode<T>*, int);
  ListNode<T>* selectMax(ListNode<T>*, int);

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
  T remove(ListNode<T>* p);
  T remove(int r);

  // Operator
  T& operator[] (int r) const;

  // Find in n pred
  ListNode<T>* find(const T& e, int n, ListNode<T>* p) const;


  // Insert
  ListNode<T>* insertAsFirst(T const& e);
  ListNode<T>* insertAsLast(T const& e);
  ListNode<T>* insertAfter(ListNode<T>* p, T const& e);
  ListNode<T>* insertBefore(ListNode<T>* p, T const& e);
  ListNode<T>* insertAfter(int r, T const& e);
  ListNode<T>* insertBefore(int r, T const& e);
  ListNode<T>* append(T const& e) {return insertAsLast(e);}

  // Return elements removed
  int deduplicate();

  void shuffle();

  // Sort
  void selectionSort(ListNode<T>* p, int n);
  void selectionSort() {selectionSort(first(), _size);}
  void insertionSort(ListNode<T>* p, int n);
  void insertionSort() {insertionSort(first(), _size);}
  void mergeSort(ListNode<T>* p, int n);


  // traverse
  void traverse(void (*visit) (T&));

  template<typename ST>
  friend std::ostream& operator<< (std::ostream& os, const List<ST>& li);
  
};


} // namespace dsa