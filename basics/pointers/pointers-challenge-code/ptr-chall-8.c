#include <stdio.h> 
#include <stdlib.h> // For malloc()

// Challenge 8
// Write char* duplicateStr(char* str) that creats a dynamic copy of the given string
// Use malloc() to allocate memory for the new string
// Return a pointer to the new string

// Example usage: 
/*
    ```
    char* copy = duplicateStr("cybersecurity");
    printf("Copy: %s\n", copy);
    free(copy); // Always free allocated memory 
    ```
*/

// LOGIC:
// Get the count of characters from str (X)
// Dynamically allocate memory for X + 1 in a character pointer 
// Copy the characters from str to copy using pointer arithmetic 
// Return the character pointer 
  
char* duplicateStr(char* str){  
    // Get the size 
    int size = 0; // Create integer to hold the size of the string 
    while(*str){
        str++; // Move the pointer in memory 
        size++; // Add one to size for every move to count characters 
        printf("SIZE IN WHILE: %d\n", size);
    }

    // Need to move the str pointer back to 0
    str = (str - size);
    printf("Checking str after subtracting size: %c\n", *str);
    
    // Dynamically allocate memory for the new char pointer 
    char* copy = (char *)malloc((size + 1) * sizeof(char));
    
    // Copy the characters from str to copy using pointer arithmetic 
    while(*str){
        printf("Current str: %c\n", *str);
        printf("Current copy: %c\n", *copy); 
        *copy++ = *str++;
    }

    // The while stops at the index of \0
    // So here, we copy null terminator to copy, which is sitting at 
    // The index where it belongs already, due to the previous while.
    *copy = '\0';

    // Checking copy after copying:
    copy = (copy - size); // Move copy back to the beginning
    printf("Copy after while: %s\n", copy);

    return copy;
}


int main(){
    //char* copy = duplicateStr("Кибербезопасность");
    //printf("Copy: %s\n", copy);
    //free(copy);

    char* copy = duplicateStr("Кибербезопасность");
    // Print to check if it worked: 
    printf("\nCopy outside of the function, in main: %s\n", copy);
    free(copy); // Always free :)

    return 0;
}

/* LEARNING NOTES:
    - I have chosen to leave debug prints in place to show my thought process, 
    and how I came up with the logic of getting this to work, checking each step.

    - I noticed that when using Cyrillic characters, they are not single bytes
    - Cyrillic characters can be 2 bytes or more, which increases the size
    - The totally correct way to handle this is using wide characters (wchar_t)
        - wchar_t supports wide characters (2+ bytes per character) 
    
    - Would also need to do sizeof(wchar_t) for allocation 
    - Would need %ls instead of %s in printf. 
    - Since my programs will never target russian / chinese systems or other friendly locales,
    this is not so important. 

    - Since this is a learning exercise, it will be left as is. 
    - Key concepts to go deeper on this are system locale, UTF-8 vs UTF-16
    - Can be investigated further when we reach OS internals.


    # NOTES ON LIBRARY STYLE VS MY IMPLEMENTATION 
    
    - The library style uses extra pointers to store the starting position of the str pointer
    - My implementation uses pointer arithmetic to move back to the 0 index position 
    - The library way is slightly more readable, my implementation is slightly more efficient 
    - The amount of memory saved with my implementation is miniscule, and doesn't really matter 
    - To me it made more sense just to move back to the start, and im practicing pointer math anyway 
    - My implementation also does not check for malloc failure -- we will get in the habit of this once
    we reach memory management section. I should add it now, but I'm a bit lazy. Kill me! :P 

    - Here is the library style version of string copy: 

    ```
    #include <stdio.h>
    #include <stdlib.h> // For malloc()

    char* duplicateStr(const char* str) {
        // Step 1: Store the original pointer before modifying it
        const char* original = str;
    
        // Step 2: Find the length of the string
        int size = 0;
        while (*str++) size++;

        // Step 3: Allocate memory for the new copy (size + 1 for '\0')
        char* copy = (char*)malloc((size + 1) * sizeof(char));
        if (!copy) return NULL; // Handle malloc failure

        // Step 4: Store the original copy pointer before modifying it
        char* copyStart = copy; 

        // Step 5: Copy characters from original string to new string
        while (*original) {
            *copy++ = *original++;
        }

        // Step 6: Null terminate the copied string
        *copy = '\0';

        // Step 7: Return the original start of the new string
        return copyStart;
    }

    int main() {
        char* copy = duplicateStr("Кибербезопасность");
        if (copy) {
            printf("Copy: %s\n", copy);
            free(copy); // Always free allocated memory
        }
        return 0;
    }
    ```
    
    - It is not much different than mine, but maybe slightly more readable, and 0 debug prints (obviously).
    - I am happy with what I have learned, and will leave things as is for now. Enjoy! 
    
    - Note regarding copy of '\0'
    - There is a small chance that my implementation may not copy \0 where expected 
    - The better, and standard practice way is to do the while loop as done in the library implementation 

    ```
    while((*copy++ = *str++));
    ```

    - This includes \0 automatically 
    - Is cleaner and does not require manually adding the \0. 

    - As previously mentioned, I will leave the code as is, to illustrate to my self and others this pointer learning process. 
    - Now I know it is possible to just copy one dereferenced pointer to another, until reaching the end with: 

    ```
    while((*copy++ = *str++));
    ```

    - This while is saying that while there is value in *copy, set *str equal to this value, then increment each pointer onc
    value of the pointer type forward in memory. In our case, one byte because it is a character pointer. 

*/
