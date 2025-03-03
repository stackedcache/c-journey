#include <stdio.h>
#include <stdlib.h> // Needed for qsort 

// Create an integer array and sort it using qsort
// Write a custom compare function that sorts in ascending order
// Print array before and after sorting 

// Here we need to create a compare function to give qsort()
// qsort needs void pointers, so we give void* as argument, then type case to integer within function
int compare(const void* a, const void* b){
        return *(int*)a - *(int*)b;
    }

// Here we write the compare for descending order 
int compareDesc(const void* a, const void* b){
        return *(int*)b - *(int*)a;
    }


int main(){
    int arr[4] = {1, 25, 4, 32};
    
    // qsort requires the size to be given to the function, so we get size here
    int size = sizeof(arr) / sizeof(int);
    
    // Print the array before sorting
    printf("ARRAY BEFORE SORTING\n");
    for (int i = 0; i < size; i++){
        printf("Array[%d]: %d\n", i, arr[i]);
    }

    printf("\n\n");

    // Here we feed the array and required parameters to qsort
    qsort(arr, size, sizeof(int), compare);

    // Print the array after sorting ascending
    printf("ARRAY AFTER SORTING IN ASCENDING ORDER\n");    
    for (int i = 0; i < size; i++){
        printf("Array[%d]: %d\n", i, arr[i]);
    }

    printf("\n\n");

    // Now sort for ascending order 
    qsort(arr, size, sizeof(int), compareDesc);
    
    // Print the array after sorting descending
    printf("ARRAY AFTER SORTING IN DESCENDING ORDER\n");    
    for (int i = 0; i < size; i++){
        printf("Array[%d]: %d\n", i, arr[i]);
    }
    
    return 0;
}
