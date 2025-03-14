#include <stdio.h>

// CHALLENGE 1 
// Declare an integer array of size 5
// Use a loop to set arr[i] = i * 2.
// Print each value using both indexing and pointer arithmetic.


int main(){
    int arr[5];

    for(int i = 0; i < 5; i++){
        arr[i] = i * 2;
    }

    // print using indexing 
    for(int i = 0; i < 5; i++){
        printf("Arr[%d]: %d\n", i, arr[i]);
    }
    
    // print using pointer arithmetic 
    int* arrPtr = arr;
    for(int i = 0; i < 5; i++){
        printf("Arr[%d] Using Pointers: %d\n", i, *(arr + i));
    }

    return 0;
}
