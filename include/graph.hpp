#include <limits.h>
#include "stack.hpp"

namespace dsa {

typedef enum {UNDISCOVERED, DISCOVERED, VISITED} VStatus;
typedef enum {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EType;

template <typename Tv, typename Te>
class Graph {

private:
  void reset() {
    for (int i = 0; i < n; i++) {
      status(i) = UNDISCOVERED;
      dTime(i) = fTime(i) = -1;
      parent(i) = -1;
      priority(i) = INT_MAX;
      for (int j = 0; j < n; j++) {
        if (exists(i, j)) type(i, j) = UNDETERMINED;
      }
    }
  }

  // search algorithms, for one connected domain
  void BFS(int, int&);
  void DFS(int, int&);
  void BCC(int, int&, Stack<int>&);
  bool TSort(int, int&, Stack<Tv>*);
  template <typename PU> void PFS(int, PU);

public:
  // ------- Node ----------
  // number of nodes
  int n;
  // Insert a vertex, return idx
  virtual int insert(Tv const&) = 0;
  // Remove vertex
  virtual Tv remove(int) = 0;
  // Get vertex
  virtual Tv& vertex(int) = 0;
  // degree
  virtual int inDegree(int) = 0;
  virtual int outDegree(int) = 0;
  // First neighbor
  virtual int firstNbr(int) = 0;
  // Next neighbor
  virtual int nextNbr(int) = 0;
  
  // Get status of vertex
  virtual VStatus& status(int) = 0;
  virtual int& dTime(int) = 0;
  virtual int& fTime(int) = 0;
  virtual int& parent(int) = 0;
  virtual int& priority(int) = 0;

  // -------- Edge --------
  // number of edges
  int e;
  virtual bool exists(int, int) = 0;
  // Insert edge between v, u with weight w
  virtual void insert(Te const&, int, int, int) = 0;
  // Remove edge and reture it
  virtual Te remove(int, int) = 0;
  virtual EType& type(int, int) = 0;
  virtual Te& edge(int, int) = 0;
  virtual int& weight(int, int) = 0;

  // -------- Algorithm ---------
  // search, for the whole graph, different from *FS
  void bfs(int);
  void dfs(int);
  void bcc(int);
  Stack<Tv>* tSort(int); // topology sort
  void prim(int);
  void dijkstra(int);
  template <typename PU> void pfs(int, PU);

}; // class Graph


} // namespace dsa

