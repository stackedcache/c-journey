# Pointers Challenges

Each challenge reinforces key pointer concepts. Try to solve them **without** looking up anything. Only ask for help if you're completely stuck.

---

## Challenge 1: Swapping Values Using Pointers

Write a function that swaps two integers **using pointers**.

### Task:
1. Create a function `swap(int *a, int *b)` that swaps the values of `a` and `b`.
2. Call this function in `main()`, passing two variables.
3. Print the values before and after swapping.

### Expected Output:

```
Before swap: x = 10, y = 20 
After swap: x = 20, y = 10
```

**Key Concept:** Using pointers to modify values inside a function.

---

## Challenge 2: Reverse an Array Using Pointers

Reverse an integer array **in place** using pointer arithmetic.

### Task:
1. Write a function `reverseArray(int *arr, int size)`.
2. Swap the first and last elements, the second and second-last, etc.
3. Print the array before and after reversing.

### Example:

```c
int numbers[] = {1, 2, 3, 4, 5};
reverseArray(numbers, 5);
```

