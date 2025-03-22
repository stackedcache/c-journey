# `calloc()` VS `malloc()` vs `memset()`
## OBJECTIVE: Understand how `calloc()` works, how it differs from `malloc` + `free`

### QUICK THEORY 
- `malloc(size)`
    - Allocates uninitialized memory of `size` bytes
    - Contents = garbage (whatever was already in RAM

- `calloc(num, size)`
    - Allocates memory for an array of `num` elements, each of `size` bytes 
    - Zero'd values, equivalent to: 

    ```C
    ptr = malloc(num * size);
    memset(ptr, 0, num * size);
    ```

## WHY CALLOC MATTERS IN EXPLOITATION 
- Sometimes `calloc()` hides bugs (no garbage values)
- Sometimes the absence of `calloc()` creates a vulnerability (uninitalized memory) 
- Some structs rely on fields being `0`, forgetting to zero can cause logic bugs 

