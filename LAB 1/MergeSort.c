#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500000

int res[SIZE];

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            res[k++] = arr[i++];
        } else {
            res[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        res[k++] = arr[i++];
    }

    while (j <= high) {
        res[k++] = arr[j++];
    }

    for (i = low; i <= high; i++) {
        arr[i] = res[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[SIZE];
    srand(time(NULL));

    for (int n = 10000; n <= 500000; n += 50000) {

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken for %d inputs: %.6f seconds\n", n, time_taken);
    }

    return 0;
}