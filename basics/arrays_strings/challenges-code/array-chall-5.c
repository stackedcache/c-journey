#include <stdio.h>

// CHALLENGE 5
// strLen -- count how many characters in a given string 

int strLen(char* str){
    if(*str == '\0'){
        printf("EMPTY STRING!\n");
        return 0;
    }
    
    int len = 0;
    
    while(*str != '\0'){
        len++;
        str++;
    }
     
    return len;
}


int main(){
    char str[25] = {'T', 'E', 'S', 'T', '\0'};

    int len = strLen(str);
    printf("Length of string: %d\n", len);
    return 0;
}
