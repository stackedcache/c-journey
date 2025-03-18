#include <stdio.h>

// CHALLENGE 10
/*
    - Create and initialize a struct named PayloadMeta with fields:
        - char name[16]
        - unsigned int size
        - unsigned char isEncrypted
    
    - Print the address of each member explicitly to illustrate memory layout 

*/

struct PayloadMeta{
    char name[16];
    unsigned int size;
    unsigned char isEncrypted; // 0 Not Encrypted / 1 Encrypted 
};

int main(){
    struct PayloadMeta payload;
    snprintf(payload.name, sizeof(payload.name), "%s", "payload1");
    payload.size = 25; // size
    payload.isEncrypted = 1; // isEncrypted
    

    struct PayloadMeta *pl1 = &payload;
    
    // Print the addresses using the pointer 
    printf("Address of name: %p\n", pl1->name);
    printf("Address of size: %p\n", (void *)&(pl1->size));
    printf("Address of isEncrypted: %p\n", (void *)&(pl1->isEncrypted));
    
    // Print value of name
    printf("\nNAME: %s\n", pl1->name);
    return 0;
}
