#include <stdio.h>
// CHALLENGE 8
/* 
    - Create a struct named NetFlags that uses bitfields to:
        - set isEncrypted (1 bit)
        - set isCompressed (1 bit)
        - set protocolType (2 bits)
    
    - Initialize this struct, set each field, then print each flag.
*/

struct NetFlags{
    unsigned int isEncrypted : 1;
    unsigned int isCompressed : 1;
    unsigned int protocolType : 2;
};

typedef enum {
    UDP,
    TCP,
    OTHER,
    UNKNOWN
} ProtocolType;

int main(){
    // Map enums to strings
    char *protocolType[] = {"UDP", "TCP", "OTHER", "UNKNOWN"};

    struct NetFlags flags1 = {1, 0, 3};

    // Print the flags
    printf("Is Encrypted: %d\n", flags1.isEncrypted);
    printf("Is Compressed: %d\n", flags1.isCompressed);
    printf("Protocol Type: %s\n", protocolType[flags1.protocolType]);

    return 0;
}
