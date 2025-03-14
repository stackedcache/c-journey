#include <stdio.h>

// CHALLENGE 3
// Write a function strcpy(char dst[], char src[]) that copies from src to dest 

#define MAXSIZE 10 // Define a max size to copy 

void strCpy(char* dst, char* src, int size){
    int i;
    for(i = 0; i < (size - 1) && *(src+i) != '\0'; i++){
        *(dst + i) = *(src + i);
    }
    *(dst + i) = '\0';
}


int main(){
    char src[] = "THIS IS DOING COPY!";
    char dst[MAXSIZE];

    strCpy(dst, src, MAXSIZE);

    printf("Destination: %s\n", dst);

    return 0;
}


