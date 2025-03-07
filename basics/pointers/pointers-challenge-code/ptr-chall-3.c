#include <stdio.h>

// Challenge 3 - Pointer based string length calculator 
// Write a function that calculates the length of a string
// Use pointer arithmetic instead of array indexing 
// Return the length of the string 

int strLen(char* str){
    // Check each position of the array with pointer math
    // While the value is not '\0', increment length
    int len = 0;
    for(; *(str + len) != '\0'; len++);    
    return len;
}

int main(){
    // Arrays decay to pointers, so we don't need to declare any pointer
    // It is already a pointer
    char string[] = "STRING LENGTH 18!";
    
    // Here we feed the string array (pointer) to the integer function
    // Setting int len so that the return type is matcheh
    int len = strLen(string);
    printf("%d\n", len);

    return 0;
}
