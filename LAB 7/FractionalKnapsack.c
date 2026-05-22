#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    float ratio;
};
void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortItems(struct Item items[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}
int main()
{
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d",&items[i].profit,&items[i].weight);

        items[i].ratio =(float)items[i].profit / items[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    sortItems(items, n);

    float totalProfit = 0.0;
    printf("\nSelected Items:\n");
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            printf("Item %d -> 100%% taken\n", i + 1);
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        }
        else
        {
            float fraction =
                (float)capacity / items[i].weight;

            printf("Item %d -> %.2f%% taken\n",i + 1,fraction * 100);
            totalProfit +=items[i].profit * fraction;
            break;
        }
    }
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}