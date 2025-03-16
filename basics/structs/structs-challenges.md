# Challenges: Structs (C Basics)

1. Simple Struct Definition (Account Info)

    Create a struct named Account with:
        Username
        Password hash
        Balance
        Account status (active/inactive)
    Declare one instance, initialize values, and print clearly formatted output.

2. Struct for TCP Packet Header

    Define a struct called TcpHeader with realistic TCP header fields:
        Source/Destination port
        Sequence number
        ACK number
        Flags (SYN, ACK, FIN, etc.)
    Initialize an example packet struct, assign values, and print each field.

3. Array of Structs (Soldiers Platoon)

    Define a Soldier struct with name, rank, weapon, ammo, and health.
    Create an array of 5 soldiers and populate each entry.
    Print out each soldier’s information neatly using a loop.

4. Pointer to Struct (Single Soldier)

    Dynamically allocate memory for a single Soldier struct using pointers (malloc).
    Initialize the struct's fields through pointer notation (->).
    Print values, then free the allocated memory.

5. Dynamic Array of Structs (Students)

    Define a Student struct with name, grade, and student ID.
    Dynamically allocate memory for an array of 10 Student structs.
    Populate this dynamically allocated array with unique data.
    Print all student info in a loop and ensure you free allocated memory properly.

6. Nested Struct (Filesystem Metadata)

    Define a struct called FileMeta that contains nested structs for:
        Permissions (read/write/execute flags)
        Created & modified timestamps
        File size
    Initialize an instance with realistic values and print each nested member.

7. Singly Linked List of Processes

    Implement a simple singly linked list node struct (ProcessNode) representing OS processes, including:
        Process ID, Priority, Status
        Pointer to next node
    Create a simple linked list of 3 nodes and traverse it, printing each node’s data.

8. Bitfields Struct (Network Flags)

    Create a struct named NetFlags using bitfields with:
        isEncrypted (1 bit)
        isCompressed (1 bit)
        protocolType (2 bits, to represent TCP/UDP/Other)
    Initialize this struct, set each bitfield, and print out each flag clearly.

9. Struct Packing (Size Analysis)

    Define the following struct with and without __attribute__((packed)):

    ```C
    struct Example {
        char a;
        int b;
        char c;
        short d;
    };
    ```

    Use sizeof() to print out both struct sizes clearly.
    Comment briefly on why the sizes differ.

10. Memory Layout (Malware Payload Metadata)

    Create and initialize a struct named PayloadMeta with fields:
        char name[16];
        unsigned int size;
        unsigned char isEncrypted;
    Print the address of each member explicitly to illustrate memory layout clearly (using pointers or address-of operator &).


