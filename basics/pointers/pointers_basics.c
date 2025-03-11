#include <stdio.h>

// This is a program which illustrates the absolute basics of pointers. 

int main(){
    int num = 93;
    int *numPtr = &num;

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n\n", &num);

    // This shows the memory address of the numPtr variable 
    printf("Address of *numPtr: %p\n", &numPtr);

    // This shows the value stored in the numPtr variable
    printf("Value of *numPtr: %p\n", numPtr);

    // This shows the dereferenced value of numPtr -- The value of the variable it points at 
    printf("Value pointed at by *numPtr: %d\n", *numPtr);
    
    return 0;
}
