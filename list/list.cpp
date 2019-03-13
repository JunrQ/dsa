

#include "list.hpp"

namespace dsa {

template <typename T>
ListNode<T>* ListNode<T>::insertAsPred(T const& e) {
  ListNode<T>* ln = new ListNode<T>;
  ln->data = e;
  pred->succ = ln;
  ln->pred = pred;
  pred = ln;
  ln->succ = this;
  return ln;
}

template <typename T>
ListNode<T>* ListNode<T>::insertAsSucc(T const& e) {
  ListNode<T>* ln = new ListNode<T>;
  ln->data = e;
  ln->succ = succ;
  succ->pred = ln;
  succ = ln;
  ln->pred = this;
  return ln;
}

// Constructor

template <typename T>
void List<T>::init() {
  header = new ListNode<T>;
  trailer = new ListNode<T>;
  header->succ = trailer;
  header->pred = nullptr;
  trailer->pred = header;
  trailer->succ = nullptr;
  _size = 0;
}

// protected

template <typename T>
List<T>::List(List<T> const& L) {
  // TODO
}

template <typename T>
void List<T>::copyNodes(ListNode<T>* p, int n) {
  init();
  while (n--) {
    insertAsLast(p->data);
    p = p->succ;
  }
}

template <typename T>
List<T>::~List() {
  clear();
  delete header;
  delete trailer;
}

template <typename T>
int List<T>::clear() {
  int oldSize = _size;
  while (0 < _size) remove(header->succ);
  return oldSize;
}

template <typename T>
ListNode<T>* List<T>::first() {
  return header->succ;
}

template <typename T>
ListNode<T>* List<T>::last() {
  return trailer->pred;
}

template <typename T>
T& List<T>::remove(ListNode<T>* p) {
  T e = p->data;
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p;
  _size--;
  return e;
}

template <typename T>
T& List<T>::operator[] (int r) const {
  ListNode<T>* p =first();
  while (0 < r--) p = p->succ;
  return p->data;
}

template <typename T>
ListNode<T>* List<T>::insertAsFirst(T const& e) {
  _size++;
  return header->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertAsLast(T const& e) {
  _size++;
  return trailer->insertAsPred(e);
}

template <typename T>
ListNode<T>* List<T>::insertAfter(ListNode<T>* p, T const& e) {
  _size++;
  p->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertBefore(ListNode<T>* p, T const& e) {
  _size++;
  p->insertAsPred(e);
}

template <typename T>
ListNode<T>* List<T>::find(const T& e, int n, ListNode<T>* p) const {
  while (0 < n--) {
    if (e == (p = p->pred)->data) return p;
  }
  return nullptr;
}

template <typename T>
int List<T>::deduplicate() {
  if (_size < 2) return 0;
  int oldSize = _size;
  int r = 0;
  ListNode<T>* p = header;
  while (trailer != (p = p->succ)) {
    ListNode<T>* q = find(p->data, r, p);
    q ? remove(q) : r++;
  }
  return oldSize - _size;
}

template <typename T>
ListNode<T>* selectMax(ListNode<T>* p, int n) {
  ListNode<T>* max = p;
  while (0 < n--) {
    p = p->succ;
    // Choose the last one
    if (p->data >= max->data) max = p;
  }
}

template <typename T>
void List<T>::selectionSort(ListNode<T>* p, int n) {
  ListNode<T>* head = p->pred;
  ListNode<T>* tail = p->succ;
  for (int i = 0; i < n; i++) tail = tail->succ;
  while (0 < n) {
    ListNode<T>* max = selectMax(head->succ, n);
    insertBefore(tail, remove(max));
    tail = tail->pred;
    n--;
  }
}

template <typename T>
void List<T>::traverse(void (*visit) (T&)) {
  for (ListNode<T>* p = header->succ; p != trailer; p=p->succ)
    visit(p->data);
}

template <typename T>
void List<T>::merge(ListNode<T>* p, int n, List<T>&, ListNode<T>* q, int m) {
  
}











}


