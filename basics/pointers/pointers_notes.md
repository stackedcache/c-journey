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

    // This shows the memory address of the numPtr variable 
    printf("Address of *numPtr: %p\n", &numPtr);

    // This shows the value stored in the numPtr variable
    printf("Value of *numPtr: %p\n", numPtr);

    // This shows the dereferenced value of numPtr -- The value of the variable it points at 
    printf("Value pointed at by *numPtr: %d\n", *numPtr);
    
    return 0;
}
```

**BREAKDOWN:**

- `int *numPtr = &num` -- Declares a pointer to an integer, and stores the memory address of 'num' in 'numPtr'
- `*numPtr*` -- "Dereferencing" -> Accesses the value at the stored address. (93 in this case)

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
- `*(numbersPtr + i) -- Dereferences the pointer to get the value. 

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



