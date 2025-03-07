#include <stdio.h>

// Reverse and Array using Pointers 
/*
    TASK:
    - Write a function reverseArr(int *arr, int size)
    - Swap the first and last elements, the second / second-last, etc.
    - Print the array before and after swapping.
*/

// Here we use int temp to store a value temporarily.
// In theory, this uses 'extra' memory.
// XOR swapping could be done instead, and is pure memory manipulation.

void reverseArr(int* arr, int size){
  int temp;
  for(int i = 0, j = (size - 1); i < j; i++, j--){
    temp = *(arr + i);
    *(arr + i) = *(arr + j);
    *(arr + j) = temp; // In these statements, we use pointer math to access array values, not index based.
  }
}


int main(){
    int array[] = {20, 30, 40, 50, 60};
    int size = sizeof(array) / sizeof(array[0]);
    
    // Loop and print array 
    printf("Before swapping array:\n");
    for (int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    
    printf("\n\n"); // Formatting cleanup. Print newline.
    // Swap array with function 
    reverseArr(array, size);

    // Loop and print array 
    // For cleaner code, this print array loop could also be stored in a function.
    // Looping twice like this is redundant, but the point here is pointer math for swapping. 
    printf("After swapping array:\n");
    for (int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }

    return 0;
}
