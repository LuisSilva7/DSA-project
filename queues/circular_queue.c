#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Queue {
    int arr[MAX];
    int front, rear;
} Queue;

// Complexity: O(1)
Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = -1;
    return q;
}

// Complexity: O(1)
int is_empty(Queue* q) {
    return q->front == -1;
}

// Complexity: O(1)
int is_full(Queue* q) {
    return (q->rear + 1) % MAX == q->front;
}

// Complexity: O(1)
void enqueue(Queue* q, int value) {
    if (is_full(q)) {
        printf("Queue Overflow. Cannot enqueue %d\n", value);
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = value;
}

// Complexity: O(1)
int dequeue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue Underflow. Nothing to dequeue.\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    return value;
}

// Complexity: O(1)
int peek(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->arr[q->front];
}

// Complexity: O(n)
void print_queue(Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    int i = q->front;
    printf("Queue from front to rear:\n");
    while (i != q->rear) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", q->arr[q->rear]);
}

int main() {
    Queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Queue after enqueueing 10, 20, 30, 40, and 50:\n");
    print_queue(q);

    printf("\nDequeued element: %d\n", dequeue(q));
    printf("Dequeued element: %d\n", dequeue(q));

    printf("\nQueue after dequeuing two elements:\n");
    print_queue(q);

    enqueue(q, 60);
    printf("\nQueue after enqueueing 60:\n");
    print_queue(q);

    printf("\nFront of the queue: %d\n", peek(q));

    return 0;
}
