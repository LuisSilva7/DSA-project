#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int arr[MAX];
    int front;
    int rear;
} Queue;

// Complexity: O(1)
Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Complexity: O(1)
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow. Cannot enqueue %d\n", value);
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++(q->rear)] = value;
}

// Complexity: O(1)
int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow. Nothing to dequeue.\n");
        return -1;
    }
    return q->arr[(q->front)++];
}

// Complexity: O(1)
int peek(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

// Complexity: O(1)
int is_empty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

// Complexity: O(1)
int is_full(Queue* q) {
    return q->rear == MAX - 1;
}

// Complexity: O(n)
void print_queue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue from front to rear:\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->arr[i]);
    }
}

int main() {
    Queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    printf("Queue after enqueueing 10, 20, 30, and 40:\n");
    print_queue(q);

    printf("\nDequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));

    printf("\nQueue after dequeuing two elements:\n");
    print_queue(q);

    enqueue(q, 50);
    printf("\nQueue after enqueueing 50:\n");
    print_queue(q);

    printf("\nFront of the queue: %d\n", peek(q));

    return 0;
}
