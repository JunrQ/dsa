/*
 * 散列表
 */

#include "dict.hpp"

namespace dsa {

template <typename K, typename V>
class Hashtable : public Dictionary<K, V> {

private:
  Entry<K, V>** ht;
  int M;
  int N;
  Bitmap* lazyRemoval;


protected:
  int probe4Hit(const K& k);
  int probe4Free(const K& k);
  void rehash();

public:
  Hashtable(int c = 5);
  ~Hashtable();

  int size() const {return N;}
  bool put(K, V);
  V* get(K k);
  bool remove(K k);
};

template<typename K, typename V>
Hashtable<K, V>::Hashtable(int c) {
  M = primeNLT(c, 1048567, "");
  N = 0;
  ht = new Entry<K, V>*[M];
  memset(ht, 0, sizeof(Entry<K, V>*) *M);
  lazyRemoval = new Bitmap(M);
}


} // namespace dsa
