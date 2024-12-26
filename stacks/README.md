# Stack Operations in C

This repository contains two C programs demonstrating stack operations: **Stack using an array** and **Stack using a linked list**.

## Stack using Array

- **`create_stack`**: Creates a new stack with a fixed maximum size.
- **`push`**: Adds an element to the top of the stack.
- **`pop`**: Removes and returns the top element of the stack.
- **`peek`**: Returns the top element of the stack without removing it.
- **`is_empty`**: Checks if the stack is empty.
- **`is_full`**: Checks if the stack is full.
- **`print_stack`**: Prints all elements in the stack from top to bottom.

**Complexity:**

- `create_stack`: O(1)
- `push`: O(1)
- `pop`: O(1)
- `peek`: O(1)
- `is_empty`: O(1)
- `is_full`: O(1)
- `print_stack`: O(n)

### Description:

This implementation uses a static array to represent the stack. The stack is managed with a fixed size, and basic operations such as push, pop, and peek are implemented with constant time complexity.

## Stack using Linked List

- **`create_stack`**: Creates a new stack using a linked list.
- **`push`**: Adds an element to the top of the stack.
- **`pop`**: Removes and returns the top element of the stack.
- **`peek`**: Returns the top element of the stack without removing it.
- **`is_empty`**: Checks if the stack is empty.

**Complexity:**

- `create_stack`: O(1)
- `push`: O(1)
- `pop`: O(1)
- `peek`: O(1)
- `is_empty`: O(1)

### Description:

This implementation uses a linked list to represent the stack. Each element is dynamically allocated as a node, allowing efficient push and pop operations without the need for a fixed-size array. The stack can grow and shrink dynamically based on the number of elements.

## Comparison

| Stack Type              | Time Complexity | Best Case | Average Case | Worst Case |
| ----------------------- | --------------- | --------- | ------------ | ---------- |
| **Stack (Array)**       | O(1)            | O(1)      | O(1)         | O(1)       |
| **Stack (Linked List)** | O(1)            | O(1)      | O(1)         | O(1)       |

- **Stack (Array)**: Uses a static array with a fixed size, providing fast O(1) time complexity for all operations, but limited to the array size.
- **Stack (Linked List)**: A dynamic stack where elements are linked together. It provides constant time complexity for push and pop operations and can grow or shrink as needed.

These implementations demonstrate two different approaches to stack operations in C, with one using a fixed-size array and the other using a dynamic linked list.
