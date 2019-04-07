

#include "graph.hpp"
#include "vector.cpp"
#include "queue.hpp"

namespace dsa {

template<typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int& clock) {
  Queue<int> Q;
  status(v) = DISCOVERED;
  Q.enqueue(v);
  while (!Q.empty()) {
    int v = Q.dequeue();
    dTime(v) = ++clock;
    for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
      if (UNDISCOVERED == status(u)) {
        status(u) = DISCOVERED;
        Q.enqueue(u);
        type(v, u) = TREE;
        parent(u) = v;
      } else {
        type(v, u) = CROSS;
      }
    }
    status(v) = VISITED;
  }
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::bfs(int s) {
  reset();
  int clock = 0;
  int v = s;
  do {
    if (UNDISCOVERED == status(v)) BFS(v, clock);
  } while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s) {
  reset();
  int clock = 0;
  int v = s;
  do {
    if (UNDISCOVERED == status(v)) DFS(v, clock);
 } while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int& clock) {
  dTime(v) = ++clock;
  status(v) = DISCOVERED;
  for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
    switch (status(u)) {
      case UNDISCOVERED:
        type(v, u) = TREE;
        parent(u) = v;
        DFS(u, clock);
        break;
      case DISCOVERED:
        type(v, u) = BACKWARD;
        break;
      default:
        type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
        break;
    }
  }
  status(v) = VISITED;
  fTime(v) = ++clock;
}

template <typename Tv, typename Te>
Stack<Tv>* Graph<Tv, Te>::tSort(int s) {
  reset();
  int clock = 0;
  int v = s;
  Stack<Tv>* S = new Stack<Tv>;
  do {
    if (UNDISCOVERED == status(v)) {
      if (!TSort(v, clock, S)) {
        // if not DAG, make S empty and break (return)
        while (!S->empty()) S->pop();
        break;
      }
    }
  } while (s != (v = (++v % n)));
  return S;
}

template <typename Tv, typename Te>
bool Graph<Tv, Te>::TSort(int v, int& clock, Stack<Tv>* S) {
  dTime(v) = ++clock;
  status(v) = DISCOVERED;
  for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
    switch (status(u)) {
      case UNDISCOVERED:
        parent(u) = v;
        type(v, u) = TREE;
        if (!TSort(u, clock, S)) return false;
        break;
      case DISCOVERED:
        type(v, u) = BACKWARD;
        return false;
        break;
      default:
        type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
        break;
    }
  }
  status(v) = VISITED;
  S->push(vertex(v));
  return true;
}

template <typename Tv, typename Te> template <typename PU>
void Graph<Tv, Te>::pfs(int s, PU prioUpdater) {
  reset();
  int v = s;
  do {
    if (UNDISCOVERED == status(v)) PFS(v, prioUpdater);
  } while (s != (v = (++v % n)));
}

template <typename Tv, typename Te> template <typename PU>
void Graph<Tv, Te>::PFS(int s, PU prioUpdater) {
  // TODO
}

// prim algorithm
template <typename Tv, typename Te> struct PrimPU {
  virtual void operator() (Graph<Tv, Te>* g, int uk, int v) {
    if (UNDISCOVERED == g->status(v)) {
      if (g->priority(v) > g->weight(uk, v)) {
        g->priority(v) = g->weight(uk, v);
        g->parent(v) = uk;
      }
    }
  }
};

// dijkstra algorithm
template <typename Tv, typename Te> struct DijkstraPU {
  virtual void operator() (Graph<Tv, Te>* g, int uk, int v) {
    if (UNDISCOVERED == g->status(v)) {
      if (g->priority(v) > g->priority(uk) + g->weight(uk, v)) {
        g->priority(v) = g->priority(uk) + g->weight(uk, v);
        g->parent(v) = uk;
      }
    }
  }
};

// ----- Node -----
template <typename Tv>
struct Vertex {
  Tv data; // data
  int inDegree, outDegree;
  VStatus status;
  int dTime, fTime; // time frame
  int parent; // parent node in traverse tree
  int priority; // priority

  Vertex(Tv const& d = (Tv)0) : data(d), inDegree(0), outDegree(0),
                                status(UNDISCOVERED), dTime(-1),
                                fTime(-1), parent(-1), priority(INT_MAX) {}
}; // struct Vertex

// ---- Edge -----
template <typename Te>
struct Edge {
  Te data;
  int weight;
  EType type;
  Edge(Te const& d, int w) : data(d), weight(w), type(UNDETERMINED) {}
}; // struct Edge

// --------- Adjacency matrix ----------
template <typename Tv, typename Te>
class GraphMatrix : public Graph<Tv, Te> {
private:
  Vector<Vertex<Tv> > V; // vector of vertex
  Vector<Vector<Edge<Te>* > > E; // matrix of edgess
public:
  GraphMatrix() {n = e = 0;}
  ~GraphMatrix() {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        delete E[j][k];
      }
    }
  }

  // basic operation
  // Get data of ith vertex
  virtual Tv& vertex(int i) {return V[i].data;}
  virtual int inDegree(int i) {return V[i].inDegree;}
  virtual int outDegree(int i) {return V[i].outDegree;}
  virtual int firstNbr(int i) {return nextNbr(i, n);}
  virtual int nextNbr(int i, int j) { // next nbr after j
    while ((-1 < j) && (!exists(i, --j)));
    return j;
  }

  // information
  virtual VStatus& status(int i) {return V[i].status;}
  virtual int& dTime(int i) {return V[i].dTime;}
  virtual int& fTime(int i) {return V[i].fTime;}
  virtual int& parent(int i) {return V[i].parent;}
  virtual int& priority(int i) {return V[i].priority;}

  // dynamic operation
  virtual int insert(Tv const& vertex) {
    for (int j = 0; j < n; j++)
      E[j].insert(nullptr);
    n++;
    E.insert(Vector<Edge<Te>* >(n, n, (Edge<Te>*) nullptr));
    return V.insert(Vertex<Tv> (vertex));
  }

  // remove node i and its related edge
  virtual Tv remove(int i) {
    for (int j = 0; j < n; j++) {
      if (exists(i, j)) {
        delete E[i][j];
        V[j].inDegree--;
      }
    }
    E.remove(i);
    n--;
    Tv vRes = vertex(i);
    V.remove(i);
    for (int j = 0; j < n; j++) {
      if (Edge<Te>* e = E[j].remove(i)) {
        delete e;
        V[j].outDegree--;
      }
    }
    return vRes;
  }

  virtual bool exists(int i, int j) {
    return (0 <= i) && (i < n) && (0 <= j) && (j < n) && (E[i][j] != nullptr);
  }

  virtual EType& type(int i, int j) {return E[i][j]->type;}
  virtual Te& edge(int i, int j) {return E[i][j]->data;}
  virtual int& weight(int i, int j) {return E[i][j]->weight;}

  // Dynamic operation
  virtual void insert(Te const& edge, int w, int i, int j) {
    if (exists(i, j)) return;
    E[i][j] = new Edge<Te>(edge, w);
    e++;
    V[i].outDegree++;
    V[j].inDegree++;
  }

  virtual Te remove(int i, int j) {
    Te eRes = edge(i, j);
    delete E[i][j];
    E[i][j] = nullptr;
    e--;
    V[i].outDegree--;
    V[j].inDegree--;
    return eRes;
  }

};

template <typename Tv, typename Te>
class GraphList : public Graph<Tv, Te> {
private:
  Vector<Vertex<Tv> > V;
  Vector<List<Edge<Te>* > > E;

public:
  



};






} // namespace dsa