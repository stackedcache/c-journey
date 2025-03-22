# SUMMARY - MEMORY AS A WEAPON 

- This section focuses on the "big four" memory functions - `malloc()`, `calloc()`, `realloc()`, and `free()`
- With a focus on how memory mismanagement can lead to bugs and exploitation, we covered: 

## STACK Vs. HEAP

- Stack: Fast, local, auto-managed 
- Heap: Manual allocation, dyanmic, larger than the stack 
- Used `&var` vs `malloc()`, printed adddresses 
- Covers freeing allocated memory. 

## Malloc, Calloc, Realloc

- `malloc`: raw, uninitialized 
- `calloc`: zeroed, safer for structs 
- `realloc`: Must return the new pointer, or else face dangling pointer -- used to resize memory 
- `free`: Must free allocated memory, or you have a memory leak. Potentially leads to use after free bugs if using old pointers.
    - Freed memory is still accessible (use-after-free) until overwritten.
    - Freeing memory twice is a double-free, leading to heap metadata corruption and potential execution hijacking 

## Valgrind - Usage Basics 

- Valgrind is a command line tool that inspects every use of memory in a compiled binary. 
- Running a program inside Valgrind launches inside a sandbox that: 
    - Checks every allocation 
    - Checks every deallocation 
    - Checks every read/write 
    - Identifies every illegal access 
    - Identifies every leak 

- Valgrind's most used tool is memcheck, used by executing: 

`valgrind --leak-check=full ./my-program`

- This tool detects: 
    - use-after-free
    - Double free
    - Memory leaks
    - Invalid read/write (writing outside buffer bounds) 
    - Uninitalized memory use (reading memory before assigning values)
    - "Still reachable" memory -- allocated but not freed. 
    

**KEY FLAGS**

| Flag | Meaning |
|------|---------|
| --leak-check-full | Detailed report on every memory leak |
| --track-origins=yes | Tells you where uninitalized values come from |
| --show-leak-kinds=all | Shows all type of memory leaks | 
| -s | Shows supressions, errors ignored by Valgrind's config |
| --log-file=val.txt | Output results to a file |

## HOW DO HACKERS USE IT? 

- Spot weak memory behavior in binaries being analyzed 
- Reproduce bugs, UAF, Heap overflows, in fuzzed programs 
- Inspect memory behavior of custom loaders and imnplants 
- Validate payloads don't leave trails (memory still reachable) 


