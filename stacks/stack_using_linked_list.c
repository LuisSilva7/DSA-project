#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

// Complexity: O(1)
Stack* create_stack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Complexity: O(1)
void push(Stack* s, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = s->top;
    s->top = new_node;
}

// Complexity: O(1)
int pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow. Nothing to pop.\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->value;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Complexity: O(1)
int peek(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->top->value;
}

// Complexity: O(1)
int is_empty(Stack* s) {
    return s->top == NULL;
}

// Complexity: O(n)
void print_stack(Stack* s) {
    if (s->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack from top to bottom:\n");
    Node* current = s->top;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main() {
    Stack* s = create_stack();

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);

    printf("Stack after pushing 10, 20, 30, and 40:\n");
    print_stack(s);

    printf("\nPopped element: %d\n", pop(s));
    printf("Popped element: %d\n", pop(s));

    printf("\nStack after popping two elements:\n");
    print_stack(s);

    push(s, 50);
    printf("\nStack after pushing 50:\n");
    print_stack(s);

    printf("\nTop of the stack: %d\n", peek(s));

    return 0;
}
