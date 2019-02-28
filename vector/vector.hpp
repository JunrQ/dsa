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
  Vector<T>& operator= (const Vector<T>& v);

  /*!
   * Destructor
   */
  ~Vector();

  T* const data();
  int const size();

  void reserve(unsigned int n);


};


} // namespace dsa



