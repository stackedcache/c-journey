#include <stdio.h>
#include <stdlib.h>

/* CHALLENGE 

- In challenge-code/L4-malloc-calloc-realloc.c, write a C program that:

    - Uses malloc() to create an int array of 5 elements.
    - Sets values, prints them, then realloc()s the array to 10 elements.
    - Uses calloc() to allocate a new float array of 4 elements, show that they are zero.
    - Frees both arrays properly.
*/

int main(){
    int *arr = (int *)malloc(5 * sizeof(int));
    if (!arr){
        printf("MALLOC FAILED!");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        *(arr + i) = i;
    }

    for (int i = 0; i < 5; i++) {
        printf("Arr[%d] = %d\n", i, *(arr + i));
    }

    int *tmp = realloc(arr, 10 * sizeof(int)); // reallocate memory to size of 10 ints for arr
    if (!tmp) {
        printf("REALLOC FAILED!");
        free(arr);
        return 1; 
    }
    arr = tmp; // set arr to newly allocated memory 
    
    printf("Check new slot of arr, arr[9]: %d\n", *(arr + 9));  

    // Use calloc to create a new float array of 4 elements 
    float *newArr = (float *)calloc(4, sizeof(float));
    if (!newArr) {
        printf("CALLOC FAILED!");
        return 1;
    }

    // print values of calloc arr to show they are zero 
    // This will be zero and not garbage value, compared to garbage in arr[9] above
    for (int i = 0; i < 4; i++) {
        printf("Value of calloc float array[%d]: %f\n",
            i, *(newArr + i));
    }
    
    free(arr);
    free(newArr); // Always free! 

    return 0;
}

