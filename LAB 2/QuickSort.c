#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int A[], int low, int high) {
    int pivot = A[low]; 
    int i = low;
    int j = high;
    while (i < j) {
        while (A[i] <= pivot && i < high)
            i++;
        while (A[j] > pivot)
            j--;

        if (i < j) {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[low], &A[j]);
    return j;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int k = partition(A, low, high);
        quickSort(A, low, k - 1);
        quickSort(A, k + 1, high);
    }
}

int main() {
    int arr[SIZE];
    srand(time(NULL));

    printf("Quick Sort (Hoare Partition) Performance Analysis\n\n");

    for (int n = 10000; n <= 500000; n += 50000) {
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Time taken for %d inputs: %.6f seconds\n", n, time_taken);
    }

    printf("\nAverage Time Complexity: O(n log n)\n");
    printf("Worst Case Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(log n)\n");

    return 0;
}
