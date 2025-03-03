#include <stdio.h>

// Create a buffer overflow scenario where a function writes more data than a buffer can handle.
// Observe what happens to surrounding memory


// Create a function to write past array bounds 
void returnArray(int *array){
    for (int i = 0; i < 250; i++) {
        array[i] = i;
        if (i % 25 == 0){printf("Writing array[%d], value: %d\n", i, i);}
    }
}

int main(){
    int arr[2];
    int nextInt = 2000;
    
    returnArray(arr);
    
    // Check what happened in nextInt
    printf("nextInt: %d\n", nextInt); // Value gets overwritten, because the functions goes way out of bounds

    // Check an out-of-bounds value
    printf("array[20]: %d\n", arr[20]);

    return 0;
}
