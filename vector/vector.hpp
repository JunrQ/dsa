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
  void heapsort();



};


} // namespace dsa



