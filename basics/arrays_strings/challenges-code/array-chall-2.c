#include <stdio.h> 

// CHALLENGE 2 
// Use gets and fgets to compare behavior on a defined buffer 

void clear_stdin(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main(){
    char buffer[10];

    printf("Enter something (unsafe gets): ");
    gets(buffer);
    printf("Unsafe input: %s\n", buffer);
    
    /* COMMENTING OUT INPUT WITHOUT ERROR CHECK 

    printf("Enter something (safe fgets): ");
    fgets(buffer, 10, stdin);
    printf("Safe input: %s\n", buffer);
    
    // Note that this will crash the program when taking input that is too long.
    // This is because fgets does NOT clear the input if what's given is too long 
    // We'll createa function to clear the input buffer and use error checking to fix
    */

    // Adding error checking to fgets 
   
    int valid = 1;
    while(valid){
        printf("Enter 8 Characters (safe fgets): ");
        
        if (fgets(buffer, sizeof(buffer), stdin) != NULL){
            int newline_found = 0;

            // Manually check if a newline exists inside buffer 
            for (int i = 0; i < sizeof(buffer) - 1; i++){
                if (buffer[i] == '\n'){
                    newline_found = 1;
                    break;
                }
            }

            if (!newline_found) { 
                clear_stdin(); // Clear the buffer because input was too long.
                printf("You entered too many characters. Try again\n");
                buffer[0] = '\0'; // Set first index to terminator to clear the string 
                continue;
            } else {
                printf("You entered: %s\n", buffer);
                valid = 0;
            }
        } // END OUTER IF 
    } // END WHILE 
    
    return 0;
}

/* NOTE:
    
    Enter something (unsafe gets): 1234567890waytoolong                     
    Unsafe input: 1234567890waytoolong
    Enter something (safe fgets): 1234567890waytoolong
    Safe input: 123456789

    Command terminated

    Press ENTER or type command to continue

    Here we see that fgets terminates when input is too long.

    Now let's go back and add error checking.
    
    We wrapped the conditions in a while, with a valid flag that equals 1.
    While runs while the condition is true, so we set true to start.

    We then check if newline is found. For a 10 char buffer, that gives us 8 characters because we need \n and \0

    We continue the while to give the user another chance

    If newline is found, input was valid, so we print and set valid to 0 to break the while. 

*/
