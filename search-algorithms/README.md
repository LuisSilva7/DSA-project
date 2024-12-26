# Search Algorithms in C

This repository contains two C programs demonstrating search algorithms: **Linear Search** and **Binary Search**.

## Linear Search

- **`linearSearch`**: Performs a linear search on an array to find the first occurrence of a target value.

**Complexity:**

- `linearSearch`: O(n)

### Description:

Linear search sequentially checks each element in the array until it finds the target value or reaches the end of the array. If the element is found, it returns the index; otherwise, it returns -1.

## Binary Search

- **`binarySearch`**: Performs a binary search on a **sorted** array to find the target value.

**Complexity:**

- `binarySearch`: O(log n)

### Description:

Binary search works by repeatedly dividing the search interval in half. If the value of the target is less than the value in the middle of the interval, it narrows the interval to the lower half. If the target is greater, it narrows it to the upper half. This process continues until the target value is found or the interval is empty. Binary search requires a sorted array.

## Comparison

| Algorithm         | Time Complexity | Best Case | Average Case | Worst Case |
| ----------------- | --------------- | --------- | ------------ | ---------- |
| **Linear Search** | O(n)            | O(1)      | O(n)         | O(n)       |
| **Binary Search** | O(log n)        | O(1)      | O(log n)     | O(log n)   |

- **Linear Search**: Works on unsorted arrays, but has a linear time complexity (O(n)).
- **Binary Search**: Requires the array to be sorted but has a much more efficient time complexity of O(log n).

These algorithms demonstrate fundamental search techniques, highlighting the difference between the simplicity and efficiency of Linear Search and the more complex but faster Binary Search for sorted arrays.
