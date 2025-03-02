#include <stdio.h>

// Write a function modifyValue() that takes an integer by value and changes it inside the function 
// Write another function modifyByPointer() that takes an integer by pointer (reference) and modifies it 
// Inside main() print the values before and after calling the function 

void modifyValue(int a){
    a = 100;
}

void modifyByPointer(int *a){
    *a = 100;
}

int main(){
    int a = 500;

    modifyValue(a);
    printf("A After modifyValue: %d\n", a);
    
    modifyByPointer(&a);
    printf("A After modifyByPointer: %d\n", a);
    return 0;
}
