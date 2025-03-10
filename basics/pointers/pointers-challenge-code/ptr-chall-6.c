#include <stdio.h>

// Challenge 6
// Write int findMax(int* arr, int size) that finds the largest number in an array 
// Use pointer arithmetic 

int findMax(int* arr, int size){
    int* current = arr;
    int max = 0;
    int count = 0;
    while (count < size){
        // printf("COUNT: %d\n", count);
    
        if (*current > max){max = *current;};
        current++;
        // printf("Max: %d\n", max);

        count++;
    };  



    return max;
}



int main(){
    int arr[] = {2, 25, 45, 13, 55};
    
    // Find Size 
    int size = sizeof(arr) / sizeof(int);

    int max = findMax(arr, size);
    printf("MAX: %d\n", max);

        return 0;
}
