

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



};






} // namespace dsa