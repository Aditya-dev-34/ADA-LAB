#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

struct Edge edges[MAX], result[MAX];
int parent[MAX];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}
void sortEdges(int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    sortEdges(e);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    int totalCost = 0;

    while (count < n - 1 && i < e) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            result[count++] = edges[i];
            unionSet(u, v);
            totalCost += w;
        }
        i++;
    }
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (int i = 0; i < count; i++) {
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].w);
    }
    printf("Total cost of MST = %d\n", totalCost);
    return 0;
}