# Array Operations in C

This repository contains two C programs demonstrating operations on static and dynamic arrays.

## Static Array Operations

- **`initialize_array`**: Initializes a static array with values from 1 to `size`.
- **`print_array`**: Prints all elements of a static array.
- **`set_value_at_index`**: Sets a specific value at a given index in the array (with bounds checking).

**Complexity:**

- `initialize_array`: O(n)
- `print_array`: O(n)
- `set_value_at_index`: O(1)

## Dynamic Array Operations

- **`initialize_dynamic_array`**: Allocates memory for a dynamic array and initializes its values.
- **`print_dynamic_array`**: Prints all elements of a dynamic array.
- **`resize_dynamic_array`**: Resizes the dynamic array and initializes new elements if the new size is larger.
- **`free_dynamic_array`**: Frees the dynamically allocated memory for the array.

**Complexity:**

- `initialize_dynamic_array`: O(n)
- `print_dynamic_array`: O(n)
- `resize_dynamic_array`: O(n)
- `free_dynamic_array`: O(1)

This demonstrates basic array manipulation, memory management, and resizing techniques in C.
