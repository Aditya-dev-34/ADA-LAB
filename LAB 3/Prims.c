#include <stdio.h>
#define MAX 100
#define INF 99999

double graph[MAX][MAX];
int parent[MAX];
double key[MAX];
int visited[MAX];

int minKey(int n) {
    double min = INF;
    int minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}
int main() {
    int n, e;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        double w;
        scanf("%d %d %lf", &u, &v, &w);
        
        u--; v--;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(n);
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    double totalCost = 0;
    printf("\nEdges in Minimum Spanning Tree:\n");
    for (int i = 1; i < n; i++) {
        printf("%d -- %d == %.2lf\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST = %.2lf\n", totalCost);
    return 0;
}