# Heap Algorithms in C

This repository contains C programs demonstrating heap operations and heap sort: **Min-Heap**, **Max-Heap**, and **Heap Sort**.

## Min-Heap Operations

- **`insert`**: Inserts a new element into the min-heap, ensuring the heap property is maintained.
- **`delete`**: Removes the root element (minimum element) from the min-heap, adjusting the heap structure.
- **`heapify`**: Maintains the min-heap property by recursively adjusting elements.
- **`extractMin`**: Extracts the minimum element from the heap and reorganizes the heap.

**Complexity:**

- `insert`: O(log n)
- `delete`: O(log n)
- `heapify`: O(log n)
- `extractMin`: O(log n)

### Description:

Min-Heap is a binary tree where the value of each parent node is less than or equal to its children. This allows quick access to the minimum element, which is always at the root.

## Max-Heap Operations

- **`insert`**: Inserts a new element into the max-heap while maintaining the heap property.
- **`delete`**: Removes the root element (maximum element) from the max-heap and reorganizes the heap.
- **`heapify`**: Adjusts elements to maintain the max-heap property.
- **`extractMax`**: Extracts the maximum element from the heap and reorganizes it.

**Complexity:**

- `insert`: O(log n)
- `delete`: O(log n)
- `heapify`: O(log n)
- `extractMax`: O(log n)

### Description:

Max-Heap is a binary tree where each parent node's value is greater than or equal to the values of its children. The largest element is always at the root, enabling efficient extraction of the maximum element.

## Heap Sort

- **`heapSortAscending`**: Sorts the array in ascending order using a max-heap.
- **`heapSortDescending`**: Sorts the array in descending order by first sorting in ascending order and then reversing the array.

**Complexity:**

- `heapSortAscending`: O(n log n)
- `heapSortDescending`: O(n log n)

### Description:

Heap sort is an efficient comparison-based sorting algorithm that utilizes the heap data structure. The array is first converted into a max-heap, and then the root element is repeatedly swapped with the last element to sort the array in ascending order. For descending order, the array is reversed after sorting.

## Comparison

| Algorithm           | Time Complexity | Best Case  | Average Case | Worst Case |
| ------------------- | --------------- | ---------- | ------------ | ---------- |
| **Min-Heap Insert** | O(log n)        | O(1)       | O(log n)     | O(log n)   |
| **Max-Heap Insert** | O(log n)        | O(1)       | O(log n)     | O(log n)   |
| **Heap Sort**       | O(n log n)      | O(n log n) | O(n log n)   | O(n log n) |

These algorithms demonstrate the core operations of heaps (insertion, deletion, and heapify) and how they are used in sorting arrays efficiently. The programs also highlight the difference between Min-Heaps and Max-Heaps, as well as the implementation of Heap Sort in both ascending and descending order.
