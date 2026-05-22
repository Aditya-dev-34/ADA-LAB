#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

typedef struct
{
    int value;
    int dir;
} Element;

void printPermutation(Element arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].dir == LEFT)
            printf(" <-  ");
        else
            printf(" ->  ");
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%3d ", arr[i].value);
    }
    printf("\n\n");
}
int getMobile(Element arr[], int n)
{
    int mobile_index = -1;
    int mobile_value = -1;

    for (int i = 0; i < n; i++)
    {
        int next = i + arr[i].dir;

        if (next >= 0 && next < n)
        {
            if (arr[i].value > arr[next].value &&
                arr[i].value > mobile_value)
            {
                mobile_value = arr[i].value;
                mobile_index = i;
            }
        }
    }

    return mobile_index;
}
void reverseDirection(Element arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].value > value)
        {
            arr[i].dir *= -1;
        }
    }
}
void johnsonTrotter(Element arr[], int n)
{
    printPermutation(arr, n);

    while (1)
    {
        int mobile_index = getMobile(arr, n);

        if (mobile_index == -1)
            break;

        int swap_index = mobile_index + arr[mobile_index].dir;

        Element temp = arr[mobile_index];
        arr[mobile_index] = arr[swap_index];
        arr[swap_index] = temp;

        reverseDirection(arr, n, arr[swap_index].value);
        printPermutation(arr, n);
    }
}
int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    Element *arr = (Element *)malloc(n * sizeof(Element));
    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].dir = LEFT;
    }
    printf("\nPermutations:\n\n");
    johnsonTrotter(arr, n);
    free(arr);
    return 0;
}