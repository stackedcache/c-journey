#include <stdio.h>

/*
- Variables are *placeholders* in memory where data is stored.
- They need a type, and a name 

Syntax: data_type variable_name = value;

## COMMON VARIABLE TYPES IN C:
-int    ; 4 bytes ; ex: int num = 10;
-char   ; 1 byte  ; ex; char c = 'A';
-float  ; 4 bytes ; ex; float dec = 3.5;
-double ; 8 bytes ; ex; double d = 3.141592;
-long   ; 8 bytes ; ex; long l = 1000L;

There are other types like unsigned int, short, long double.

# sizeof()
- Tells you the amount of bytes a data type or variable is taking up in memory
- Возвращает размер типа данных в байтах


# TYPE CONVERSIONS 
- Implicit type conversion -- automatically converts smaller types to bigger types
ex; int a = 5; double b = a;

- Explicit type conversion (casting) -- You tell C to convert from one type to another 
ex; double num = 5.55; 
    int int_num = (int) num;

# SCOPE AND LIFETIME OF VARIABLES 
- Local variables -- Declared inside a function/block. Only accessible there.
- Global variables -- Declared outside functions. Can be used from anywhere in the file.
- Static variables -- Keep their value, even after a function ends.
*/

// Create a function that modifies a global variable 
void modify_global(int *a){
   *a = 100;
}

// Create function to modify a static integer 
void demonstrate_static(){
    static int staticCount = 0;
    staticCount++;
    printf("Value of staticCount is now: %d\n", staticCount);
}


// Declare variables of each type 
int a_global = 25; // Глобальная переменная - Global Variable 
int b_global = 533333;

char charA = 'A';
char name[7] = "ALEX";

float float1 = 3.5;

double doub = 3.141592;

long longvar = 1000L;

int main(){

// Print the value and size of each variable type
printf("VARIABLE VALUES AND SIZES\n");
printf("=========================\n\n");
printf("Integer a_global has Value: %d and size: %lu-bytes\n", a_global, sizeof(a_global));
printf("Character charA has Value: %c and size: %lu-bytes\n", charA, sizeof(charA));
printf("Character name has Value: %s and size: %lu-bytes\n", name, sizeof(name));
printf("Float float1 has Value: %f and size: %lu-bytes\n", float1, sizeof(float1));
printf("Double doub has Value: %f and size: %lu-bytes\n", doub, sizeof(doub));
printf("Long longvar has Value: %ld and size: %lu-bytes\n\n\n", longvar, sizeof(longvar));

// Practice Explicit casting 
// Cast Double to Int
printf("Casting practice. Here doub is casted to an integer," 
"and b_global is casted to a character\n\n");

int casted_int = (int)doub;
printf("casted_int has value %d and size: %lu-bytes\n", casted_int, sizeof(casted_int));

// Cast Int to Char
char casted_char = (char)b_global;
printf("casted_char has value %c and size: %lu-bytes\n\n", casted_char, sizeof(casted_char));


/* TYPE CONVERSION CHALLENGE 

Write a program that:
- Accepts a double value from the user (scanf())
- Converts it to an int and a char
- Prints all three values 

*/
printf("TYPE CONVERSION CHALLENGE\n");
printf("=========================\n\n");
printf("Enter a value to store in double: ");

double userlong;

// If the user enters a non-integer value, output is invalid, 
// but will handle error-checking and sanitation in future modules 
scanf("%lf", &userlong);

// Print the value
printf("You entered %lf and stored in long variable userlong.\n\n", userlong);

printf("Now we explicitly convert the variable.\n\n");

// Conversions 
int userlong_int = (int)userlong;
printf("userlong converted to int: %d and stored in int variable userlong_int.\n", userlong_int);

char userlong_char = (char)userlong;
printf("userlong converted to char: %c and stored in char variable userlong_char.\n\n", userlong_char);


printf("Now we use a function to modify a global variable.\n"
"The original value is %d, and we pass an integer pointer to a"
"function to change the value.\n\n", a_global);

// Create a pointer to pass the value to the function 
int *a_globalptr = &a_global;

modify_global(a_globalptr);

printf("Int variable a_global has been modified to: %d\n\n\n", a_global);

// Use a constant variable in another function and show how it retains value over calls
// Static int
printf("Now we demonstrate a static integer variable," "
and watch how it changes across function calls.\n\n");

printf("Static int staticCount is defined as 0 initially," "
and the function adds 1 each call. We call it 3 times.\n\n");

demonstrate_static();
demonstrate_static();
demonstrate_static();

return 0;   
}


