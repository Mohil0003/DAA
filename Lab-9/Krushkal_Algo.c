#include <stdio.h>

struct Edge {
    int src, dest, weight;
};

void sortEdges(struct Edge edges[], int E){
    for(int i =1 ; i < E; i++) {
        struct Edge key = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].weight > key.weight) {
            edges[j + 1] = edges[j];
            j--;
        }
        edges[j + 1] = key;
    }
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}
void 
void kruskal(int V , int E ,struct Edge edges[]){
    int parent[V];
    int edge=0;
    struct Edge mst[V - 1];
    for (int i = 0; i < V; i++){
        parent[i] = i;
    }
    sortEdges(edges, E);
    for (int i = 0; i < E && edge < V - 1; i++) {
        int u = find(parent, edges[i].src);
        int v = find(parent, edges[i].dest);

        int ucomp = find(parent, u);
        int vcomp = find(parent, v);
        if (ucomp != vcomp) {
            mst[edge++] = edges[i];
            parent[ucomp] = vcomp;   // Union operation
        }
    }
}
void main(){

}