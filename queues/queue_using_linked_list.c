#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

// Complexity: O(1)
Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Complexity: O(1)
void enqueue(Queue* q, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

// Complexity: O(1)
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow. Nothing to dequeue.\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->value;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Complexity: O(1)
int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->value;
}

// Complexity: O(1)
int is_empty(Queue* q) {
    return q->front == NULL;
}

// Complexity: O(n)
void print_queue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    Node* current = q->front;
    printf("Queue from front to rear:\n");
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
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
