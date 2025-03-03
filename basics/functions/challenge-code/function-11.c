#include <stdio.h>

// Here we will practice everything we learned so far. 
// We will use a switch case to select and option, then
// Use a callback function to print a message.

void executeCallback(void (*func)()){
    func();
}

// Say Hello in English
void helloEnglish(){printf("HELLO!\n");}

// Say Hello in Russian informal
void helloRussian(){printf("Привет!\n");}

// Say Hello in Russian formal
void helloRussianFormal(){printf("Здравствуйте!\n");}

// Define language selection function
int languageSelection(){
    char input[3];

    while (1){   
        printf("Option 1: English\n");
        printf("Option 2: Russian Informal\n");
        printf("Option 3: Russian Formal\n\n");
        printf("Select an option: ");
        
        fgets(input, sizeof(input), stdin);

        if (input[1] == '\n' && input[0] >= '1' && input[0] <= '3'){
            return input[0] - '0'; // convert to integer with ASCII Math stuff, standard practice 
        }
        // Else if invalid choice...
        printf("\n\nInvalid choice! Try again!\n\n");
    } // END WHILE 
}


// Begin Main
int main(){
    // Create function pointers for each option 
    void (*engPtr)() = helloEnglish;
    void (*rusPtr)() = helloRussian;
    void (*rusFormalPtr)() = helloRussianFormal;

    // Take user input for menu choice
    int choice = languageSelection();
    
    // Debug, not needed in 'production'
    //printf("%d\n", choice);

    // Begin switch case 
    switch(choice){
        case 1:
            executeCallback(helloEnglish);
            break;
        case 2:
            executeCallback(helloRussian);
            break;
        case 3:
            executeCallback(helloRussianFormal);            
            break;
    }
    
    // And now, we do it a cleaner way without using switch cases 
    // Declare an array of functions
    void (*functions[3])() = {helloEnglish, helloRussian, helloRussianFormal};

    // Use the same input function to store a user choice 
    int choice2 = languageSelection();
    
    // Use the callback function and our functions array with choice - 1 to get index of users choice
    executeCallback(functions[choice2 - 1]);
   
    return 0;
}

