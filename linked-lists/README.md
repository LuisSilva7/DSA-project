# Linked List Operations in C

This repository contains three C programs demonstrating operations on **Singly Linked Lists**, **Doubly Linked Lists**, and **Circular Linked Lists**.

## Singly Linked List Operations

- **`create_node`**: Creates a new node with the given value and sets the `next` pointer to `NULL`.
- **`traverse`**: Traverses the list and counts the number of nodes.
- **`insert_at_beginning`**: Inserts a new node at the beginning of the list, updating the head of the list.
- **`insert_at_middle`**: Inserts a new node at the middle position of the list based on the list's size.
- **`insert_at_end`**: Inserts a new node at the end of the list by traversing to the last node and appending the new node.
- **`delete`**: Deletes the first occurrence of a node with the given value.
- **`print_list`**: Prints all the nodes in the list, showing their values and the `next` pointers.

**Complexity:**

- `create_node`: O(1)
- `traverse`: O(n)
- `insert_at_beginning`: O(1)
- `insert_at_middle`: O(n)
- `insert_at_end`: O(n)
- `delete`: O(n)
- `print_list`: O(n)

## Doubly Linked List Operations

- **`create_node`**: Creates a new node with the given value and sets both `prev` and `next` pointers to `NULL`.
- **`traverse`**: Traverses the list and counts the number of nodes.
- **`insert_at_beginning`**: Inserts a new node at the beginning of the list, updating the head of the list and adjusting the `prev` and `next` pointers accordingly.
- **`insert_at_middle`**: Inserts a new node at the middle of the list, adjusting the `prev` and `next` pointers for the adjacent nodes.
- **`insert_at_end`**: Inserts a new node at the end of the list by traversing to the last node and updating the `prev` and `next` pointers.
- **`delete`**: Deletes the node with the given value, adjusting the `prev` and `next` pointers of the surrounding nodes.
- **`print_list`**: Prints all the nodes in the list, showing their values and the `next` and `prev` pointers.

**Complexity:**

- `create_node`: O(1)
- `traverse`: O(n)
- `insert_at_beginning`: O(1)
- `insert_at_middle`: O(n)
- `insert_at_end`: O(n)
- `delete`: O(n)
- `print_list`: O(n)

## Circular Linked List Operations

- **`create_node`**: Creates a new node with the given value and links it to itself (making it circular).
- **`traverse`**: Traverses the circular list and counts the number of nodes.
- **`insert_at_beginning`**: Inserts a new node at the beginning of the circular list, adjusting the `prev` and `next` pointers and updating the head.
- **`insert_at_middle`**: Inserts a new node at the middle of the circular list, updating the `prev` and `next` pointers of the surrounding nodes.
- **`insert_at_end`**: Inserts a new node at the end of the circular list, ensuring the last node's `next` pointer points back to the head.
- **`delete`**: Deletes the node with the given value from the circular list, handling edge cases like deleting the head node or an empty list.
- **`print_list`**: Prints all the nodes in the circular list, showing their values and the `next` pointer, and indicates the circular nature.

**Complexity:**

- `create_node`: O(1)
- `traverse`: O(n)
- `insert_at_beginning`: O(1)
- `insert_at_middle`: O(n)
- `insert_at_end`: O(n)
- `delete`: O(n)
- `print_list`: O(n)

---

These programs demonstrate basic operations for singly, doubly, and circular linked lists, highlighting node insertion, deletion, traversal, and printing operations in C.
