#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[8];
    int access_level;
} User;

int main() {
    User *u = malloc(sizeof(User));
    // Error check malloc for good practice! 
    if (!u) {  
        printf("MALLOC FAILED");
        return 1;
    }
    printf("Name before overflow: %s\n", u->name);
    printf("access_level before overflow: %d\n", u->access_level);

    // Overflow name 
    strcpy(u->name, "AAAAAAAA\x01\x00\x00\x00");

    printf("access_level after overflow: %d\n", u->access_level);

    return 0;
}


/* LEARNING NOTES

    OUTPUT:
    if copying just text, AAAAAAAA01 --> output is 49 due to ASCII encoding 

    Name before overflow: 
    access_level before overflow: 0
    access_level after overflow: 49

    - We can see that copying too much data into `name` overflows into `access_level`
    
    - If we use byte code, strcpy(u->name, "AAAAAAAA\x01\x00\x00\x00" --> access_level = 1
    - This is due to 'little-endian' systems (linux is) -- least significant byte is stored first
    - In short, the byte code for this is \x01\x00\x00\x00 -- 4 bytes in little endian
    - Copying the above strings results in access_level being 1.
*/
