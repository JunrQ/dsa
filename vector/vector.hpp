/*!
 * vector.hpp
 * 
 * \author ZhouJunr
 */

#include <iostream>

#define DEBUG

namespace dsa {


template <typename T> class Vector {
private:
  // size of Vector
  int _size;
  // capacity of Vector
  int _capacity;
  // elements
  T* _elem;

  // Copy from array
  void copyFrom(T const* A, int lo, int hi);
  // Expand capacity double
  void expand();
  // Shrink capacity to size
  void shrink();

  // auxiliary function
  // build max heap
  void build_max_heap(T*, int);
  // maintain max-heap property, assume left[i]
  // right[i] are max-heaps, bug a[i] might not
  void max_heapify(T*, int, int);
  inline int left(int i) { return 2 * i; }
  inline int right(int i) { return 2 * i + 1; }
  inline int parent(int i) { return i / 2; }

  int partition(T*, int, int);
  void quicksort_imp(T*, int, int);

  bool bubble(int lo, int hi);
  void merge(int, int, int);

  inline void exchange(T* x, T* y) {
    T tmp = *x;
    *x = *y;
    *y = tmp;
  }

  inline void exchange(T& x, T& y) {
    T tmp = x;
    x = y;
    y = tmp;
  }
  
public:
  /*!
   * \brief Vector constructor
   * Given capacity, size, init value
   */
  Vector(int capacity, int size, T init);
  // Copy from array
  Vector(T const* A, int rank);
  Vector(T const* A, int lo, int hi);
  Vector();

  // Operator
  Vector<T>& operator= (const Vector<T>& v);
  T& operator[] (int idx);

  // non-member, friend
  // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class/4661372#4661372
  template<typename ST>
  friend std::ostream& operator<< (std::ostream& os, const Vector<ST>& vec);

  /*!
   * Destructor
   */
  ~Vector();

  T* const data() const;
  int size() const;
  inline int capacity() const;

  /*!
   * \brief Reserve capacity
   * If already initilized, turncate.
   */
  void reserve(unsigned int n);

  /*
   * \brief Push back an ele into vector.
   */
  void push_back(const T& ele);

  /*
   * \brief Insert one element.
   */
  int insert(int r, const T& ele);

  /*
   * \brief Remove a interval, return #ele removed.
   */
  int remove(int lo, int hi);
  T remove(int r);

  /*
   * \brief Remove duplicate elements;
   */
  int deduplicate();
  /*
   * \brief Remove duplicate elements in ordered vector.
   */
  int ordered_uniquify_v1();
  int ordered_uniquify();

  /*
   * \brief Traverse vector.
   */
  void traverse(void (*visit) (T&)) {
    for (int i = 0; i < _size; i++) visit(_elem[i]);
  }
  template <typename VST>
  void traverse(VST& visit) {
    for (int i = 0; i < _size; i++) visit(_elem[i]);
  }
  

  // Sort algorithms
  void mergesort(int lo, int hi);
  void heapsort();
  void quicksort();
  void bubblesort();
  void bubblesort_v1(int lo, int hi);
  void selectionsort();


  // shuffle
  void shuffle();

  // find - unordered
  int sequential_find(const T& key, int lo, int hi) const;
  // search - ordered
  int binary_search(const T* key) const;
  int binary_search_v1(const T& key, int lo, int hi) const;
  int binary_search_v2(const T& key, int lo, int hi) const;
  int binary_search_v3(const T& key, int lo, int hi) const;

  // statistics
  T mean();
  T max();
  T min();

  int disordered() const;



};


} // namespace dsa



