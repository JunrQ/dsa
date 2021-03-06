#include <iostream>
#include <stdlib.h>

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
T List<T>::remove(ListNode<T>* p) {
  T e = p->data;
  p->pred->succ = p->succ;
  p->succ->pred = p->pred;
  delete p;
  _size--;
  return e;
}

template <typename T>
T List<T>::remove(int r) {
  // TODO if(r > _size) log error
  ListNode<T>* p = first();
  while (0 < r--) p = p->succ;
  T data = remove(p);
  return data;
}

template <typename T>
T& List<T>::operator[] (int r) {
  ListNode<T>* p = first();
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
  return p->insertAsSucc(e);
}

template <typename T>
ListNode<T>* List<T>::insertAfter(int r, T const& e) {
  ListNode<T>* p = first();
  while (0 < r--) p = p->succ;
  return insertAfter(p, e);
}

template <typename T>
ListNode<T>* List<T>::insertBefore(ListNode<T>* p, T const& e) {
  _size++;
  return p->insertAsPred(e);
}

template <typename T>
ListNode<T>* List<T>::insertBefore(int r, T const& e) {
  ListNode<T>* p = first();
  while (0 < r--) p = p->succ;
  return insertBefore(p, e);
}

template <typename T>
ListNode<T>* List<T>::find(const T& e, int n, ListNode<T>* p) const {
  while (0 < n--) {
    if (e == (p = p->pred)->data) return p;
  }
  return nullptr;
}

template <typename T>
ListNode<T>* List<T>::search(const T& e, int n, ListNode<T>* p) const {
  while (0 <= n--) { // equal is important
    if ((p = p->pred)->data <= e) break;
  }
  return p;
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
int List<T>::uniquify() {
  if (_size < 2) return 0;
  int oldSize = _size;
  ListNode<T>* p = header;
  while (trailer != (p = p->succ)) {
    if (p->succ->data == p->data) remove(p);
  }
  return oldSize - _size;
}

template <typename T>
ListNode<T>* List<T>::selectMax(ListNode<T>* p, int n) {
  ListNode<T>* max = p;
  while (1 < n--) {
    p = p->succ;
    // Choose the last one, stability
    if (p->data >= max->data) max = p;
  }
  return max;
}

template <typename T>
void List<T>::selectionSort(ListNode<T>* p, int n) {
  ListNode<T>* head = p->pred;
  ListNode<T>* tail = p;
  for (int i = 0; i < n; i++) tail = tail->succ;
  while (1 < n) {
    ListNode<T>* max = selectMax(head->succ, n);
    insertBefore(tail, remove(max));
    tail = tail->pred;
    n--;
  }
}

template <typename T>
void List<T>::insertionSort(ListNode<T>* p, int n) {
  p = p->succ;
  for (int i = 1; i < n; i++) {
    insertAfter(search(p->data, i, p), p->data);
    p = p->succ;
    remove(p->pred);
  }
}

template <typename T>
void List<T>::traverse(void (*visit) (T&)) {
  for (ListNode<T>* p = header->succ; p != trailer; p=p->succ)
    visit(p->data);
}

template <typename T>
void List<T>::merge(ListNode<T>* p, int n, List<T>& L, ListNode<T>* q, int m) {
  ListNode<T>* pp = p->pred;
  while (0 < m) {
    if ((0 < n) && (p->data <= q->data)) {
      if (q == (p = p->succ)) break;
      n--;
    } else {
      insertBefore(p, L.remove((q = q->succ)->pred));
      m--;
    }
  }
  p = pp->succ;
}

template <typename T>
void List<T>::mergeSort(ListNode<T>* p, int n) {
  // TODO
  if (n < 2) return;
  int m = n >> 1;
  ListNode<T>* q = p;
  for (int i = 0; i < m; i++) q = q->succ;
  mergeSort(p, m);
  mergeSort(q, n - m);
  merge(p, m, *this, q, n - m);
}

template <typename ST>
std::ostream& operator<< (std::ostream& os, const List<ST>& li) {
  // TODO error: member function 'traverse' not viable:
  // li.traverse([&](const ST& data){ os << data << " "; });
  for (ListNode<ST>* p = li.header->succ; p != li.trailer; p = p->succ) {
    os << p->data << " ";
  }
  os << std::endl;
  return os;
}

template <typename T>
void List<T>::shuffle() {
  int max_idx = _size - 1;
  for (int i = max_idx; i >= 1; i--) {
    int tmp = rand() % max_idx;
    if (tmp != i)
      exchange(this->operator[](i), this->operator[](tmp));
  }
}




}
