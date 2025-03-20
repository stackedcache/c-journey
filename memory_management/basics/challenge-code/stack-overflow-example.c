#include <stdio.h>

// CHALLENGE 3 - CAUSING A STACK OVERFLOW 
/* 
    - Write a program that: 
        - Has a function which calls itself indefinitely until the stack 
        overflows and crashes.
*/

void crashStack(int count) {
    printf("Stack frame: %d\n", count); 
    crashStack(count + 1); // Recursive call with no exit condition
}

int main() {
    crashStack(1);
    return 0;
}

/* Learning Notes:
    
    - This code will eventually crash when ran.
    - Each function stores a return value address and local variables on the stack.
    - The stack has limited space, about 8MB by default on linux.
    - Since there is no exit condition, the function runs forever. 
    - This consumes stack space until it runs out.
    - When the program tries to allocate more space on the stack, it crashes with a segmentation fault.

*/
