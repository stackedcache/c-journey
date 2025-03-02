#include <stdio.h>

// Implement a recursive function factorial() that calculates a factorial of a number n.
// Use a base case to prevent infinite recursion
// Call the function inside main() and print factorial 5


int factorial(int a){
    if (a == 0) return 1;
    return a * (factorial(a - 1));
}

int main(){
    int f_5 = factorial(5);
    printf("Factorial of 5 is: %d\n", f_5);
    return 0;
}
