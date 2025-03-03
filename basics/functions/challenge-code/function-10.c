#include <stdio.h>

// Write a function executeCallback() that takes a function pointer as argument.
// Call executeCallback() with different function pointers to demonstrate callbacks. 

/* 
    NOTE:
    This type of function calling is useful for dynamic behavior that needs to change at runtime.
    For example, if a user selects English, run one function, if a user selectes Russian, run another.
*/


// To declare a 'function pointer' the syntax is void (*func)() 
// If the return type of a function is different, syntax is different
// Example, int returntype would be int (*func)() 
// This would require a different callback function as well 

// Void callback function 
void executeCallback(void (*func)()){
    func();
}

// Int callback function 
// Here the function takes a function pointer to a function that takes two integers as parameter 1
// Parameters 2 and 3 are integer 'a' and integer 'b'
// We return the restult of the passed function, when that function is given 'a' and 'b'
int intCallback(int (*func)(int, int), int a, int b){
    return func(a, b);
}

// Defining functions to pass 
void sayHello(){printf("Здравствуйте!\n");}

int addition(int a, int b){
    return a+b;
}

// Start main
int main(){
    void (*funcPtr)() = sayHello;
    executeCallback(sayHello);
    
    // Here we define an integer variable sum
    // sum is equal to the integer callback function, which takes a function name as parameter 1
    // the second and third parameters are the integers we want to add, which are passed to the function 
    int sum = intCallback(addition, 2, 2);
    printf("Sum is: %d\n", sum);

    return 0;
}
