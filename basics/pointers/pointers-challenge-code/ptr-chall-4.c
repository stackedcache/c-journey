#include <stdio.h>

// Challenge 4
// Write void strCopy(char* dest, char* src) that copies a string from src to dest
// Use pointer arithmetic
// Make sure to copy \0 at the end

void strCopy(char* dst, char* src){
    // While i != '\0', copy from src to dst
    // Add '\0' at i + 1 -- which is the index where '\0' belongs using ptr arithmetic
    int i = 0;
    for(; *(src + i) != '\0'; i++){
        *(dst + i) = *(src + i);
    }
    
    // add one to i to get the index where '\0' is needed
    i += 1;
    *(dst + i) = '\0'; 
}


int main(){
    char src[] = "HELLO!";
    int srcSize = sizeof(src);
    char dst[srcSize];

    printf("string from src: %s\n", src);
    printf("String from dst before copy: %s\n\n", dst);
    
    // Checking length of src
    printf("Length of src: %d\n", srcSize);

    // Checking length of dst
    int dstSize = sizeof(dst);
    printf("Length of dst: %d\n\n", dstSize);

    // Call our string copy function 
    strCopy(dst, src);
    printf("String from dst after copy: %s\n", dst);
    
    return 0; 
}
