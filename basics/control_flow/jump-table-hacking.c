#include <stdio.h>
#include <string.h>

void secret_function() {
    printf("\nHACKED: YOU REACHED THE SECRET FUNCTION!");
}

void menu(){
    char input[8]; // Vulnerable buffer
    int choice = 0;

    printf("Enter your choice: ");
    gets(input); // UNSAFE! Does not check input length. Overflow possible.
    
    printf("Choice read: %d\n", choice);

    switch(choice) {
        case 1: 
            printf("Option 1 selected.\n");
            break;
        case 2: 
            printf("Option 2 selected.\n");
            break;
        case 3:
            printf("Option 3 selected.\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

int main(){
    menu();
    return 0;
}
