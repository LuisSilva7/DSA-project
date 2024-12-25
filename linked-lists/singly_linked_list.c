#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node)); // aloca 16 bytes (int 4; ptr 8; alinhamento 4)
    if (new_node == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void insert_at_beginning(Node **head, int value) {
    Node *new_node = create_node(value);
    new_node->next = *head; // Faz o novo nó apontar para o antigo primeiro nó
    *head = new_node;       // Atualiza o ponteiro cabeça para o novo nó
}

void insert_at_end(Node **head, int value) {
    Node *new_node = create_node(value);
    new_node->next = NULL;

    if (*head == NULL) {
        // Se a lista estiver vazia, o novo nó será o primeiro e único nó
        *head = new_node;
    } else {
        // Caso contrário, percorre até o último nó
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next; // Vai para o próximo nó até encontrar o último
        }
        current->next = new_node; // Conecta o novo nó ao final da lista
    }
}

void remove_first(Node **head) {
    if (*head == NULL) {
        printf("A lista esta vazia. Nada para remover.\n");
        return;
    }
    Node *temp = *head;     // Salva o nó atual
    *head = (*head)->next;  // Atualiza a cabeça para o próximo nó
    free(temp);             // Libera a memória do nó removido
    printf("Primeiro no removido.\n");
}

void remove_last(Node **head) {
    if (*head == NULL) {
        printf("A lista esta vazia. Nada para remover.\n");
        return;
    }

    // Caso a lista tenha apenas um nó
    if ((*head)->next == NULL) {
        free(*head);        // Libera o único nó
        *head = NULL;       // Atualiza a cabeça da lista para NULL (lista vazia)
        printf("Ultimo no removido. A lista agora esta vazia.\n");
        return;
    }

    // Caso contrário, percorre até o último nó
    Node *current = *head;
    Node *prev = NULL;
    while (current->next != NULL) {  // Vai para o próximo nó até encontrar o último
        prev = current; // Nó anterior
        current = current->next; // Nó atual
    }
    
    prev->next = NULL;  // O penúltimo nó fica sem "next"
    free(current);      // O último nó é removido
    printf("Ultimo no removido.\n");
}

void print_list(Node *head) {
    if (head == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }
    Node *current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; // Avança para o próximo nó
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    print_list(head);

    remove_last(&head);
    print_list(head);

    remove_first(&head);
    print_list(head);

    remove_first(&head);
    print_list(head);

    return 0;
}
