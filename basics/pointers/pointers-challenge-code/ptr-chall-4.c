#include <stdio.h>

// Challenge 4
// Write void strCopy(char* dest, char* src) that copies a string from src to dest
// Use pointer arithmetic
// Make sure to copy \0 at the end

void strCopy(char* dst, char* src){
    // While i != '\0', copy from src to dst
    // Add '\0' at the end
    // Loop stops when \0 is hit, leaving i = the index where '\0' belongs using ptr arithmetic
    int i = 0;
    for(; *(src + i) != '\0'; i++){
        *(dst + i) = *(src + i);
    }
    
    // add one to i to get the index where '\0' is needed
    *(dst + i) = '\0'; 
}

// The above function was written with zero reference to notes or other code
// Let's compare to how the "real" string copy function is written.

char* realStrCpy(char* dst, const char* src){
    char* original = dst; // store original pointer for return value 
    while ((*dst++ = *src++)); // Copy each character including '\0'
    return original; // Return pointer to start of destination string
}

int main(){
    char src[] = "HELLO!";
    int srcSize = sizeof(src);
    char dst[srcSize];

    printf("string from src: %s\n", src);
    
    // Checking length of src
    printf("Length of src: %d\n", srcSize);

    // Checking length of dst
    int dstSize = sizeof(dst);
    printf("Length of dst: %d\n\n", dstSize);

    // Call our string copy function 
    strCopy(dst, src);
    printf("String from dst after copy: %s\n", dst);
    

    // Testing 'real' string copy 
    char realTestSrc[] = "REAL COPY!";
    int realTestSize = sizeof(realTestSrc);
    char realTestDst[realTestSize];

    realStrCpy(realTestDst, realTestSrc);
    printf("Copy with 'real' function: %s\n", realTestDst);
    return 0; 
}
