#include <stdio.h>

// Write a function getStaticArray() that returns a pointer to a static array of integers.
// Print the array in main().

// Here we have to pass *size (pass by reference) for dynamic printing later 
// The function takes an integer by reference as a parameter, 
// so that it can modify 'size' for persistence after the function exist
// We then use that size variable to loop for printing

int* getStaticArray(int* size){
    static int arr[4] = {1, 2, 3, 4};
    *size = sizeof(arr) / sizeof(arr[0]);
    return arr; // Returns a pointer to the array 
}

int main(){
    int size; 

    // Call the function and pass size integer by reference 
    int* ptr = getStaticArray(&size);
    
    // Loop to print the array 
    for (int i = 0; i < size; i++){
        printf("%d, ", ptr[i]);
    }

    return 0;
}
