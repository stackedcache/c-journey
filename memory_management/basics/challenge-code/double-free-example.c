#include <stdio.h>
#include <stdlib.h>
/*
    Write a simple C program that:

    - Allocates memory
    - Frees it
    - Frees it again (accidentally or deliberately)
    - Observe crash or Valgrind report
*/

int main() {
    int *doubleFree = (int *)malloc(sizeof(int));
    if (!doubleFree) {
        printf("MALLOC FAILED!");
        return 1;
    }

    *doubleFree = 25;
    printf("Address before free: %p\n", &doubleFree);
    printf("doubleFree = %d\n", *doubleFree);
    free(doubleFree);

    printf("Address after free: %p\n", &doubleFree);
    free(doubleFree);

    return 0;
}

/* LEARNING NOTES: 

    shell $ valgrind --leak-check=full --track-origins=yes ./double-free-example 
    ==60744== Memcheck, a memory error detector
    ==60744== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
    ==60744== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
    ==60744== Command: ./double-free-example
    ==60744== 
    Address before free: 0x1ffefffed8
    doubleFree = 25
    Address after free: 0x1ffefffed8
    ==60744== Invalid free() / delete / delete[] / realloc()
    ==60744==    at 0x484317B: free (vg_replace_malloc.c:872)
    ==60744==    by 0x109206: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/double-free-example)
    ==60744==  Address 0x4a47040 is 0 bytes inside a block of size 4 free'd
    ==60744==    at 0x484317B: free (vg_replace_malloc.c:872)
    ==60744==    by 0x1091DF: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/double-free-example)
    ==60744==  Block was alloc'd at
    ==60744==    at 0x48407B4: malloc (vg_replace_malloc.c:381)
    ==60744==    by 0x10916A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/double-free-example)
    ==60744== 
    ==60744== 
    ==60744== HEAP SUMMARY:
    ==60744==     in use at exit: 0 bytes in 0 blocks
    ==60744==   total heap usage: 2 allocs, 3 frees, 1,028 bytes allocated
    ==60744== 
    ==60744== All heap blocks were freed -- no leaks are possible
    ==60744== 
    ==60744== For lists of detected and suppressed errors, rerun with: -s
    ==60744== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
    

    - Here we can see valgrind alerts the double free 
    - Simplified Exploit Flow:
     Example Exploit Flow (Simplified):

        Allocate chunk A
        Free chunk A
        Free chunk A again → it's in freelist twice
        Allocate chunk B → gets same memory
        Allocate chunk C → gets same memory again
        Overwrite C → modifies B → control function pointer

    You now control memory flow.
*/
