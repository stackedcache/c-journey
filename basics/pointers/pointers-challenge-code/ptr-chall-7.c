#include <stdio.h>

// Challenge 7
// Find the first occurence of a character in a string 
// Write char* findChar(char *str, char ch) that returns a pointer to
// the first occurence of the given character in str ch.

// Use pointer math, no indexing

char* findChar(char* str, char ch){
    // Increment through char* str, checking against ch
    // If *str = ch, stop and return
    
    while (*str != ch && *str != '\0'){
        str++;
    }
    
    if (*str == '\0'){
        return NULL;
    };

    return str;
}

int main(){
    char string[] = "TESS!";
    char* stringPtr = string;
    
    // Feed the pointer to the function and check
    char* result = findChar(stringPtr, 'T');
    
    if(result != NULL) {
        printf("Result: %c is found at position: %ld\n", *result, result - stringPtr);
    } else {
        printf("NOT FOUND!\n");
    }
}

/* 
    # LEARNING NOTES: 

    Here is the original implementation of this function in C's string library: 

    ```
    char *strchr(const char *str, int ch) {
        while (*str) {
            if (*str == ch)
                return (char *)str; // Cast because str is `const char *`
            str++;
        }
        return NULL; // If `ch` isn't found, return NULL
    }
    ```

    - This is basically the same thing, my function is just a bit different
    - Additional note on pointer math:
        - We could do ptr - str with placeholder %ld (long integer) in printf to get the position
        - ptr - str calculates the offset between ptr relative to string (the position) 
        - Since ptr and str are both char*, subtracting them gives the difference in memory locations 
        - This difference represents the index-based position of the character. 
        - I have added an example print with this just for example purposes.
*/
