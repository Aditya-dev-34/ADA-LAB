#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);
    int values[n], weights[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &values[i]);
    }
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weights[i]);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)
            {
                int include = values[i - 1] +
                              dp[i - 1][w - weights[i - 1]];

                int exclude = dp[i - 1][w];

                dp[i][w] = max(include, exclude);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    printf("\nMaximum Profit = %d\n", dp[n][W]);
    int w = W;
    printf("\nSelected Items:\n");
    int totalWeight = 0;
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("Item %d -> Value = %d, Weight = %d, Quantity = 1\n",
                   i, values[i - 1], weights[i - 1]);

            totalWeight += weights[i - 1];

            w = w - weights[i - 1];
        }
    }
    printf("\nTotal Weight Used = %d\n", totalWeight);
    return 0;
}