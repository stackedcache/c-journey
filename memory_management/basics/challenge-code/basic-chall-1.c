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

    free(heapNum); // Always FREE! 
    
    return 0;
}   

/* LEARNING NOTES 

    - Always check if malloc failed. We will cover this in more depth in next lessons.
    - When printing the address of 
    - heapNum is a pointer variable stored on the stack. 
        - It holds the memory address of the heap allocation
        - The pointer itself is a local variable, so it 'lives' on the stack 
        - This is why we print heapNum itself, and not &heapNum
        - heapNum is a variable that lives on the stack, so it's address is a stack address 
        - The value stored in heapNum is the heap allocated memory address which when dereferenced
        gives the stored value.
*/
