#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct MaxHeap {
    int arr[MAX];
    int size;
} MaxHeap;

// Complexity: O(1)
MaxHeap* create_max_heap() {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->size = 0;
    return heap;
}

// Complexity: O(log n)
void insert(MaxHeap* heap, int value) {
    if (heap->size == MAX) {
        printf("Heap overflow\n");
        return;
    }

    heap->arr[heap->size] = value;
    int index = heap->size;
    heap->size++;

    while (index > 0 && heap->arr[index] > heap->arr[(index - 1) / 2]) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[(index - 1) / 2];
        heap->arr[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Complexity: O(log n)
int extract_max(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow\n");
        return -1;
    }

    int max_value = heap->arr[0];
    heap->size--;
    heap->arr[0] = heap->arr[heap->size];

    int index = 0;
    while (index * 2 + 1 < heap->size) {
        int left_child = index * 2 + 1;
        int right_child = index * 2 + 2;
        int largest = index;

        if (left_child < heap->size && heap->arr[left_child] > heap->arr[largest]) {
            largest = left_child;
        }
        if (right_child < heap->size && heap->arr[right_child] > heap->arr[largest]) {
            largest = right_child;
        }
        if (largest == index) {
            break;
        }

        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        index = largest;
    }

    return max_value;
}

// Complexity: O(log n)
void heapify(MaxHeap* heap, int index) {
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int largest = index;

    if (left_child < heap->size && heap->arr[left_child] > heap->arr[largest]) {
        largest = left_child;
    }
    if (right_child < heap->size && heap->arr[right_child] > heap->arr[largest]) {
        largest = right_child;
    }

    if (largest != index) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        heapify(heap, largest);
    }
}

// Complexity: O(n)
void print_heap(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return;
    }

    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int main() {
    MaxHeap* heap = create_max_heap();

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 5);
    insert(heap, 30);
    insert(heap, 15);

    printf("Max-Heap after inserts:\n");
    print_heap(heap);

    printf("Extracted Max: %d\n", extract_max(heap));

    printf("Max-Heap after extractMax:\n");
    print_heap(heap);

    heapify(heap, 0);

    printf("Max-Heap after heapify:\n");
    print_heap(heap);

    return 0;
}
