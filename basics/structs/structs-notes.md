# STRUCTS IN C 

## WHAT IS A STRUCT? 

- A struct is short for structure, which is a custom data-type that groups multiple variables under one name. 
- This can be thought of as a blueprint for an object. 
- Instead of managing multiple separate values, we group them into a single unit. 
- Real-world objects such as network packets, sockets, files, userdata, and payloads are represented in C. 

## WHY USE STRUCTS? 

- Helps to organize related data. 
- Mimics real-world memory layouts (Critical for reverse engineering, exploits, and binary parsing) 
- Structs manipulate memory at a low level. (Important for shellcode, network packets, and fuzzing)
- Used everywhere in OS internals, networking, and exploit development. 

## BASIC STRUCT SYNTAX 

- Declaring a struct 

**EXAMPLE:**

```C
struct User {
    char name[20];
    int age;
    float balance;
};
```

- This creates a 'User' type that has: 
    - A char array `name` for storing a name.
    - An int `age` for storing age. 
    - A float `balance` for storing a balance

## USING A STRUCT  (CREATING AND ACCESSING) 

```C
#include <stdio.h> 

struct User{
    char name[20];
    int age;
    float balance;
};

int main(){
    struct User u1 = {"userName", 25, 1000.99};

    printf("Name: %s\n", u1.name);
    printf("Age: %d\n", u1.age);
    printf("Balance: %.2f\n", u1.balance);

    return 0;
}
```

- You access struct members with dot notation (`u1.name, u1.age, etc`)


## POINTERS AND STRUCTS 

```C
#include <stdio.h>

struct User{
    char name[20];
    int age;
    float balance;
};

int main(){
    struct User *usrPtr1 = malloc(sizeof(struct User)); // Allocate memory dynamically 

    userPtr1->age = 25; // use -> instead of . for pointers 
    userPtr1->balance = 250.75;

    printf("Age: %d\n", userPtr1->age);
    printf("Balance: %.2f\n", userPtr1->balance);

    free(userPtr1); // Always free memory! 

    return 0;
}
```

**WHY USE POINTERS?**

- Allows dynamic allocation of memory for structs (network buffers, working with the heap)
- userPtr1-> is notation for accessing struct members when using pointers. 

## ARRAYS OF STRUCTS 

**What is an Array of Structs?**

- An array of structs is a collection of multiple struct objects stored in contiguous memory. 
- Instead of managing multiple variables individually, we group similar objects together. 
- Useful for storing multiple, students, cars, network packets, etc. 

**DECLARING AN ARRAY OF STRUCTS:**

```C
struct Student{
    char name[20];
    int grade;
};

struct Student students[3]; // creates an array of 3 student structs.
```

- Each element in `students[]` is a struct Student 
- Just like an array of `int` or `char`, it's stored in contiguous memory. 

### ASSIGNING VALUES TO STUCT ARRAY ELEMENTS 

- *Note:* Since char name[20] is a character array, we must use `strcpy()` for assignment.

```C
#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int grade;
};

int main() {
    struct Student students[2];  // Declare an array of structs

    // Assign values (Use strcpy for name)
    strcpy(students[0].name, "John");
    students[0].grade = 85;

    strcpy(students[1].name, "Eric");
    students[1].grade = 99;

    // Print values
    for (int i = 0; i < 2; i++) {
        printf("Student %d: Name: %s, Grade: %d\n", i + 1, students[i].name, students[i].grade);
    }

    return 0;
}
```

#### ASSIGNING VALUES TO STRUCT ARRAY AT INITILIZATION 

- If you already know the values at compile-time, you can initialize directly: 

```C
struct Student students[3] = {
    {"John", 85},
    {"Eric", 99},
    {"Lisa", 92}
};
```

- This avoids `strcpy()` since it's set at declaration. 

#### ARRAY OF STRUCTS WITH DYNAMIC MEMORY 

- To allocate an array of structs dynamically, use `malloc()`

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char name[20];
    int grade;
};

int main() {
    int numStudents = 2;
    
    // Allocate array dynamically
    struct Student *students = malloc(numStudents * sizeof(struct Student));

    // Assign values
    strcpy(students[0].name, "John");
    students[0].grade = 85;

    strcpy(students[1].name, "Eric");
    students[1].grade = 99;

    // Print values
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d: Name: %s, Grade: %d\n", i + 1, students[i].name, students[i].grade);
    }

    // Free memory
    free(students);
    return 0;
}
```
**Summary (Best Practices)**

- Use strcpy() to assign string values in structs (char name[20]).
- Use a for loop to iterate over struct arrays (students[i].name).
- Use malloc() for dynamic struct arrays (struct Student *students = malloc(...)).
- Free dynamically allocated memory to avoid leaks.


## MORE ADVANCED STRUCT USAGE 

1. Nested Structs (Structs inside structs, for complex data structures)
2. Pointers to Structs (Dynamic allocation, linked lists, efficient memory use)
3. Bitfields (Packing small data to save memory, used in networking & OS)
4. Struct Packing & Alignment (Memory optimization, struct exploi

