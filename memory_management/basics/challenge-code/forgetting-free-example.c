#include <stdio.h>
#include <stdlib.h>

// CHALLENGE 1
/*
    - Write a program that: 
        - Declares int on the stack
        - Declars int on the heap 
        - Prints the memory address of each 
*/  

int main() {
    int stackNum = 42;
    int* heapNum = (int *)malloc(sizeof(int));
    
    // Error Check malloc allocation 
    if (!heapNum) {
        printf("HEAP ALLOCATION FAILED\n");
        return 1;
    }

    *heapNum = 42;

    // Print the memory addresses 
    printf("Stack Num Address: %p\n",(void *)&stackNum);
    printf("Heap Num Address, Address of allocated memory in heap: %p\n", (void *)heapNum);

    // Here we forget to free heapNum, so we can check with the tool valgrind! 

    return 0;
}   

/* LEARNING NOTES 

    $ valgrind --leak-check=full ./forgetting-free-example 

    ==45887== Memcheck, a memory error detector
    ==45887== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
    ==45887== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
    ==45887== Command: ./forgetting-free-example
    ==45887== 

    Stack Num Address: 0x1ffefffec4
    Heap Num Address, Address of allocated memory in heap: 0x4a47040

    ==45887== 
    ==45887== HEAP SUMMARY:
    ==45887==     in use at exit: 4 bytes in 1 blocks
    ==45887==   total heap usage: 2 allocs, 1 frees, 1,028 bytes allocated
    ==45887== 
    ==45887== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
    ==45887==    at 0x48407B4: malloc (vg_replace_malloc.c:381)
    ==45887==    by 0x109171: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/forgetting-free-example)
    ==45887== 

    ==45887== LEAK SUMMARY:
    ==45887==    definitely lost: 4 bytes in 1 blocks
    ==45887==    indirectly lost: 0 bytes in 0 blocks
    ==45887==      possibly lost: 0 bytes in 0 blocks
    ==45887==    still reachable: 0 bytes in 0 blocks
    ==45887==         suppressed: 0 bytes in 0 blocks
    ==45887== 
    ==45887== For lists of detected and suppressed errors, rerun with: -s
    ==45887== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)



    - Above is the output of valgrind 
    - Definitely lost means memory was allocated but never freed 
    - The 4 bytes comes from the malloc allocated int that we did not free 
*/
