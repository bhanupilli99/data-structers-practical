#include <stdio.h>
#include <stdlib.h>

struct Edge {
   int source, destination, weight;
};

int compare(const void* a, const void* b) {
   struct Edge* edge1 = (struct Edge*)a;
   struct Edge* edge2 = (struct Edge*)b;
   return edge1->weight > edge2->weight;
}

int find(int parent[], int i) {
   if(parent[i] == -1) {
      return i;
   } else {
      return find(parent, parent[i]);
   }
}

void unionSet(int parent[], int x, int y) {
   int xset = find(parent, x);
   int yset = find(parent, y);
   parent[xset] = yset;
}

void kruskalMST(struct Edge edges[], int V, int E) {
   qsort(edges, E, sizeof(edges[0]), compare);
   struct Edge result[V];
   int parent[V];
   for(int i = 0; i < V; i++) {
      parent[i] = -1;
   }
   int i = 0, e = 0;
   while(e < V-1 && i < E) {
      struct Edge next_edge = edges[i++];
      int x = find(parent, next_edge.source);
      int y = find(parent, next_edge.destination);
      if(x != y) {
         result[e++] = next_edge;
         unionSet(parent, x, y);
      }
   }
   printf("Minimum Spanning Tree:\n");
   for(i = 0; i < e; i++) {
      printf("%d -- %d == %d\n", result[i].source, result[i].destination, result[i].weight);
   }
}

int main() {
   int V = 4;
   int E = 5;
   struct Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
   kruskalMST(edges, V, E);
   return 0;
}
