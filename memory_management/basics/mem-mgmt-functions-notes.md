# malloc, calloc, realloc, free -- Memory Management Functions 
## The Big 4 Functions 

## `malloc()`
- `malloc(size_t size)` 
    - Allocates `size` bytes of raw, uninitialized memory on the **heap**. 
    - Returns a `void*` to the memory block.
    - Needs to be **casted** (if using strict types, good practice)
    - If allocation fails --> returns `NULL`

**COMMON BUGS**

    - Forgetting to check if the result is `NULL`
    - Accessing memory before setting it
    - Not freeing memory (memory leak)

## `calloc()`
- `calloc(size_t count, size_t size)`
    - Allocates memory for `count` elements of `size` bytes each. 
    - Zeros memory out (unlike malloc).
    - Useful for arrays, structs, or anything where garbage values might break things.

**COMMON BUGS**

    - Confusing order of args (count and size).
    - Slower than `malloc()` in high-performance code 

## `realloc()`
- `realloc(void *ptr, size_t new_size)`
    - Changes the size of an existing memory block.
    - Can move the block to a new address.
    - Returns **new pointer**, the old one becomes invalid.

**DANGEROUS EDGE CASES**
    
    - If `realloc` fails, returns `NULL`, and old pointer is still valid
    - If you don't store the return value, this is a memory leak or segfault.

    ```C
    ptr = realloc(ptr, new_size) // Must store result
    ```

## `free()`
- `free(void *ptr)`
    - Releases memory back to the heap.
    - ptr must be from malloc/calloc/realloc.
    - After freeing, ptr becomes invalid, so never use it again! 

**DANGEROUS MISTAKES**

    - Use-after-free (using memory after freeing it)
    - Double free (calling `free()` twice)
    - Freeing stack memory or random pointers (leads to segfaults)


## MEMORY ALLOCATION FLOW (Mental Model)

```C
int *arr = malloc(10 * sizeof(int));
if (arr = NULL) { /* Handle Failure */ }
arr[0] = 1337; 
arr = realloc(20 * sizeof(int)); // Resize safely
free(arr); // Free memory back to heap 
```

## WHAT CAN GO WRONG? 

| Bug | Description |
|-----|-------------|
| Memory Leak | You use `malloc()` but forget to `free()` it |
| Use-after-free | You `free()` a block but still use the pointer after free |
| Double-free | You `free()` the same pointer/memory twice | 
| NULL dereference | `malloc()` failed, but you didn't check, and still tried to use the pointer |
| realloc trap | You `realloc()` without checking for failure, old pointer lost | 

# Challenge Code Instructions

- In challenge-code/L4-malloc-calloc-realloc.c, write a C program that:

    - Uses malloc() to create an int array of 5 elements.
    - Sets values, prints them, then realloc()s the array to 10 elements.
    - Uses calloc() to allocate a new float array of 4 elements, show that they are zero.
    - Frees both arrays properly.
    - Add optional edge case testing:
        - malloc(0)
        - realloc(NULL, size) (equivalent to malloc)
        - free(NULL) (safe)


