#include "graph.h"

int *visited, *parent;

struct node {
  int vertex;
  struct node *next;
} *queueHead, *queueTail;

struct node* getNewNode() {
  return (struct node*)malloc(sizeof(struct node));
}

void enqueue (int vertex) {
  struct node *temp = getNewNode();
  temp->vertex = vertex;
  temp->next = NULL;
    
  if (queueHead == NULL) {
    queueHead = queueTail = temp;
  } else {
    queueTail->next = temp;
    queueTail = temp;
  }
  visited[vertex] = 1;
}

struct node* dequeue() {
  if (queueHead == NULL) {
    return NULL;
  }
  struct node *temp = queueHead;
  if (queueHead == queueTail) {
    queueTail = NULL;
  }
  queueHead = queueHead->next;
  printf("dequeued vertex = %d\n",temp->vertex);
  return temp;
}

void initialize_bfs(graph *g) {
  // set all vertices as non-visited
  visited = (int*) malloc (sizeof(int)*(g->nvertices + 1));
  parent = (int*) malloc (sizeof(int)*(g->nvertices + 1));
  for (int i = 1; i < g->nvertices; ++i) {
    visited[i] = 0;
    parent[i] = 0;
  }
}

void bfs (graph *g, int start) {
  struct node *current;
  edge *tempEdge;
  int dest;
  initialize_bfs(g);
  enqueue(start);
  parent[start] = 0;
  current = dequeue();
  while (current != NULL) {
    tempEdge = g->edges[current->vertex];
    while(tempEdge != NULL) {
      dest = tempEdge->dest;
      if (visited[dest] != 1) {
	enqueue(dest);
	parent[dest] = current->vertex;
      }
      tempEdge = tempEdge->next;
    }
    current = dequeue();
  }
}
