#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void preorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);   // Visita a raiz
    preorder_traversal(root->left);  // Percorre a subárvore esquerda
    preorder_traversal(root->right); // Percorre a subárvore direita
}

void inorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);  // Percorre a subárvore esquerda
    printf("%d ", root->value);   // Visita a raiz
    inorder_traversal(root->right); // Percorre a subárvore direita
}

void postorder_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);  // Percorre a subárvore esquerda
    postorder_traversal(root->right); // Percorre a subárvore direita
    printf("%d ", root->value);   // Visita a raiz
}

int main() {
    Node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    /*
       Estrutura da árvore criada:
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
    */

   printf("Estrutura da arvore:\n");
   printf("     1\n");
   printf("   /   \\\n");
   printf("  2     3\n");
   printf(" / \\   / \\\n");
   printf("4   5 6   7\n");

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
