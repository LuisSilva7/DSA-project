#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// FIFO
typedef struct Queue {
    Node *front, *rear;
} Queue;

Queue* create_queue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Função para enfileirar (adicionar elemento ao final da fila)
void enqueue(Queue *q, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    
    if (q->rear == NULL) {
        // Se a fila estiver vazia, o novo nó é o primeiro e o último nó
        q->front = q->rear = new_node;
        return;
    }
    
    // Caso contrário, o último nó aponta para o novo nó e o último nó é atualizado
    q->rear->next = new_node;
    q->rear = new_node;
}

// Função para desenfileirar (remover o elemento do início da fila)
int dequeue(Queue *q) {
    if (q->front == NULL) {
        printf("Fila vazia, nao ha nada para remover.\n");
        return -1;  // Indicando que a fila está vazia
    }

    Node *temp = q->front;
    int value = temp->value;
    q->front = q->front->next;

    if (q->front == NULL) {
        // Se a fila ficar vazia, o último ponteiro também deve ser NULL
        q->rear = NULL;
    }

    free(temp);
    return value;
}

// Função para exibir os elementos da fila
void print_queue(Queue *q) {
    if (q->front == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    Node *current = q->front;
    while (current != NULL) {
        printf("%d <- ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Queue *q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // Imprimindo a fila
    printf("Fila após enfileirar 10, 20, 30 e 40:\n");
    print_queue(q);

    // Desenfileirando elementos
    printf("\nElemento desenfileirado: %d\n", dequeue(q));
    printf("Elemento desenfileirado: %d\n", dequeue(q));

    // Imprimindo a fila após as remoções
    printf("\nFila após desenfileirar dois elementos:\n");
    print_queue(q);

    // Enfileirando mais um elemento
    enqueue(q, 50);
    printf("\nFila após enfileirar 50:\n");
    print_queue(q);

    return 0;
}
