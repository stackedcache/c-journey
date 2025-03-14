#include <stdio.h>

int main(){
    // Declare an integer array 
    int arr[4] = {1, 2, 3, 4};

    // Declare a pointer to an integer array 
    int* arrPtr = arr;

    // Print the memory addresses of elements in the array
    printf("Address of Element 1: %p\n", &arr[0]); // index-based access 
    printf("Address of Element 2: %p\n", &arr[2]);
    printf("Address of Element 3: %p\n", (arrPtr + 3)); // pointer arithmetic based access 
    
    // Access the array with a loop
    for(int i = 0; i < 4; i++){
        printf("arr[%d]: %d\n", i, *(arrPtr + i));
    }
 
    return 0;
}

