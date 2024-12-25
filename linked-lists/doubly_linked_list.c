#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

void insert_at_beginning(Node **head, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = *head;    // O novo nó aponta para o antigo primeiro nó
    new_node->prev = NULL;     // O novo nó não tem nó anterior (porque é o primeiro)

    if (*head != NULL) {       // Se a lista não estiver vazia
        (*head)->prev = new_node;  // O antigo primeiro nó aponta para o novo nó
    }

    *head = new_node;         // Atualiza a cabeça da lista para o novo nó
}

// Função para imprimir a lista (da cabeça até o final)
void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Função para imprimir a lista de trás para frente
void print_list_reverse(Node *head) {
    // Primeiro, vá até o final da lista
    Node *current = head;
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }

    // Agora, percorre a lista de trás para frente
    while (current != NULL) {
        printf("%d <-> ", current->value);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);

    printf("Lista (da frente para tras):\n");
    print_list(head);

    printf("Lista (de tras para frente):\n");
    print_list_reverse(head);

    return 0;
}
