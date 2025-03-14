# ARRAYS AND STRINGS IN C

- Arrays - Contiguous blocks of memory that store an array of some data.
    - Key for buffer overflows

- C has no built in safety -> we can overstep bounds and corrupt memory, which leads to exploits 

- Arrays are used in buffers, network packets, binary exploitation, and shellcoding. 

## DECLARING AND USING ARRAYS IN C 

- An array is just a contiguous block of memory with elements of the **same type**. 

**EXAMPLE:**

```C
#include <stdio.h>

int main(){
    int arr[4] = {1, 2, 3, 4};

    printf("First element: %d\n", arr[0]);
    printf("Second element: %d\n", arr[1]);

    return 0;
}
```

- Here we allocate space for 4 integers in memory (integers are 4 bytes each, so 16 bytes).
- Array values can be accessed using index based values as above, or with pointers and pointer arithmetic
- Accessing arrays outside their defined boundaries will cause unexpected behavior 

## MEMORY LAYOUT OF ARRAYS 

- The following program would show how memory is laid out by printing the memory address of each element

```C
#include <stdio.h>

int main(){
    int arr[4] = {1, 2, 3, 4};
    int* arrPtr = arr;

    // Print the memory addresses of elements in the array
    printf("Address of Element 1: %p\n", &arr[0]);
    printf("Address of Element 2: %p\n", &arr[2]);
    printf("Address of Element 3: %p\n", (arrPtr + 3));
 
    return 0;
}
```

### WHAT'S HAPPENING? 

- Memory locations are sequential -> Each int is **4 bytes** on most systems
- We print the memory address with `%p` placeholder with index based and pointer math based syntax


## ACCESSING ARRAYS WITH LOOPS 

- Consider the code from the example in MEMORY LAYOUT OF ARRAYS above for the following loop:

```
for(int i = 0; i < 4; i++){
    printf("arr[%d]: %d\n", i, *(arrPtr + i));
}
```

## Buffer Overflow BASICS 

- Why are Arrays in C a "Hacker's Playground"?

- Consider the array code from MEMORY LAYOUT OF ARRAYS above

```C
arr[5] = 777; // Writes out of bounds
printf("arr[5]: %d\n", arr[5]); // Could overwrite random memory! 
```

- No errors, but memory is corrupted 
- In functions and control-flow sections, we examined how carefully crafted overflows can overwrite memory which stores return addresses
- If you overwrite the exact memory location where a return address is stored, replacing it with your own value, you can control execution flow.
- Heap overflows (which we will learn about in the memory management section) allow for injecting shellcode.


# STRINGS IN C 

- Why do strings matter? 
    - Strings in C are just character arrays (char[])
    - Manipulating strings incorrectly leads to buffer overflows 
    - Functions like strcpy() and gets() are dangerous because they don't check bounds / buffer size 

- Strings in C are just arrays of characters ending with a null terminator '\0'

```C
#include <stdio.h>

int main() {
    char name[] = "Hacker";  // Implicitly null-terminated
    char manual[7] = {'H', 'a', 'c', 'k', 'e', 'r', '\0'};  // Manual null-termination

    printf("%s\n", name);  // Prints "Hacker"
    printf("%s\n", manual);  // Also prints "Hacker"

    return 0;
}
```

### KEY TAKEAWAYS 

- Strings are always null terminated ('\0')
- Forgetting \0 leads to memory corruption risks 
- strcpy() and gets() are common only in old or exploitable code due to their security risks 
    - These functions do not check buffer, and allow for overwriting adjacent memory 

- fgets() and strncpy() are the preferred alternatives to gets() and strcpy()




