#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front > rear;
}
int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }
    int count = 0;
    int topo[MAX];

    while (!isEmpty()) {
        int u = dequeue();
        topo[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }
    if (count != n) {
        printf("Graph has a cycle. Topological sort not possible.\n");
    } 
    else {
        printf("Topological Order:\n");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }
    return 0;
}