# FUNCTIONS IN C

(What I learned today)

- Functions in C allow for code re-use and modularity
- A function in C is defined with returnType functionName (arguments) {} 
- To use a function, it must be declared before main() or you must use prototypes 
- qsort is built in to stdlib.h in C, and requires a compare function to know what type of data is being sorted
- Bubble sort is a slow but common learning algorithm for sorting objects that beginners can use for learning
- Values should always be returned properly from functions when needed
- These notes will be updated with more detail as study continues. 


# DEEP DIVING FUNCTIONS 

## WHAT IS A FUNCTION

- A function is a block of reusable code that performs a specific task.
- In C, every function:
    - Takes input
    - Processes something
    - Returns output (or is return type void if nothing is returned)

BASIC SYNTAX: 

```C

return_type function_name(parameter_1, parameter_2, . . .){
    // FUNCTION BODY 
    return value; // (optional, and based on return_type)
}

```

## FUNCTION PROTOTYPES (DEFINITION vs DECLARATION)

### FUNCTION DECLARATION 

- Also known as prototype 
- Tells the compiler about the function return type, parameters, and name 
- Avoids implicit declaration errors 

```C
#include <stdio.h>

// прототип функция 
// Function Prototype 

int multiply(int, int);

int main(){

    int result = multiply(2, 2);
    printf("Product: %d\n", result);
    return 0;
}

// Function definition 
int multiply(int a, int b){
    
    return a * b;

}

```
