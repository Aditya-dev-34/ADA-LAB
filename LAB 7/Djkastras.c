#include <stdio.h>

#define MAX 100
#define INF 99999

void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int distance[MAX];
    int visited[MAX] = {0};

    for (int i = 0; i < n; i++)
    {
        distance[i] = INF;
    }
    distance[start] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }
    printf("\nShortest distances from vertex %d:\n", start);
    for (int i = 0; i < n; i++)
    {
        printf("To vertex %d = %d\n", i, distance[i]);
    }
}
int main()
{
    int n;
    int graph[MAX][MAX];
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    dijkstra(graph, n, start);
    return 0;
}