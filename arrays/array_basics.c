#include <stdio.h>

// Complexity: O(n)
void initialize_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

// Complexity: O(n)
void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }
}

// Complexity: O(1)
void set_value_at_index(int *arr, int index, int value) {
    if (index >= 0 && index < 5) {
        arr[index] = value;
    } else {
        printf("Index out of bounds\n");
    }
}

int main() {
    int arr[5];
    initialize_array(arr, 5);
    print_array(arr, 5);
    printf("\n");
    set_value_at_index(arr, 2, 100);
    print_array(arr, 5);

    return 0;
}
