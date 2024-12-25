#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

// FIFO
typedef struct Stack {
    Node *top;
} Stack;

Stack* create_stack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

// Função para empilhar (adicionar um elemento no topo da pilha)
void push(Stack *s, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = s->top; // O próximo nó será o antigo topo da pilha
    s->top = new_node;       // Atualiza o topo para o novo nó
}

// Função para desempilhar (remover o elemento do topo da pilha)
int pop(Stack *s) {
    if (s->top == NULL) {
        printf("Pilha vazia. Nada para remover.\n");
        return -1; // Retorna um valor de erro se a pilha estiver vazia
    }

    Node *temp = s->top;
    int value = temp->value;
    s->top = s->top->next; // Atualiza o topo para o próximo nó

    free(temp); // Libera a memória do nó removido
    return value; // Retorna o valor do nó desempilhado
}

// Função para verificar o topo da pilha sem remover
int peek(Stack *s) {
    if (s->top == NULL) {
        printf("Pilha vazia.\n");
        return -1; // Retorna um valor de erro se a pilha estiver vazia
    }
    return s->top->value; // Retorna o valor do topo
}

// Função para verificar se a pilha está vazia
int is_empty(Stack *s) {
    return s->top == NULL;
}

// Função para exibir os elementos da pilha
void print_stack(Stack *s) {
    if (s->top == NULL) {
        printf("Pilha vazia.\n");
        return;
    }

    Node *current = s->top;
    printf("Topo da pilha:\n");
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

int main() {
    // Criando uma pilha
    Stack *s = create_stack();

    // Empilhando elementos
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);

    // Imprimindo a pilha
    printf("Pilha após empilhar 10, 20, 30 e 40:\n");
    print_stack(s);

    // Desempilhando elementos
    printf("\nElemento desempilhado: %d\n", pop(s));
    printf("Elemento desempilhado: %d\n", pop(s));

    // Imprimindo a pilha após as remoções
    printf("\nPilha após desempilhar dois elementos:\n");
    print_stack(s);

    // Empilhando mais um elemento
    push(s, 50);
    printf("\nPilha após empilhar 50:\n");
    print_stack(s);

    // Verificando o topo da pilha
    printf("\nTopo da pilha: %d\n", peek(s));

    return 0;
}
