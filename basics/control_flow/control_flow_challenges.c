#include <stdio.h>
#include <string.h>

int main(){
        // Wrap this in While, to repeat user input until valid input is given
    // Create variable to track with while, set 0 on valid input, keep 1 for invalid
    int valid_check = 1;
    
    while (valid_check == 1){
        // Write a CLI menu using switch-case 
        // User picks 1, 2, or 3 -- output different responses.
        // Add default case for invalid input 

        printf("Enter an option (1, 2, or 3):\n\n"
            "1. Get a greeting\n"
            "2. Get an Insult\n"
            "3. Move to next part of the program\n\n");
    
        // Create int variable to store user input 
        int choice; 
        
        // scanf is a poor choice, for next inputs we will use fgets and practice sanitation
        // Edit: Original scanf did not error check, potential to cause infinite loop
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        // Clean buffer after scanf
        while(getchar() != '\n' && getchar() != EOF);
        
        switch (choice){
            case 1:
                printf("Hello cool person!\n\n");
                valid_check = 0;
                break;
            case 2:
                printf("You suck!\n\n");
                valid_check = 0;
                break;
            case 3:
                printf("Moving to next challenge\n\n");
                valid_check = 0;
                break;
            default:
                printf("\n\nInvalid choice! Try again...\n\n");
                break;
        }
    }
   
   // Level 1 pt 2 - Write an authentication system using if else 
   // Ask the user for a password
   // If "letmein" print "Access Granted"
   // Else, print Access "Access Denied" 

    // Create string array to store password 
    char password[9];
    
    while (1) { 
        printf("Enter the secret password, then press enter.\n"
        "The password should be 7 characters only, to 'let you in': ");
        
        // Use fgets to take input from the user 
        fgets(password, sizeof(password), stdin);
        
        // Check if password is too short
        if (strlen(password) < 8){
            puts("\n\nPassword too short!. Try again!\n\n");
            continue;
        
        // Check if \n is in the password, if not, it is long
        
        } else if (strchr(password, '\n') == NULL){
           puts("\n\nPASSWORD TOO LONG. Try again!\n\n");
           // CLEAR BUFFER OF EXTRA INPUT 
           int c;
           while ((c = getchar()) != '\n' && c != EOF);
           continue;
        
        } else {
            if (strchr(password, '\n') != NULL){
                password[strcspn(password, "\n")] = '\0';
            } if (strcmp(password, "letmein") == 0) {
                puts("\n\nACCESS GRANTED!\n\n");
                break;
            } else {
                puts("\n\nPassword incorrect....\n\n");
                continue;
            } // CLOSES NESTED ELSE 
        } // CLOSES FINAL ELSE 
    } // CLOSES WHILE 
        
    // End of while 
    printf("Outside loop");


    return 0;
}
