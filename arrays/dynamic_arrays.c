#include <stdio.h>
#include <stdlib.h>

// Complexity: O(n)
void initialize_dynamic_array(int **arr, int size) {
    *arr = (int *)malloc(size * sizeof(int));
    if(*arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for(int i = 0; i < size; i++) {
        (*arr)[i] = i + 1;
    }
};

// Complexity: O(n)
void print_dynamic_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }
}

// Complexity: O(n)
void resize_dynamic_array(int **arr, int new_size) {
    *arr = (int *)realloc(*arr, new_size * sizeof(int));
    if (*arr == NULL) {
        printf("Memory reallocation failed\n");
        exit(1);
    }
    for (int i = 0; i < new_size; i++) {
        if (i >= 5) {
            (*arr)[i] = i + 1;
        }
    }
}

// Complexity: O(1)
void free_dynamic_array(int *arr) {
    free(arr);
    arr = NULL;
}

int main() {
    int *arr = NULL;
    int size = 5;

    initialize_dynamic_array(&arr, size);
    print_dynamic_array(arr, size);

    resize_dynamic_array(&arr, 10);
    print_dynamic_array(arr, 10);

    free_dynamic_array(arr);

    return 0;
}
