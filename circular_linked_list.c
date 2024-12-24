#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void insert_at_beginning(Node **head, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    
    if (*head == NULL) {
        // Se a lista estiver vazia, o novo nó aponta para si mesmo
        new_node->next = new_node;
        *head = new_node;
    } else {
        // Se a lista não estiver vazia, o novo nó se torna o primeiro e aponta para o antigo primeiro nó
        new_node->next = *head;
        
        // Atualiza o último nó para apontar para o novo primeiro nó
        Node *temp = *head;
        while (temp->next != *head) {  // Percorre até o último nó
            temp = temp->next;
        }
        temp->next = new_node;  // O último nó aponta para o novo nó
        *head = new_node;       // Atualiza a cabeça da lista
    }
}

void print_list(Node *head) {
    if (head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    
    Node *current = head;
    do {
        printf("%d -> ", current->value);
        current = current->next;
    } while (current != head);  // Quando voltar para o primeiro nó, o loop para

    printf("(circular)\n");
}

int main() {
    Node *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);
    insert_at_beginning(&head, 40);

    print_list(head);

    return 0;
}
