#include <stdio.h>
// CHALLENGE 1 
// SIMPLE STRUCT DEFINITION 

/* 
    Create a struct named Account with:
        - Username 
        - Password hash
        - Balance
        - Account Status (active, inactive)

    - Declare one instance 
    - Initialize values 
    - Print output
*/

struct Account{
    char name[20];
    char passwordHash[20];
    int balance;
    unsigned int isActive : 1; // 1 Active, 0 inactive 
};

int main(){
    struct Account account1 = {"Razval", "abc123", 25000, 1};

    // Print values cleanly
    printf("Account Name: %s\n", account1.name);
    printf("PW Hash: %s\n", account1.passwordHash);
    printf("Account Balance: %d\n", account1.balance);
    
    if (account1.isActive == 1){
        printf("Account is Active!\n");
    } else {
        printf("Account is deactivated.\n");
    }
    
    return 0;
}

/* FEEDBACK NOTES 
    Next-level notes (small tips):

        Bitfield Usage:
        Bitfields are usually reserved for memory-sensitive apps (like embedded/network). 
        In simpler structs, regular types (int isActive) are common. 

        Password Hash storage:
        Typically, you'd want a longer storage buffer 
        (e.g., SHA-256 hashes are 64 chars hex-encoded). 
        20 chars would limit secure hashing methods. 
        Consider larger buffers in practical scenarios.
*/
