# POINTERS, POINTERS, POINTERS 

- A pointer is a variable that stores a memory address of another variable 
- Instead of holding a value directly, it *points* to another variable's address in memory (RAM)

### WHY WOULD YOU EVEN USE A POINTER ANYWAY? 

- **Efficiency:** Instead of copying large amounts of data, you just pass around a pointer. Saves processing and memory power.
- **Direct Memory Access:** Pointers let you work directly with memory. This is critical for:
    - Low level programming (embedded systems)
    - System hacking 
    - Exploiting vulnerabilities
    - Understanding these concepts for defending against the above 

- **Dynamic Memory Management:** Pointers allow you to allocate and free memory at runtime with `malloc()` and `free()`, 
making programs more dynamic.

- **Pointer Arithmetic:** You can traverse arrays and data structures efficiently using pointer arithmetic, instead of relying
on index-based access. 

- **Function Pointers**: You can use function pointers for callbacks, jump tables, and even obfuscate execution flow.
    - Malware can use function pointers to make reverse engineering more difficult, instead of calling functions directly. 

## POINTER BASICS - DECLARING AND USING 

- The simplest pointer setup looks like this: 

```C
#include <stdio.h>

// This is a program which illustrates the absolute basics of pointers. 

int main(){
    int num = 93; // A normal integer 
    int *numPtr = &num; // Pointer to an integer and storing the address of 'num' in 'numPtr'

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n\n", &num);

    // This shows the memory address of the numPtr variable (a pointer to an int)
    printf("Address of numPtr: %p\n", &numPtr);

    // This shows the value stored in the numPtr variable
    printf("Value of *numPtr: %p\n", numPtr);

    // This shows the dereferenced value of numPtr -- The value of the variable it points at 
    printf("Value pointed at by *numPtr: %d\n", *numPtr);
    
    return 0;
}
```

**BREAKDOWN:**

- `int *numPtr = &num` -- Declares a pointer to an integer, and stores the memory address of 'num' in 'numPtr'
- `*numPtr` -- "Dereferencing" -> Accesses the value at the stored address. (93 in this case)

**OUTPUT OF THE EXAMPLE PROGRAM**

```bash
Value of num: 93
Address of num: 0x7fff3f74921c

Address of *numPtr: 0x7fff3f749210
Value of *numPtr: 0x7fff3f74921c
Value pointed at by *numPtr: 93
```

## POINTER ARITHMETIC 

- Once a pointer is holding an address, we can **move through memory**. 

**EXAMPLE: Walking through an Array with a Pointer:**

```C
#include <stdio.h> 

// This illustrates the basic concept of pointer arithmetic. 

int main(){
    int numbers[] = {10, 20, 30, 40, 50, 60};
    int *numbersPtr = numbers;

    for (int i = 0; i < 6; i++){
        printf("Address: %p, Value: %d\n", numbersPtr + i, *(numbersPtr + i));
    }

    return 0;
}
```

**OUTPUT:**

```bash
Address: 0x7ffe4df922a0, Value: 10
Address: 0x7ffe4df922a4, Value: 20
Address: 0x7ffe4df922a8, Value: 30
Address: 0x7ffe4df922ac, Value: 40
Address: 0x7ffe4df922b0, Value: 50
Address: 0x7ffe4df922b4, Value: 60
```

### KEY TAKEAWAYS: 

- `numbersPtr + i` -- moves the pointer forward in memory. Each step is sizeof(int) bytes.
- `*(numbersPtr + i)` -- Dereferences the pointer to get the value. 

```C
    int numbers[] = {10, 20, 30, 40, 50, 60};
    int *numbersPtr = numbers;

    // A pointer to an array behaves similarly to an array name
    printf("%d, %d\n", numbers[0], *numbersPtr); // Both give 10
    printf("%d, %d\n", numbers[1], *(numbersPtr + 1)); // Both give 20
```

- `numbers` CANNOT be modified, while `numbersPtr` CAN be moved. 

- What the above means is that you cannot modify numbers (the plain array) after it has been created
    - It points to a permanent address in memory where the array starts 
    - For example, `numbers = numbers + 1` --> INVALID

- However you CAN modify numbersPtr
    - `numbersPtr = numberPtr + 1` --> VALID, and now points to numbers[1]
    - numbers ALWAYS points to the start of the array, no moving allowed
    - numbersPtr can be moved freely to point to different elements

## POINTERS AND MALLOC 

- Dynamic memory allocation gives full control over memory but you must `free()` it. 
- This allows the allocation of space at runtime instead of hardcoding array values 
- If you dont 'free' allocated memory, it causes memory leaks. 
- Over time, memory leaks cause gradual RAM exhaustion and potential crashes. 

### WHY IS MALLOC() USEFUL?

- Flexibility: no need to hard code values or predefine large arrays -- allocate what is needed 
- Efficient memory usage: Saves RAM in embedded systems where memory is limited 
- Hacking and Exploitation: Controlling heap allocation allows
    - Crafting heap-based buffer overflows (exploit programs dynamically)
    - Manipulate heap structures for privilege escalation 
    - Bypassing ASLR (Address Space Layout Randomization) with memory spraying techniques 
    - Understanding these concepts allows for adequate defense against these techniques 

- We will expand on `malloc()` in subsequent sections 

**EXAMPLE OF MALLOC**

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(3 * sizeof(int)); // Note that we 'cast' malloc() with (int *)malloc(...) because malloc() returns void *. 

    // Checks if malloc() failed 
    if (!ptr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        ptr[i] = i * 10;
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    free(ptr); // Always free memory

    return 0;
}
```

## FUNCTION POINTERS 

- We worked a bit with function pointers in the functions section of this repository. 
- Pointers can also store function addresses 
- This is useful for callbacks and ROP (Return-Oriented Programming)
    - 'Callbacks' are useful for event-handling, asynchronous programming, and custom behavior.
        - OS internals, modular code, etc.
    - ROP --> Attackers can hijack function pointers to control execution and bypass DEP (Data Execution Prevention)
    - We will touch on these advanced concepts later 

- Function Pointers = flexibility in legit programming + a weapon for exploitation 
- Understanding these concepts allows for adequate defensive measures to be taken 

**EXAMPLE FUNCTION POINTER**

```C
#include <stdio.h> 

// This program illustrates a basic function pointer 

void hello(){
    printf("HELLO!\n");
}

int main(){
    // Here we declare a function pointer 
    // The parenthesis in (*funcPtr)() are important because it tells us
    // that funcPtr is a pointer which takes no arguments
    // So funcPtr is a pointer to a function that takes no arguments and returns void 
    void (*funcPtr)() = hello; // In C, function names act as pointers to the function's address 
    
    funcPtr(); // Calls hello() through pointer funcPtr    
    
    return 0;
}
```


