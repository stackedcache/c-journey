#include <stdio.h>

// CHALLENGE 4 
// strCpy but reverse 
// HELLO = OLLEH

void strRev(char* dst, char* src, int size){
    int srcIndex, dstIndex;
    for(srcIndex = (size - 2), dstIndex = 0; srcIndex >= 0; srcIndex--, dstIndex++){
        *(dst + dstIndex) = *(src + srcIndex);
    }
    
    *(dst + size - 1) = '\0'; // Null Terminate the string 
}


int main(){
    char src[] = "This is backwards now!";
    char dst[sizeof(src)];
    
    strRev(dst, src, sizeof(dst));
    printf("RESULT: %s\n", dst);
    return 0;
}
