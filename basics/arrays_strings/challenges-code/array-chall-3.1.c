#include <stdio.h> 
// Re-writing from memory without notes 

void strCpy(char* dst, char* src, int size){
    int i;
    for (i = 0; i < (size - 1); i++){
        *(dst + i) = *(src + i);
    }
    printf("i after for: %d\n", i);
    *(dst + i) = '\0';

}


int main(){
    char src[] = "TEST";
    char dst[sizeof(src)];

    strCpy(dst, src, sizeof(dst));
    printf("DESTINATION RESULT: %s\n", dst);
    
    // TEST SIZE 
    int size = sizeof(src);
    printf("SIZE: %d\n", size);
    return 0;
}
