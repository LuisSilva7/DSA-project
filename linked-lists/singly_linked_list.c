#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Complexity: O(1)
Node *create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);

    }
    new_node->data = value;
    new_node->next = NULL;

    return new_node;
}

// Complexity: O(n)
int traverse(Node *head) {
    Node *current = head;
    int count = 0;

    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Complexity: O(1)
void insert_at_beginning(Node **head, int value) {
    Node *new_node = create_node(value);
    new_node->next = *head;
    *head = new_node;
}

// Complexity: O(n)
void insert_at_middle(Node **head, int value) {
    Node *new_node = create_node(value);
    Node *current = *head;
    int size = traverse(*head);
    int mid = size / 2;

    for (int i = 0; i < mid - 1; i++) { 
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

// Complexity: O(n)
void insert_at_end(Node **head, int value) {
    Node *new_node = create_node(value);
    Node *current = *head;

    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete(Node **head, int value) {
    Node *current = *head;
    Node *prev = NULL;

    if (current != NULL && current->data == value) {
        *head = current->next;
        free(current);
        current = NULL;
        return;
    }

    while(current->data != value) {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current);
    current = NULL;
}

void print_list(Node *head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    printf("List: ");
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insert_at_beginning(&head, 30);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 10);
    insert_at_end(&head, 40);
    insert_at_middle(&head, 100);
    print_list(head);
    
    delete(&head, 100);
    print_list(head);

    return 0;
}