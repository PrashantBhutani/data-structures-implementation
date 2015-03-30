#include "graph.h"

void initialize_graph (graph *g, int directed) {
  int itr = 0;
  g->nvertices = 0;
  g->nedges = 0;
  g->directed = directed;

  for (itr = 1; itr <= MAXV; ++itr) {
    g->degree[itr] = 0;
  }
  for (itr = 1; itr <= MAXV; ++itr) {
    g->edges[itr] = NULL;
  }
}

void read_graph (graph *g, int directed) {
  int itr;
  int nedges;
  int edgeStart, edgeEnd, edgeWeight;
  initialize_graph (g, directed);
  
  scanf("%d %d", &(g->nvertices), &nedges);

  if (g->nvertices > MAXV) {
    printf ("vertices cannot be more than %d", MAXV);
    return;
  }

  for ( itr = 1 ; itr <= nedges; ++itr) {
    scanf("%d %d %d", &edgeStart, &edgeEnd, &edgeWeight);
    insert_edge (g, edgeStart, edgeEnd, edgeWeight, directed);
  }
}

void insert_edge (graph *g, int edgeStart, int edgeEnd, int edgeWeight, int directed) {
  edge *tempEdge = (edge *) malloc (sizeof(edge));
  tempEdge->dest = edgeEnd;
  tempEdge->weight = edgeWeight;
  tempEdge->next = g->edges[edgeStart];

  g->edges[edgeStart] = tempEdge;
  g->degree[edgeStart]++;

  if (directed == 0) {
    insert_edge (g, edgeEnd, edgeStart, edgeWeight, 1);
  } else {
    g->nedges++;
  }
}

void print_graph(graph *g) {
  int itr;
  edge *tempEdge;
  for (itr = 1; itr <= g->nvertices; ++itr) {
    printf("edge Start = %d\n", itr);
    tempEdge = g->edges[itr];
    while (tempEdge != NULL) {
      printf("\tedge end = %d\n",tempEdge->dest);
      tempEdge = tempEdge->next;
    }
    printf("\n");
  }
}
