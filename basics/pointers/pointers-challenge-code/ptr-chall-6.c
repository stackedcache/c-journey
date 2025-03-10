#include <stdio.h>

// Challenge 6
// Write int findMax(int* arr, int size) that finds the largest number in an array 
// Use pointer arithmetic 

int findMax(int* arr, int size){
    // Create a pointer to increment starting at the beginning of arr
    int* current = arr;

    // Create an int to hold the max value 
    int max = 0;

    // Loop through the array, until current is equal to the last value of arr
    while (current != arr + size){
        
        // Set the value of max to current, if current is greater than existing value
        if (*current > max){max = *current;};
        current++;

    };  
    
    return max;
}

int main(){
    int arr[] = {2, 25, 45, 13, 55, 54, 345, 1000};
    
    // Find Size 
    int size = sizeof(arr) / sizeof(int);

    int max = findMax(arr, size);
    printf("MAX: %d\n", max);

        return 0;
}
