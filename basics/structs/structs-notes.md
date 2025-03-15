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

### ASSIGNING VALUES TO STRUCT ARRAY ELEMENTS 

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


## NESTED STRUCTS (STRUCTS ON STRUCTS ON STRUCTS)

- Nested structs allow you to organize data into hierarchical structures 
- Useful for network packets, filesystem structures, and metadata handling 

**EXAMPLE NESTED STRUCT WITH CAR ENGINE**

```C
#include <stdio.h> 

// Engine Struct
struct Engine{
    int horsepower;
    int displacement;
};

// Car struct that contains an engine
struct Car{
    char name[20];
    int year;
    struct Engine engine;
};

int main(){
    struct Car car1 = {"FORD", 2001, {180, 2.0}};

    printf("Car Name: %s\n", car1.name);
    printf("Engine Horsepower: %d\n", car1.engine.horsepower);

    return 0;
}
```

### WHY USE NESTED STRUCTS? 

- Organizes data in a useful, hierarchical way 
- Mimics real-world objects more accurately
- Makes memory layout and serialization easier (critical in network packets)


## POINTERS TO STRUCTS 

- Instead of storing structs on the stack, you can dynamically allocate memory on the heap
    - Used for linked lists, trees, and other dynamic data structures 

**EXAMPLE OF DECLARING A STRUCT DYNAMICALLY**

```C
#include <stdio.h> 
#include <stdlib.h>

struct User{
    char name[20];
    int age;
};


int main(){
    struct User *user1 = (struct User *)malloc(sizeof(struct User)); // Allocate memory for one User struct 

    // Assign values
    snprintf(user1->name, "John");
    user1->age = 20;

    // Print 
    printf("User: %s, Age: %d\n", user1->name, user1->age);

    free(user1); // Always free dynamic memory

    return 0;
}
```

### WHY USE STRUCT POINTERS? 

*Note:* snprintf() is a function that formats a string and stores it in a buffer, 
but only up to a specified size to avoid buffer overflow.

- Allows for dynamic allocation of memory instead of storing on the stack 
- Essential for linked lists, trees, and advanced data structures 
- Used in kernel development, networking packets, and file systems 

**LINKED LIST EXAMPLE** 

- A linked list is a series of structs, where each struct points to the next one 
- Used in malware for process injection and evasion techniques 

**EXAMPLE: Signle Linked List with Structs:**

```C
#include <stdio.h>
#include <stdlib.h>

// Node Struct 
struct Node{
    int data;
    struct Node *next; // Pointer to next node 
};

// Function to create a new node
struct Node* createNode(int value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main(){
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Print the List 
    struct Node *temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    return 0;
}
```

### WHY USE LINKED LISTS? 

- Avoids fixed-size memory issues, more flexible than arrays 
- Used in OS task scheduling, memory allocation, and malware techniques 
- Can be extended into trees, graphs, and other data structures 


## BITFIELDS (Optimizing Memory Usage)

- Bitfields allow you to store small values in a struct while using minimal amounts of memory.
- Used in networking (protocol headers), OS kernel structures, and low-level bit maniuplation.

**EXAMPLE: Using Bitfields in a Structure:**

```C
#include <stdio.h>

struct NetworkFlags{
    unsigned int isEncrypted : 1 // 1 bit 
    unsigned int isCompressed : 1 // 1 bit 
    unsigned int protocolType : 2 // (00 = TCP, 01 = UDP, etc.)
    unsigned int reserved : 4 // (unused, but reserved for future use)
};

int main(){
    struct NetworkFlags packet = {1, 0, 1, 0};

    printf("Is Encrypted: %d\n", packet.isEncrypted);
    printf("Is Compressed: %d\n", packet.isCompressed);
    // and so on. . . 

    return 0;
}
```

### WHY USE BIT FIELDS? 

- Allows for storing small amounts of memory -- only the amount of bits specified
- Used in networking (TCP/IP headers), OS kernel flags, and embedded systems 
- Perfect for binary-level exploit development and low-level hacking 


## STRUCT PACKING AND ALIGNMENT (Memory Optimization and Exploitation)

- Compilers add padding bytes between struct members for performance reasons.
- This wastes memory and can affect binary exploitation techniques. 
- `__attribute__((packed))` removes this padding to save space 

**EXAMPLE: Normal Struct with Padding**

```C
#include <stdio.h>

struct Normal{
    char a; // 1 byte
    int b; // 4 bytes 
    short c; // 2 bytes 
};

int main(){
    printf("Size of Normal Struct: %lu bytes\n", sizeof(struct Normal));
    return 0;
}
```

- On most systems, this will show 12 bytes, even though it seems there should only be 7 bytes
- This is due to compiler added padding 

**REMOVING PADDING WITH `__attribute__((packed))` 

- Packing a struct removes unnecessary padding, saving space and making memory predictable 

**EXAMPLE: STRUCT PACKING**

```C
#include <stdio.h> 

struct __attribute((packed)) Packed {
    char a;
    int b;
    short c;
};
```

- This would show only 7 bytes instead of 12 bytes 

**WHY IS THIS USEFUL?**
- Saves memory in performance-critical applications (embedded systems)
- Prevents unexpected offsets in memory (important in networking, OS dev, reverse engineering)
- Exploits often depend on precise memory layout -- packing helps make memory layout predictable. 


