#include <stdio.h>

// Write a function printStackInfo() that calls another function, sayHello().
// Use GDB to set breakpoints in sayHello, step through execution, and print the stack with 'bt'. 

void sayHello(){
    printf("Здравствуйте!\n");
}

void printStackInfo(){
    sayHello();
}

int main(){
    printStackInfo();
    return 0;
}
