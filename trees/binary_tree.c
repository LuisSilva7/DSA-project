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
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Complexity: O(log n) on average, O(n) in the worst case (unbalanced tree)
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Complexity: O(log n) on average, O(n) in the worst case (unbalanced tree)
Node* search(Node* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }

    if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

Node* find_min(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Complexity: O(log n) on average, O(n) in the worst case (unbalanced tree)
Node* delete(Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->value) {
        root->left = delete(root->left, value);
    } else if (value > root->value) {
        root->right = delete(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = find_min(root->right);
        root->value = temp->value;
        root->right = delete(root->right, temp->value);
    }

    return root;
}

// Preorder traversal (Root, Left, Right)
// Complexity: O(n)
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal (Left, Root, Right)
// Complexity: O(n)
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
// Complexity: O(n)
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    int search_value = 40;
    Node* result = search(root, search_value);
    if (result != NULL) {
        printf("Node %d found in the tree.\n", result->value);
    } else {
        printf("Node %d not found in the tree.\n", search_value);
    }

    printf("Deleting node with value 20.\n");
    root = delete(root, 20);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
