#include <stdio.h> 

// This program illustrates a basic function pointer 

void hello(){
    printf("HELLO!\n");
}

int main(){
    // Here we declare a function pointer 
    // The parenthesis in (*funcPtr)() are important because it tells us
    // that funcPtr is a pointer which takes no arguments
    // So funcPtr is a pointer to a function that takes no arguments and returns void 
    void (*funcPtr)() = hello; // In C, function names act as pointers to the function's address 
    
    funcPtr(); // Calls hello() through pointer funcPtr    
    
    return 0;
}

