# REALLOC PITFALS AND DANGLING POINTERS 
## Real World Setups 

- A program assigns memory with `malloc()`
- Later resizes it with `realloc()`
- Forgets to assign the return value 
- Keeps using the *old* pointer, which may now be invalid. 

**THIS CREATES:**

- Dangling pointer bugs
- Memory Leaks 
- Crash surfaces 
- Potential exploitation scenarios 

## WHAT'S REALLY GOING ON WITH REALLOC? 

- `realloc()` takes an existing pointer and:
    - Tries to resize it in place 
        - If there's enough space after the current block, it shrinks/expands it right there 

    - If theres not enough space -> it: 
        - Allocates a new memory block 
        - Copies the contents of the old block into it 
        - Frees the original block
        - Returns the new pointer 
    
    **IF YOU DON'T STORE THE RETURN VALUE -> you're still pointing at memory that's now freed.**

## WHY IS THIS DANGEROUS? 

- For example: 

```C
char *data = malloc(10);
data = realloc(data, 100)i; // Correctly returns the 'new' pointer
```
- But if you forget to return the result: 

```C
realloc(data, 100);  // 👈 result discarded
```

- `data` still points to the freed memory, if the reallocation moved the block. 
- This is a use after free, dangling pointer, crash waiting to happen
- Depending on the code layout, this is an exploit surface. 

## MEMORY BEHAVIOR BREAKDOWN 

- At the memory level, `malloc(10)` allocates ~24 bytes of memory (heap chunks include metadata headers)
- You write "hello" into it
- `realloc(ptr, 100)` checks:
    - Is there space? If yes, adds in place 
    - If no -> new chunk allocated elsewhere 

- If the memory moves: 
    - `memcpy()` moves memory from old to new block 
    - Old block goes back to free list 
    - You now have a pointer which points to a freed memory block 
        - This is dangerous if the pointer is reused 

## CHALLENGES 

- Challenge Requirements (Let’s Break It)
    - Step 1:

        malloc() small buffer
        Write some string into it

    - Step 2:

        realloc() the buffer to a bigger size
        Don’t capture the return

    - Step 3:

        Try to strcat() to the original pointer
        Observe if you get garbage, a crash, or silent corruption
