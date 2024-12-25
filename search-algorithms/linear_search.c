#include <stdio.h>

// O(n) time complexity
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);  // Tamanho do array: (4(int) * nº elementos) / (4(int) * 1 elemento) = 20 / 4 = 5 elementos
    int target = 30;
    
    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Elemento encontrado no indice: %d\n", result);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}
