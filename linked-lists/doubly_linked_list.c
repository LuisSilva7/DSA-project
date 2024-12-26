#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);

    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

int traverse(Node *head) {
    Node *current = head;
    int count = 0;

    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void insert_at_beginning(Node **head, int value) {
    Node *new_node = create_node(value);

    // if list is empty
    if(*head == NULL) {
        *head = new_node;
    } else {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
    }
}

void insert_at_middle(Node **head, int value) {
    Node *new_node = create_node(value);
    Node *current = *head;
    int size = traverse(*head);
    int mid = size / 2;

    for (int i = 0; i < mid - 1; i++) { 
        current = current->next;
    }

    new_node->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new_node;
    }
    new_node->prev = current;
    current->next = new_node;
}

void insert_at_end(Node **head, int value) {
    Node *new_node = create_node(value);
    Node *current = *head;

    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void delete(Node **head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node *current = *head;

    if (current->data == value) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    while (current != NULL && current->data != value) {
        current = current->next;
    }

    Node *prev = current->prev;
    Node *next = current->next;

    if (prev != NULL) {
        prev->next = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }

    free(current);
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
    print_list(head);
    insert_at_end(&head, 40);
    insert_at_middle(&head, 100);
    print_list(head);
    
    delete(&head, 100);
    print_list(head);

    return 0;
}