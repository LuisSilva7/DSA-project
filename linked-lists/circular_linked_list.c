#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
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
    new_node->prev = new_node;
    new_node->next = new_node;

    return new_node;
}

// Complexity: O(n)
int traverse(Node *head) {
    Node *current = head;
    int count = 0;

    if (head != NULL) {
        do {
            count++;
            current = current->next;
        } while(current != head);
    }

    return count;
}

// Complexity: O(1)
void insert_at_beginning(Node **head, int value) {
    Node *new_node = create_node(value);

    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        new_node->prev = (*head)->prev;
        (*head)->prev->next = new_node;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

// Complexity: O(n)
void insert_at_middle(Node **head, int value) {
    Node *new_node = create_node(value);
    Node *current = *head;
    int size = traverse(*head);
    int mid = size / 2;

    for (int i = 0; i < mid; i++) { 
        current = current->next;
    }

    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;
}

// Complexity: O(n)
void insert_at_end(Node **head, int value) {
    Node *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        new_node->prev = (*head)->prev;
        (*head)->prev->next = new_node;
        (*head)->prev = new_node;
    }
}

// Complexity: O(n)
void delete(Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = *head;

    do {
        if (current->data == value) {
            if (current == *head) {
                *head = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
        current = current->next;
    } while (current != *head);
}

// Complexity: O(n)
void print_list(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = head;
    printf("List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while(current != head);
    printf("(head)\n");
}

int main() {
    Node *head = NULL;

    insert_at_beginning(&head, 30);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 10);
    print_list(head);
    insert_at_end(&head, 40);
    insert_at_middle(&head, 100);
    print_list(head);
    
    delete(&head, 100);
    print_list(head);

    return 0;
}
