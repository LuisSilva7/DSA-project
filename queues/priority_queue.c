#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct PriorityQueue {
    int arr[MAX];
    int size;
} PriorityQueue;

// Complexity: O(1)
PriorityQueue* create_priority_queue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

// Complexity: O(1)
int is_empty(PriorityQueue* pq) {
    return pq->size == 0;
}

// Complexity: O(1)
int is_full(PriorityQueue* pq) {
    return pq->size == MAX;
}

// Complexity: O(n)
void insert(PriorityQueue* pq, int value) {
    if (is_full(pq)) {
        printf("Priority Queue Overflow. Cannot insert %d\n", value);
        return;
    }

    int i = pq->size - 1;
    while (i >= 0 && pq->arr[i] > value) {
        pq->arr[i + 1] = pq->arr[i];
        i--;
    }
    pq->arr[i + 1] = value;
    pq->size++;
}

// Complexity: O(1)
int extract_min(PriorityQueue* pq) {
    if (is_empty(pq)) {
        printf("Priority Queue Underflow. Nothing to extract.\n");
        return -1;
    }

    int min = pq->arr[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->arr[i] = pq->arr[i + 1];
    }
    pq->size--;
    return min;
}

// Complexity: O(1)
int extract_max(PriorityQueue* pq) {
    if (is_empty(pq)) {
        printf("Priority Queue Underflow. Nothing to extract.\n");
        return -1;
    }

    int max = pq->arr[pq->size - 1];
    pq->size--;
    return max;
}

// Complexity: O(1)
int peek(PriorityQueue* pq) {
    if (is_empty(pq)) {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    return pq->arr[0];
}

// Complexity: O(n)
void print_priority_queue(PriorityQueue* pq) {
    if (is_empty(pq)) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue (Min-Heap) from front to rear:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue* pq = create_priority_queue();

    insert(pq, 10);
    insert(pq, 20);
    insert(pq, 5);
    insert(pq, 15);
    insert(pq, 30);

    printf("Priority Queue after inserting 10, 20, 5, 15, and 30:\n");
    print_priority_queue(pq);

    printf("\nExtracted min: %d\n", extract_min(pq));
    printf("Extracted min: %d\n", extract_min(pq));

    printf("\nPriority Queue after extracting two mins:\n");
    print_priority_queue(pq);

    printf("\nPeek: %d\n", peek(pq));

    printf("\nExtracted max: %d\n", extract_max(pq));
    printf("\nPriority Queue after extracting max:\n");
    print_priority_queue(pq);

    return 0;
}
