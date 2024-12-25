#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = low - 1;       // Índice do menor elemento

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // Se o elemento atual é menor ou igual ao pivô
            i++;
            swap(&arr[i], &arr[j]); // Troca os elementos
        }
    }
    // Troca o pivô para sua posição correta
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Retorna o índice do pivô
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array e obtém o índice do pivô
        int pi = partition(arr, low, high);

        // Ordena recursivamente os sub-arrays
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array antes da ordenacao:\n");
    print_array(arr, size);

    quicksort(arr, 0, size - 1);

    printf("Array depois da ordenacao:\n");
    print_array(arr, size);

    return 0;
}
