#include <stdio.h>

// Swapping values using pointers 
// Write a function that swaps two values using pointers 

// Here we setup a function that takes two integer pointers as parameters
// We hold the dereferenced value of int a within int temp
// Then we swap
// To modify variables outside of function scope, we must pass by reference, aka by pointer
// Because this function returns nothing, it is return type void 

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 20;
    int b = 40;
    int* ptrA = &a;
    int* ptrB = &b;

    printf("Before Swap, A: %d\n", a);
    printf("Before Swap, B: %d\n\n", b);

    swap(ptrA, ptrB);

    printf("After Swap, A: %d\n", a);
    printf("After Swap, B: %d\n", b);

    return 0;
}
