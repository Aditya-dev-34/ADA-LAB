#include <stdio.h>

#define INF 99999

int main()
{
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int dist[n][n];
    printf("Enter weighted adjacency matrix:\n");
    printf("(Enter %d if no edge exists)\n", INF);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &dist[i][j]);
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    int newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j])
                    {
                        dist[i][j] = newDist;
                    }
                }
            }
        }
    }
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}