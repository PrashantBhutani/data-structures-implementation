#include "graph.h"

int main() {
  graph *g = malloc(sizeof(graph));
  read_graph(g, 0);
  print_graph(g);
  return 0;
}
