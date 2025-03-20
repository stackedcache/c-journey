# MEMORY MANAGEMENT BASICS 
## STACK VS. HEAP MEMORY 

- When a program runs, memory is divided into different sections. 
    - Stack - Fast, automatically allocated, used for function calls and local variables
    - Heap - Dynamic memory allocated at runtime. Used for large data structures, malloc, free.
    - Data (static) Segement - Stores global and static variables. 
    - Text (code) Segment - This section stores the compiled machine code of the running program. 

**KEY TAKEAWAY:** The stack is small and managed by the system, while the heap is large but manually managed.


## STACK MEMORY - Fast but Limited 

- Stores local variables, function arguments, return addresses (where to return after function execution)
- Automaticall managed by the OS
- Grows downward in memory.
- Small in size (8MB on Linux by default)

**EXAMPLE STACK ALLOCATION:**

```C
#include <stdio.h>

void printStackExample() {
    int num = 42; // stored in stack
    printf("Stack Variable: %d\n", num);
}

int main() {
    printStackExample();
    return 0;
}
```

### WHAT HAPPENS? 
- `num` is created in stack memory 
- When `printStackExample()` is called, a stack frame is added to the 'top' of the stack 
- When `printStackExample()` finishes, num is erased automatically. 
- After execution, the program returns to the stored return address and pops the frame off the top of the stack.
- You don't need to manually free stack memory. 


## HEAP MEMORY - MANUAL CONTROL, LARGER SIZE 

- The heap is used for dynamic memory allocation.
- Manually managed (you allocate and free memory with `malloc()` and `free()`)
- Larger in size, GBs depending on the system memory 
- Grows upward in memory

    - If you don't `free()` --> memory leak
    - If you use after `free()` --> dangling pointer (use after free bug)

**EXAMPLE: HEAP ALLOCATION, DYNAMIC**

```C
#include <stdio.h>
#include <stdlib.h>

void printHeapExample() {
    int* heapNum = (int *)malloc(sizeof(int)); // Allocate memory on the heap 
    *heapNum = 42;
    printf("Heap Num: %d\n", *(heapNum));
    free(heapNum);
}

int main() {
    printHeapExample();
    return 0;
}
```

### WHAT HAPPENED? 
- `malloc(sizeof(int))` reserves memory in the heap.
- `free(heapNum)` frees the memory, preventing leaks. 
- If you forget `free()` --> This is a memory leak, which is bad in long-running programs.

### STACK VS HEAP: KEY DIFFERENCES 

| Feature | Stack | Heap |
|---------|-------|------|
| Speed | Faster (LIFO Structure) | Slower (Manual allocation) |
| Size | Small, MBs | Large, depends on system memory |
| Allocation | Automatic | Manual | 
| Storage | Local variables, return addresses | Dynamically allocated data |
| Error Risk | Stack overflow, too many function calls | Memory-leaks, use after free | 

