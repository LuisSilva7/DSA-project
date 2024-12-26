# Sorting Algorithms in C

This repository contains several C programs demonstrating sorting algorithms: **Bubble Sort**, **Quick Sort**, **Insertion Sort**, **Merge Sort**, and **Selection Sort**.

## Bubble Sort

- **`bubbleSort`**: Sorts an array by repeatedly swapping adjacent elements if they are in the wrong order.

**Complexity:**

- `bubbleSort`: O(n^2)

### Description:

Bubble sort compares adjacent elements in the array and swaps them if they are in the wrong order. This process is repeated for each element until the array is sorted. It's easy to implement but inefficient for large datasets.

## Quick Sort

- **`quickSort`**: Sorts an array by selecting a pivot element and partitioning the array into two sub-arrays, sorting them recursively.

**Complexity:**

- `quickSort`: O(n log n) average, O(n^2) worst case

### Description:

Quick sort is a divide-and-conquer algorithm. It selects a pivot element and partitions the array into two parts, one with elements less than the pivot and one with elements greater than the pivot. The sub-arrays are sorted recursively. While its average time complexity is O(n log n), its worst-case complexity can be O(n^2) if the pivot is poorly chosen.

## Insertion Sort

- **`insertionSort`**: Sorts an array by repeatedly inserting an element into its correct position within the sorted portion of the array.

**Complexity:**

- `insertionSort`: O(n^2)

### Description:

Insertion sort builds the sorted array one element at a time. It assumes that the first element is already sorted, then iteratively inserts the next element into its correct position. It is efficient for small datasets or nearly sorted arrays but has poor performance for large unsorted arrays.

## Merge Sort

- **`mergeSort`**: Sorts an array by dividing it into two halves, sorting each half recursively, and then merging the sorted halves.

**Complexity:**

- `mergeSort`: O(n log n)

### Description:

Merge sort is a divide-and-conquer algorithm that divides the array into two halves, sorts each half, and merges them back together in sorted order. It guarantees O(n log n) time complexity in all cases and is very efficient, especially for large datasets.

## Selection Sort

- **`selectionSort`**: Sorts an array by repeatedly finding the minimum element from the unsorted portion of the array and moving it to the sorted portion.

**Complexity:**

- `selectionSort`: O(n^2)

### Description:

Selection sort works by finding the smallest (or largest) element in the unsorted portion of the array and swapping it with the first unsorted element. It performs poorly on large lists due to its O(n^2) time complexity but is easy to implement.

---

## Comparison

| Algorithm          | Time Complexity | Best Case  | Average Case | Worst Case |
| ------------------ | --------------- | ---------- | ------------ | ---------- |
| **Bubble Sort**    | O(n^2)          | O(n)       | O(n^2)       | O(n^2)     |
| **Quick Sort**     | O(n log n)      | O(n log n) | O(n log n)   | O(n^2)     |
| **Insertion Sort** | O(n^2)          | O(n)       | O(n^2)       | O(n^2)     |
| **Merge Sort**     | O(n log n)      | O(n log n) | O(n log n)   | O(n log n) |
| **Selection Sort** | O(n^2)          | O(n^2)     | O(n^2)       | O(n^2)     |

### Summary:

- **Bubble Sort**: Simple but inefficient, O(n^2) time complexity in all cases.
- **Quick Sort**: Efficient for large datasets, O(n log n) on average but can degrade to O(n^2) in the worst case.
- **Insertion Sort**: Best for small or nearly sorted datasets, O(n^2) complexity.
- **Merge Sort**: Very efficient with O(n log n) time complexity in all cases.
- **Selection Sort**: Simple but inefficient for large datasets, with O(n^2) complexity.

These sorting algorithms demonstrate a variety of approaches to sorting data, from simple, easy-to-understand algorithms like Bubble Sort and Selection Sort to more efficient and complex algorithms like Merge Sort and Quick Sort.
