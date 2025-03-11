#include <stdio.h>

// Challenge 10
// Write a sorting function void sort(int *arr, int size, int (*compare)(int, int))
// This takes a function pointer to decide sorting order 
// Implement two sorting functions -- ascending and descinding 
// Use bubble sort and allow sorting in asc/desc order based on given function pointer 


// Here we need to create a compare function to give qsort()
// qsort needs void pointers, so we give void* as argument, then type cast to integer within function
int compare(int a, int b){
        return a - b;
    }

// Here we write the compare for descending order 
int compareDesc(int a, int b){
        return b - a;
    }

// Write the sorting function
void sort(int* arr, int size, int (*compare)(int, int)){
    // We need to pass over the array multiple times
    // Check two values at a time, and swap if 'a' is larger than 'b'
    int* current = arr; // Set pointer to increment 
    int* next = (arr + 1); // Set next to compare
    
    int pass = 0;
    
    // Loop through the array
    for(int i = 0; i < (size - 1); i++){
    
        int swapped = 0; // Set a flag to check if a swap occurs 
        
        for(int j = 0; j < (size - pass - 1); j++){
            if(compare(*current, *next) > 0){
                int temp = *current;
                *current = *next;
                *next = temp;
                swapped = 1;
                }; 

            current = (current + 1);
            next = (next + 1);
        } // End inner for loop
        
        if(swapped == 0){break;} // if swapped is 0, it means that no swap was needed 

        pass++;
        current = arr;
        next = (arr + 1);
    } // End outer for loop

}


int main(){
    int arr[4] = {133, 2, -553, 45};
    
    // sort requires the size to be given to the function, so we get size here
    int size = sizeof(arr) / sizeof(int);
    
    // Feed to the function 
    sort(arr, size, compareDesc);
    
    printf("Array after sorting:\n");
    for (int i = 0; i < size; i++){
        printf("Array[%d]: %d\n", i, arr[i]);
    }

    return 0;
}
