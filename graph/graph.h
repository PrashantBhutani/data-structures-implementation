#include <stdio.h>

#define MAXV 1000           // maximum number of vertices possible in graph

typedef struct {
  int dest;                  // destination vertex of this edge from this vertex 
  int weight;                // weight of the edge
  struct edgeNode* next;     // list of adjacency list from this vertex
} edge;

typedef struct {
  int directed;              // graph directed or not?
  int degree[MAXV];          // out degree of each vertex = number of edges going/coming from/to each vertex 
  int nvertices;             // number of vertices in graph
  int nedges;                // number of edges in graph
  edge *edges[MAXV];         // adjacency edge list for each vertex
} graph;

void initialize_graph (graph *g, int directed);

void read_graph (graph *g, int directed);
