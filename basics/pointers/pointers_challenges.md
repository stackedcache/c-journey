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

--- 

## Challenge 3: Pointer-Based String Length Calculator

**Task:**

1. Write a function `int strLength(char *str)` that calculates the length of a string without using strlen().
2. Use pointer arithmetic instead of array indexing.
3. Return the length of the string.

Example Usage: 

```C
printf("Length: %d\n", strLength("Hello / Здравствуйте!"));  // Output: 21
```

---

## Challenge 4: Pointer-Based String Copy (strcpy()) Clone 

**Task:**

1. Write `void strCopy(char *dest, char *src)` that copies a string from `src` to `dest` without using strcpy(). 
2. Use pointer arithmetic. 
3. Make sure to copy the null terminator `\0` at the end. 

Example Usage: 

```C
char source[] = "Hacker";
char destination[20];

strCopy(destination, source);
printf("Copied string: %s\n", destination);
```

---

## Challenge 5: Reverse a String Using Pointers 

**Task:**

1. Write `void reverseString(char* str)` that reverses a string in place using pointer swapping. 
2. Don't use extra arrays, modify the original string. 

Example Usage: 

```C
char word[] = "exploit";
reverseStr(word);
printf("Reversed: %s\n", word);  // Output: "tiolpxe"
```

---

## Challenge 6: Find the Largest Element in an Array Using Pointers

**Task:**

1. Write int findMax(int *arr, int size) that returns the largest number in an array using pointer arithmetic.

Example Usage:

```C
int numbers[] = {12, 45, 2, 67, 89, 3};
printf("Max: %d\n", findMax(numbers, 6));  // Output: 89
```

---

## Challenge 7: Find the First Occurrence of a Character in a String

**Task:**

1. Write `char* findChar(char *str, char ch)` that returns a pointer to the first occurrence of ch in str.
2. If ch isn’t found, return NULL.
3. Use pointer math, no indexing. 

Example Usage: 

```C
char *pos = findChar("hacker", 'k');
printf("Found at: %p, Character: %c\n", pos, *pos);  // Prints address & 'k'
```

---

## Challenge 8: Dynamic Memory Allocation – Duplicate a String

**Task:**

1. Write `char* duplicateStr(char *str)` that creates a new dynamically allocated copy of str.
2. Use malloc() to allocate memory for the new string.
3. Return a pointer to the new string.

Example Usage: 

```C
char *copy = duplicateStr("cybersecurity");
printf("Copy: %s\n", copy);
free(copy);  // Always free allocated memory
```

---

## Challenge 9: Function Pointer – Create a Math Operation Selector

**Task:**

1. Write a program that:
        - Defines add(), subtract(), multiply(), and divide() functions.
        - Uses a function pointer to select which function to call based on user input.

Example Usage: 

```C
printf("Choose operation: 1. Add  2. Subtract  3. Multiply  4. Divide\n");
scanf("%d", &choice);
int result = operate(choice, a, b);  // Calls the selected function
```

---

## Challenge 10: Function Pointers and Callbacks – Sorting an Array

**Task:**

1. Write a sorting function `void sort(int *arr, int size, int (*compare)(int, int))` that takes a function pointer to decide sorting order.
2. Implement two comparison functions:
    - ascending(int a, int b)
    - descending(int a, int b)

3. The sort() function should use bubble sort and allow sorting in ascending or descending order based on the function pointer.

Example Usage: 

```C
int numbers[] = {4, 2, 8, 5, 1};
sort(numbers, 5, ascending);
sort(numbers, 5, descending);
```





