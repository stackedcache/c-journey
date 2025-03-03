🔹 1. Basic Function Challenge
Task:

Write a function sum() that takes two integers and returns their sum.

    Declare the function prototype above main().
    Define the function below main().
    Call it inside main() and print the result.

```C
int sum(int a, int b);
```

🔹 2. Pass by Value vs. Pass by Reference
Task:

    Write a function modifyValue() that takes an integer by value and changes it inside the function.
    Write another function modifyValueByPointer() that takes an integer by reference and modifies it.
    Inside main(), print the values before and after calling each function.

```C
void modifyValue(int x);
void modifyValueByPointer(int *x);
```

🔹 3. Recursion Challenge (Factorial)
Task:

    Implement a recursive function factorial() that calculates the factorial of a number n.
    Use a base case to prevent infinite recursion.
    Call the function inside main() and print factorial(5).

```C
int factorial(int n);
```

🔹 4. Function Pointers Challenge
Task:

    Define a function printMessage() that prints "Hello!"
    Store the function’s address in a function pointer.
    Call the function using the function pointer.

```C
void printMessage();
void (*funcPtr)();
```

🔹 5. Implementing qsort() with a Custom Compare Function
Task:

    Create an integer array and sort it using qsort().
    Write a custom compare function that sorts numbers in descending order.
    Print the array before and after sorting.

```C
int compare(const void *a, const void *b);
```

🔹 6. Function Returns a Pointer
Task:

    Write a function getStaticArray() that returns a pointer to a static array of 3 integers.
    Print the array in main().

```C
int* getStaticArray();
```

🔹 7. Debugging with GDB (Function Stack Frames)
Task:

    Write a function printStackInfo() that calls another function sayHello().
    Use GDB to set breakpoints in sayHello(), step through execution, and print the stack with bt.

```C
void printStackInfo();
void sayHello();
```

🔹 8. Beginner Buffer Overflow Experiment
Task:

    Create a buffer overflow scenario where a function writes more data than a fixed-size buffer.
    Observe what happens to surrounding memory.

```C
void overflowFunction();
```

🚨 WARNING: Don’t try to break anything yet—just observe how writing past the buffer affects program memory.

🔹 9. Return Address Manipulation (Beginner)
Task:
    
    *NOTE*: Completed this challenge in challenge 7, therefore will not repeat.

    Call a function normally.
    Print its return address inside GDB using info frame.
    Manually overwrite the return address in GDB and redirect execution.

🔹 10. Function Callback System (Basic Plugin Style)
Task:

    Write a function executeCallback() that takes a function pointer as an argument.
    Call executeCallback() with different function pointers to demonstrate callbacks.

```C
void executeCallback(void (*func)());
```
