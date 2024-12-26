# Binary Tree and Binary Search Tree in C

This repository contains two C programs demonstrating operations on **Binary Tree** and **Binary Search Tree (BST)**.

## Binary Tree

- **`insert`**: Inserts a new value into the binary tree.
- **`search`**: Searches for a value in the binary tree.
- **`delete`**: Deletes a node with a given value from the binary tree.
- **`findMin`**: Finds the node with the minimum value in the binary tree.
- **`findMax`**: Finds the node with the maximum value in the binary tree.
- **`height`**: Returns the height of the binary tree.
- **`inorder`**: Traverses the tree in an inorder manner (left, root, right) and prints the node values.

### Time Complexities:

- `insert`: O(log n) average case, O(n) worst case
- `search`: O(log n) average case, O(n) worst case
- `findMin`: O(n)
- `findMax`: O(n)
- `delete`: O(log n) average case, O(n) worst case
- `height`: O(n)
- `inorder`: O(n)

### Description:

A binary tree is a tree data structure where each node has at most two children, referred to as the left child and the right child. The operations on a binary tree include inserting new nodes, searching for values, deleting nodes, and traversing the tree in different ways (inorder, preorder, postorder).

## Binary Search Tree (BST)

- **`insert`**: Inserts a value into the binary search tree (BST).
- **`search`**: Searches for a value in the BST.
- **`delete`**: Deletes a node with a given value from the BST.
- **`findMin`**: Finds the node with the minimum value in the BST.
- **`findMax`**: Finds the node with the maximum value in the BST.
- **`height`**: Returns the height of the BST.

### Time Complexities:

- `insert`: O(log n) average case, O(n) worst case
- `search`: O(log n) average case, O(n) worst case
- `findMin`: O(log n) average case, O(n) worst case
- `findMax`: O(log n) average case, O(n) worst case
- `delete`: O(log n) average case, O(n) worst case
- `height`: O(n)

### Description:

A Binary Search Tree (BST) is a binary tree in which all the nodes follow a specific order: for every node, the left subtree contains values smaller than the node, and the right subtree contains values greater than the node. This property allows for more efficient searching, insertion, and deletion operations compared to a regular binary tree.

### Comparison:

| Operation    | Binary Tree Time Complexity | Binary Search Tree Time Complexity |
| ------------ | --------------------------- | ---------------------------------- |
| **Insert**   | O(n)                        | O(log n) average, O(n) worst case  |
| **Search**   | O(n)                        | O(log n) average, O(n) worst case  |
| **Delete**   | O(n)                        | O(log n) average, O(n) worst case  |
| **Find Min** | O(n)                        | O(log n) average, O(n) worst case  |
| **Find Max** | O(n)                        | O(log n) average, O(n) worst case  |
| **Height**   | O(n)                        | O(n)                               |

These programs demonstrate the basic operations of binary trees and binary search trees, highlighting their differences in structure and efficiency for common operations such as insertion, searching, and deletion.
