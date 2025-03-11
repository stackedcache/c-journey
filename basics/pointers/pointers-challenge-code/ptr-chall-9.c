#include <stdio.h>

// Challenge 9 - Create a Math Operation Selector 
// Write a program that: 
// - Defines add(), subtract(), multiply(), and division() functions 
// - Uses a function pointer to select which function to call based on user input 

int add(int x, int y){
    int sum = x + y;
    return sum;
}

int subtract(int x, int y){
    int diff = x - y;
    return diff;
}

int multiply(int x, int y){
    int prod = x * y;
    return prod;
}

float divide(float x, float y){
    float quot = x / y;
    return quot;
}

int main(){
    // Set function pointers: 
    int (*addPtr)(int x, int y) = add;
    int (*subPtr)(int x, int y) = subtract;
    int (*mulPtr)(int x, int y) = multiply;
    float (*divPtr)(float x, float y) = divide;
    
    // Collect input to make operation choice 
    printf("Enter a choice: 1. Add -- 2. Subtract -- 3. Multiply -- 4. Divide :");
    int choice; // Create int to store user choice 
    scanf("%d", &choice); // Take user input to store choice 
    
    // clean buffer after scanf
    int c;
    while((c = getchar()) != '\n' && c != EOF);

    // Make switch case for user selection 
    switch(choice){
        case 1: 
            // function pointer callback to add
            printf("Enter first number: ");
            int x;
            scanf("%d", &x);
            printf("Enter second number: ");
            int y;
            scanf("%d", &y);
            int sum = addPtr(x, y);
            printf("Sum: %d\n", sum);
            break;
        case 2:
            // function pointer callback to subtract 
            printf("Enter first number: ");
            int x1;
            scanf("%d", &x1);
            printf("Enter second number: ");
            int y1;
            scanf("%d", &y1);
            int diff = subPtr(x1, y1);
            printf("Difference: %d\n", diff);
            break;
        case 3: 
            // function pointer callback to multiply
            printf("Enter first number: ");
            int x2;
            scanf("%d", &x2);
            printf("Enter second number: ");
            int y2;
            scanf("%d", &y2);
            int prod = mulPtr(x2, y2);
            printf("Product: %d\n", prod);
            break;
        case 4: 
            // function pointer callback to divide
            printf("Enter first number: ");
            float x3;
            scanf("%f", &x3);
            printf("Enter second number: ");
            float y3;
            scanf("%f", &y3);
            float quot = divPtr(x3, y3);
            printf("Quotient: %f\n", quot);
            break;
        default:
            printf("INVALID CHOICE!\n");
            break;
    }
    

    return 0;
}


/* LEARNING NOTES: 
    - I accidentally forgot to take floats and change the print options for division
    - This came from copying and pasting the switch case instead of retyping each part by hand
    - Remember to be careful and not lazy! 

    - After checking this working solution with AI, the following optimizations are considered: 
        
        - Wrap the selections in a while, to give the user another chance if invalid input is given
            - We did this in control_flow_challenges.c in the control flow section -- no need to redo it here
        
        - There is a potential for division by 0 errors - dividing by 0 can cause unexpected behavior 
            - There should be a check to prevent this in the division case. 

        - Code duplication -- We are taking scanf multiple times.
            - Instead, we could take user input before the switch cases and feed it to each case.
            - This would require just one scanf

        - Combining function pointers into an array
            - Instead of having each function pointer declared, we could just use an array of function pointers

        **EXAMPLE FUNCTION POINTER ARRAY**

        ```C
        int main() {
            // Function pointer array
            int (*operations[])(int, int) = { add, subtract, multiply, divide };

            int choice, x, y;
            printf("Choose operation: 0. Add  1. Subtract  2. Multiply  3. Divide\n");
            scanf("%d", &choice);

            printf("Enter two numbers: ");
            scanf("%d %d", &x, &y);

            if (choice >= 0 && choice <= 3) {
                printf("Result: %d\n", operations[choice](x, y));
            } else {
                printf("Invalid choice!\n");
            }        

        ```
        
        - This is a cleaner way to achieve what I have written without switch cases 
        - If you want floats, change int to float and use float (*operations[])(float, float). 
        
        - Another thing to note is that I do not clear the buffer after every scanf, so this should also be 
        implemented in a 'real' calculator. 

        - fgets() would be a better choice for taking the user inputi. fgets does not require flushing.
        
        - We also do not validate integer / number input. Real world would require checking for valid numbers
        
        - Because the main focus of this exercise was just calling a function pointer, I am happy with it.
        - I also got extra practice writing switch cases 

*/
