#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Complexity: O(1)
Stack* create_stack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

// Complexity: O(1)
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow. Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
}

// Complexity: O(1)
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow. Nothing to pop.\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Complexity: O(1)
int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[s->top];
}

// Complexity: O(1)
int is_empty(Stack *s) {
    return s->top == -1;
}

// Complexity: O(1)
int is_full(Stack *s) {
    return s->top == MAX - 1;
}

 // Complexity: O(n)
void print_stack(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack from top to bottom:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    Stack *s = create_stack();

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
