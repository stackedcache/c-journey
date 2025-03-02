#include <stdio.h>

// Write a function sum that takes two integers and returns their sum
// Define prototype above main
// Define function below main
// Call in main and print the result 

int sum(int, int);

int main(){
    int answer = sum(24, 26);
    printf("24 + 26 is: %d\n", answer);
    return 0;
}

int sum(int a, int b){
    return a + b;
}
