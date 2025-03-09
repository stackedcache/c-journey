#include <stdio.h>

// Challenge 5
// Write a function void reverseString(char* str) that reverses a string in place using pointer swapping
// Don't use extra arrays, modify the original string

void reverseString(char* str){
    // Get the length of the string
    // Swap the last with the first
    // Swap second last with second
    // Do so until we reach the middle
    // Ignore '\0'
    
    // Let's get the size by counting until we hit '\0'
    int size = 0;
    while (*(str + size) != '\0'){size++;};
    // Debug print, check size
    //printf("Size after count: %d\n", size);
    
    // Now we have the size of the string, not counting '\0'
    // We can swap with this, stopping at the middle using for 
    // Subtract 1 from size to account for 0 based math
    for(int i = 0, j = (size - 1); i < j; i++, j--){
        // DEBUG PRNTS 
        //printf("Int i: %d\n", i);
        //printf("Int j: %d\n", j);
        //printf("Str i: %c\n", *(str + i));
        //printf("Str j: %c\n", *(str + j));

        char temp = *(str + i);
        *(str + i) = *(str +j);
        *(str + j) = temp;
    }
    
}

int main(){
    char str[] = "Test!";
    printf("String before reverse: %s\n", str);
    
    reverseString(str);
    printf("String after reverse: %s\n", str);


    return 0; 
}
