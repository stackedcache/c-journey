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

## MORE ADVANCED STRUCT USAGE 


