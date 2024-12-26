#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct MinHeap {
    int arr[MAX];
    int size;
} MinHeap;

// Complexity: O(1)
MinHeap* create_min_heap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->size = 0;
    return heap;
}

// Complexity: O(log n)
void insert(MinHeap* heap, int value) {
    if (heap->size == MAX) {
        printf("Heap overflow\n");
        return;
    }

    heap->arr[heap->size] = value;
    int index = heap->size;
    heap->size++;

    while (index > 0 && heap->arr[index] < heap->arr[(index - 1) / 2]) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[(index - 1) / 2];
        heap->arr[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// Complexity: O(log n)
int extract_min(MinHeap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow\n");
        return -1;
    }

    int min_value = heap->arr[0];
    heap->size--;
    heap->arr[0] = heap->arr[heap->size];

    int index = 0;
    while (index * 2 + 1 < heap->size) {
        int left_child = index * 2 + 1;
        int right_child = index * 2 + 2;
        int smallest = index;

        if (left_child < heap->size && heap->arr[left_child] < heap->arr[smallest]) {
            smallest = left_child;
        }
        if (right_child < heap->size && heap->arr[right_child] < heap->arr[smallest]) {
            smallest = right_child;
        }
        if (smallest == index) {
            break;
        }

        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        index = smallest;
    }

    return min_value;
}

// Complexity: O(log n)
void heapify(MinHeap* heap, int index) {
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int smallest = index;

    if (left_child < heap->size && heap->arr[left_child] < heap->arr[smallest]) {
        smallest = left_child;
    }
    if (right_child < heap->size && heap->arr[right_child] < heap->arr[smallest]) {
        smallest = right_child;
    }

    if (smallest != index) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[smallest];
        heap->arr[smallest] = temp;
        heapify(heap, smallest);
    }
}

// Complexity: O(n)
void print_heap(MinHeap* heap) {
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
    MinHeap* heap = create_min_heap();

    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 5);
    insert(heap, 30);
    insert(heap, 15);

    printf("Min-Heap after inserts:\n");
    print_heap(heap);

    printf("Extracted Min: %d\n", extract_min(heap));

    printf("Min-Heap after extractMin:\n");
    print_heap(heap);

    heapify(heap, 0);

    printf("Min-Heap after heapify:\n");
    print_heap(heap);

    return 0;
}
