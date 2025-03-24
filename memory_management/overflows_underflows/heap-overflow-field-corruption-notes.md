# HEAP OVERFLOW - FIELD CORRUPTION 

**GOAL:** Understand how overflowing a buffer in the heap allows you to corrupt adjacent memory,
including function pointers, access levels, or behavior-critical data. 

## SCENARIO 

- You're given a struct in a C Program: 

```C 
typedef struct {
    char name[8];
    int access_level;
} User;
```

- When you `malloc(sizeof(User))`, those two members -- `name` and `access_level` -- get stored **right next to each other** in memory. 
- That means if you write more than 8 bytes to name, you overwrite memory for `access_level`. 

**WHY THIS MATTERS:**

- This is a **heap overflow:** Writing past the bounds of an allocated object. 
- This can lead to: 
    - Privilege escalation
    - Logic modification
    - Execution flow hijacking 
    - Full RCE if you can control what is overwritten

### MEMORY LAYOUT VISUAL 

- Imagine this: 

```
| char name[8] | int access_level |

/* MEMORY WISE */

[ 0x00 - 0x07 ] - name 
[ 0x08 - 0x0B ] - access_level
```

- So writing more than 8 bytes to `name` hits `access_level`

## BABY BORN EXPLOIT FORM 

```c
User *u = malloc(sizeof(User));
strcpy(u->name, "AAAAAAAAAAAAAAAA");
```

**What's Happenning?**

- "AAAAAAAAAAAAAAAA" is **16 Bytes**
- It overflows `name` which only has **8 Bytes**
- Then it smashes the `access_level` with `0x41414141` (hex for 'A')
- Printing will show the corruption. 

## TAKEAWAYS 

- Heap overflow doesn't need to be fancy to be deadly 
- This is how early malware escalated privileges
- Most real-world exploits start as memory layout abuse 
- Small corruption can lead to big behavior shifts

## Assignment:

**Write a C program that:**

    - Defines a struct with a buffer and an int field

    - Allocates it on the heap

    - Overflows the buffer with strcpy

    - Prints the value of the adjacent int before and after

    - Shows that it was overwritten by overflow

