# USE AFTER FREE 
## WHAT IS USE AFTER FREE? 

- Typical flow is `malloc()` memory -> use it -> `free()` the memory 
- Use after free is when memory is used after freeing it with `free()`
- This memory might be: 
    - Unallocated (segfault)
    - Reallocated by something else (data leak)
    - Corruptible (exploitable) 

## REAL WORLD EXPLOIT EXAMPLES 

    - Web Browsers -- UAFs from JS objects -> code execution 
    - Linux Kernel CVEs -- Structures freed but not cleared -> race conditions 
    - Heap spraying -- use-after-free + carefully crafted replacement data = RCE (Remote Code Execution)

## Challenge Code

Write a program that:

    - Allocates a block with malloc()
    - Fills it with some data (e.g., a string)
    - Frees the block
    - Prints or accesses the pointer after it’s freed
    - Observe output or crash with Valgrind


