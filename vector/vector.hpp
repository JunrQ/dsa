/*!
 * vector.hpp
 * 
 * \author ZhouJunr
 */

namespace dsa {


template <typename T> class Vector {
private:
  // size of Vector
  int _size;
  // capacity of Vector
  int _capacity;
  // elements
  T* _elem;
  // Whether sorted
  bool _sorted=false;

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
  inline left(int i) { return 2 * i; }
  inline right(int i) { return 2 * i + 1; }
  inline parent(int i) { return i / 2; }

  int partition(T*, int, int);
  void quicksort_imp(T*, int, int);

  inline exchange(T* x, T* y) {
    T tmp = *x;
    *x = *y;
    *y = tmp;
  }

  inline exchange(T& x, T& y) {
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
  Vector(T const* A);
  Vector();

  // Operator
  Vector<T>& operator= (const Vector<T>& v);
  T& operator[] (int idx);

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

  // Sort algorithms
  void mergesort();
  void heapsort();
  void quicksort();

  // shuffle
  void shuffle();

  // find
  int sequential_find(const T* key);
  int binary_find(const T* key);

  // statistics
  T mean();
  T max();
  T min();



};


} // namespace dsa



