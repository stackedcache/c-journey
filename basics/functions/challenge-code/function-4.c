#include <stdio.h>

// Define a function printMessage() that prints a greeting
// Store the functions address in a function pointer
// Call the function using the function pointer 

void greeting(){ printf("Привет!\n");}

int main(){
    void (*funcPtr)() = greeting;
    funcPtr();
    return 0;
}
