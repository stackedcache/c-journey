#include <stdio.h>

// CHALLENGE 9 - STRUCT PACKING 
/*
    - Define an example struct with char, int, char, short
    - Make one struct packed, and one not packed
    - Use sizeof to print both sizes and note the difference 
*/

struct Example{
    char a;
    int b;
    char c;
    short d;
};

struct __attribute__((packed)) Example2{
    char a;
    int b;
    char c;
    short d;
};

int main(){
    struct Example example1 = {'A', 2, 'C', 1};
    struct Example2 example2 = {'A', 2, 'C', 2};

    printf("Size of Example: %lu\n", sizeof(example1));
    printf("Size of Example2: %lu\n", sizeof(example2));

    return 0;
}

/* LEARNING NOTE 
    char is 1 byte
    int is 4 bytes
    short is 2 bytes

    Therefore we expect the struct to be 1 + 4 + 1 + 2 = 8 bytes
    However unpacked is 12 due to padding.
    Packed is 8 as expected. 
*/
