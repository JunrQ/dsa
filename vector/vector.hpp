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
  // Expand
  void expand();
  // Shrink
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
  Vector<T>& operator= (Vector<T> const& v);

  /*!
   * Destructor
   */
  ~Vector();

  const T* data();
  const int size();


};


} // namespace dsa



