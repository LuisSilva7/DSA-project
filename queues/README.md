# Queue Operations in C

This repository contains four C programs demonstrating different queue operations. These programs cover **Queue using an array**, **Circular Queue using an array**, **Queue using a linked list**, and **Priority Queue**.

## Queue using Array

- **`create_queue`**: Creates a new queue with a fixed maximum size.
- **`enqueue`**: Adds an element to the end of the queue.
- **`dequeue`**: Removes and returns the front element from the queue.
- **`peek`**: Returns the front element of the queue without removing it.
- **`is_empty`**: Checks if the queue is empty.
- **`is_full`**: Checks if the queue is full.
- **`print_queue`**: Prints all elements in the queue from front to rear.

**Complexity:**

- `create_queue`: O(1)
- `enqueue`: O(1)
- `dequeue`: O(1)
- `peek`: O(1)
- `is_empty`: O(1)
- `is_full`: O(1)
- `print_queue`: O(n)

### Description:

This implementation uses a static array to represent the queue. The queue is managed with a fixed size, and basic operations such as enqueue, dequeue, and peek are implemented with constant time complexity.

## Circular Queue using Array

- **`create_queue`**: Creates a new circular queue with a fixed maximum size.
- **`enqueue`**: Adds an element to the rear of the queue while handling the wrap-around.
- **`dequeue`**: Removes and returns the front element from the queue.
- **`peek`**: Returns the front element without removing it.
- **`is_empty`**: Checks if the queue is empty.
- **`is_full`**: Checks if the queue is full.
- **`print_queue`**: Prints all elements in the circular queue.

**Complexity:**

- `create_queue`: O(1)
- `enqueue`: O(1)
- `dequeue`: O(1)
- `peek`: O(1)
- `is_empty`: O(1)
- `is_full`: O(1)
- `print_queue`: O(n)

### Description:

In this implementation, we use a circular queue with an array to efficiently handle wrap-around when the front of the queue reaches the end of the array. This avoids the issue of wasting space in the array.

## Queue using Linked List

- **`create_queue`**: Creates a new queue using a linked list.
- **`enqueue`**: Adds an element to the rear of the queue.
- **`dequeue`**: Removes and returns the front element of the queue.
- **`peek`**: Returns the front element without removing it.
- **`is_empty`**: Checks if the queue is empty.

**Complexity:**

- `create_queue`: O(1)
- `enqueue`: O(1)
- `dequeue`: O(1)
- `peek`: O(1)
- `is_empty`: O(1)

### Description:

This implementation uses a linked list to represent the queue. Each element is dynamically allocated as a node, allowing efficient enqueue and dequeue operations without the need for a fixed-size array.

## Priority Queue

- **`create_priority_queue`**: Creates a new priority queue.
- **`insert`**: Inserts an element into the priority queue while maintaining the heap property (Min-Heap).
- **`extract_min`**: Removes and returns the smallest element (highest priority).
- **`extract_max`**: Removes and returns the largest element (lowest priority).
- **`peek`**: Returns the smallest element without removing it.
- **`print_priority_queue`**: Prints all elements in the priority queue.

**Complexity:**

- `create_priority_queue`: O(1)
- `insert`: O(n)
- `extract_min`: O(n)
- `extract_max`: O(1)
- `peek`: O(1)
- `print_priority_queue`: O(n)

### Description:

This implementation uses an array to represent a **Min-Heap** priority queue. The smallest element has the highest priority and is always at the front. Insertion and extraction are done while maintaining the heap property. The time complexity for insertion and extraction is O(n) due to shifting elements in the array.

## Comparison

| Queue Type                 | Time Complexity | Best Case | Average Case | Worst Case |
| -------------------------- | --------------- | --------- | ------------ | ---------- |
| **Queue (Array)**          | O(1)            | O(1)      | O(1)         | O(1)       |
| **Circular Queue (Array)** | O(1)            | O(1)      | O(1)         | O(1)       |
| **Queue (Linked List)**    | O(1)            | O(1)      | O(1)         | O(1)       |
| **Priority Queue**         | O(n)            | O(1)      | O(n)         | O(n)       |

- **Queue (Array)**: Uses a static array with a fixed size, providing fast O(1) time complexity for all operations, but limited to the array size.
- **Circular Queue (Array)**: A variation of the queue using a circular array, efficiently handling wrap-arounds without wasting space.
- **Queue (Linked List)**: A dynamic queue where elements are linked together. It provides constant time complexity for enqueue and dequeue operations without a fixed size.
- **Priority Queue**: Implements a Min-Heap where the smallest element has the highest priority. The insertion and extraction operations take O(n) time due to the need to maintain the heap property.

These implementations showcase different approaches to queue operations in C, each with its own set of advantages depending on the use case.
