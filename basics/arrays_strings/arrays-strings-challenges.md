# ARRAYS AND STRING CHALLENGES 

## CHALLENGE 1

**Basic Array Manipulation**

Task:

    Declare an int array of size 5.
    Use a loop to set arr[i] = i * 2.
    Print each value using both indexing and pointer arithmetic.

## CHALLENGE 2 

**Buffer Overflow Simulation (Safe vs. Unsafe)**

Task:

    Create a char buffer[10].
    Use gets(buffer); (dangerous) and then fgets(buffer, 10, stdin); (safe) to compare behavior.LABLA**


## CHALLENGE 3 

Challenge 3 (Custom strcpy() Without <string.h>)

Now that you’ve mastered safe input handling, it’s time to recreate strcpy() from scratch.

    No <string.h> allowed
    Manually copy characters from src to dest
    Ensure no overflows by checking buffer size
