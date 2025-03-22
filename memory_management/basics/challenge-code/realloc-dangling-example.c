#include <stdio.h>
#include <stdlib.h> 

/* CHALLENGE
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
*/

int main(){
    char *ptr = (char *)malloc(10 * sizeof(char)); // Allocate dynamic memory
    if (!ptr){
        printf("MALLOC FAILED!");
        return 1;
    }

    snprintf(ptr, 10, "%s", "HELLO!");
    printf("Ptr: %s\n", ptr); // All good, allocation and copy successful 

    // Realloc incorrectly, copy more into the string
    realloc(ptr, 20);

    char *str = "ADDED";

    // Copy str to ptr
    int ptrIndex = 6;
    int i = 0;
    for(ptrIndex, i; i < 5; i++, ptrIndex++) {
        *(ptr + ptrIndex) = *(str + i);
    }

    // Check the value now of ptr
    printf("Ptr after realloc without return: "
        "%s\n", ptr);

    /* NOTES:
        - This code "works" for now, likely because realloc modified memory in place.
        - But what if we assign something AFTER first malloc, then realloc?
    */

    char *ptr2 = (char *)malloc(10 * sizeof(char)); // Allocate 10 bytes (+ heap metadata)
    if (!ptr2){
        printf("MALLOC FAILED!");
        return 1;
    }

    snprintf(ptr2, 10, "%s", "string2");
    printf("Ptr2: %s\n", ptr2);
    
    // Now lets malloc something else, to take space after ptr2 
    char *takeSpace = (char *)malloc(25 * sizeof(char));
    if (!takeSpace){
        printf("MALLOC FAILED!");
        return 1;
    }

    // Now lets realloc ptr2 - incorrectly not returning new/updated pointer 
    realloc(ptr2, 512); // Realloc a larger value, so glibc is more likely to move the block 
    *(ptr2 + 7) = 'A';
    
    // Check what happens if we print ptr2
    printf("Ptr2 after realloc: %s\n", ptr2); // prints garbage! 

    return 0;
}

/* LEARNING NOTES: 

    realloc-dangling-example.c:33:5: warning: ignoring return value of ‘realloc’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
       33 |     realloc(ptr, 20);
          |     ^~~~~~~~~~~~~~~~
    realloc-dangling-example.c:70:5: warning: ignoring return value of ‘realloc’ declared with attribute ‘warn_unused_result’ [-Wunused-result]
       70 |     realloc(ptr2, 512); // Realloc a larger value, so glibc is more likely to move the block
          |     ^~~~~~~~~~~~~~~~~~
    Ptr: HELLO!
    Ptr after realloc without return: HELLO!ADDED
    Ptr2: string2
    Ptr2 after realloc: ��^


    - Here we see that garbade is printed after forcing the move of the reallocated memory. 
    - We are not really at the point of full understanding how this is exploitable, and this code is likely not 
    - However, if this type of UAF / dangling pointer has user input which can be provided to old memory, 
    and then the move is triggered, it presents opportunities for 'heap spraying' and ACE.
*/
