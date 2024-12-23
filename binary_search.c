#include <stdio.h>

// O(logn) time complexity se o array estiver ordenado
int binarySearch(int arr[], int left, int right, int target) {
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};  // Array ordenado
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Elemento encontrado no indice: %d\n", result);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}
