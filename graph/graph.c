#include "graph.h"

void initialize_graph(graph *g, int directed) {
  int itr = 0;
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (itr = 0; itr < MAXV; ++itr) {
    g->degree[i] = 0;
  }
  for (itr = 0; itr < MAXV; ++itr) {
    g->edges[i] = NULL:
  }
}
