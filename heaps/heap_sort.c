#include <stdio.h>
#include <stdlib.h>

// Complexity: O(n)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Complexity: O(n)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Complexity: O(n log n)
void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// Complexity: O(n log n)
void heapSortAscending(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Complexity: O(n log n)
void heapSortDescending(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }

    for (int i = 0; i < n / 2; i++) {
        swap(&arr[i], &arr[n - i - 1]);
    }
}

// Complexity: O(n)
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSortAscending(arr, n);
    printf("\nSorted array in ascending order:\n");
    printArray(arr, n);

    heapSortDescending(arr, n);
    printf("\nSorted array in descending order:\n");
    printArray(arr, n);

    return 0;
}
