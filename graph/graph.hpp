

namespace dsa {


typedef enum {UNDISCOVERED, DISCOVERED, VISITED} VStatus;
typedef enum {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} EType;

template <typename Tv, typename Te>
class Graph {

private:
  void reset() {

  }

  void BFS(int, int&);
  void DFS(int, int&);
  void BCC(int, int&, Stack<int>&);
  bool TSort(int, int&, Stack<Tv>*);
  template <typename PU> void PFS(int, PU);

public:

  int n;
  virtual int insert(Tv const&) = 0;
  virtual Tv remove(int) = 0;



  void bfs(int);
  void dfs(int);
  void bcc(int);
  Stack<Tv>* tSort(int); // topology sort
  void prim(int);
  void dijkstra(int);
  template <typename PU> void pfs(int, PU);



}; // class Graph


} // namespace dsa

