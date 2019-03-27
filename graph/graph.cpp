

#include "graph.hpp"
#include "../vector/vector.hpp"

namespace dsa {


// ----- Node -----
template <typename Tv>
struct Vertex {
  Tv data;
  int inDegree, outDegree;
  VStatus status;
  int dTime, fTime;
  int parent;
  int priority;

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
  Vector<Vertex<Tv> > V;
  Vector<Vector<Edge<Te>* > > E;
public:
  GraphMatrix() {n = e = 0;}
  ~GraphMatrix() {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        delete E[j][k];
      }
    }
  }

  virtual Tv& vertex(int i) {return V[i].data;}
  virtual int inDegree(int i) {return V[i].inDegree;}
  virtual int outDegree(int i) {return V[i].outDegree;}
  virtual int firstNbr(int i) {return nextNbr(i, n);}
  virtual int nextNbr(int i, int j) {
    while ((-1 < j) && (!exists(i, --j)));
    return j;
  }
  virtual VStatus& status(int i) {return V[i].status;}
  virtual int& dTime(int i) {return V[i].dTime;}
  virtual int& fTime(int i) {return V[i].fTime;}
  virtual int& parent(int i) {return V[i].parent;}
  virtual int& priority(int i) {return V[i].priority;}

  virtual int insert(Tv const& vertex) {
    for (int j = 0; j < n; j++)
      E[j].insert(nullptr);
    n++;
    E.insert(Vector<Edge<Te>* >(n, n, (Edge<Te>*) nullptr));
    return V.insert(Vertex<Tv> (vertex));
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