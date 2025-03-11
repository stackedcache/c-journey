# FUNCTIONS IN C

(What I learned today)

- Functions in C allow for code re-use and modularity
- A function in C is defined with returnType functionName (arguments) {} 
- To use a function, it must be declared before main() or you must use prototypes 
- qsort is built in to stdlib.h in C, and requires a compare function to know what type of data is being sorted
- Bubble sort is a slow but common learning algorithm for sorting objects that beginners can use for learning
- Values should always be returned properly from functions when needed
- These notes will be updated with more detail as study continues. 


# DEEP DIVING FUNCTIONS 

## WHAT IS A FUNCTION

- A function is a block of reusable code that performs a specific task.
- In C, every function:
    - Takes input
    - Processes something
    - Returns output (or is return type void if nothing is returned)

BASIC SYNTAX: 

```C

return_type function_name(parameter_1, parameter_2, . . .){
    // FUNCTION BODY 
    return value; // (optional, and based on return_type)
}

```

## FUNCTION PROTOTYPES (DEFINITION vs DECLARATION)

### FUNCTION DECLARATION 

- Also known as prototype 
- Tells the compiler about the function return type, parameters, and name 
- Avoids implicit declaration errors 

```C
#include <stdio.h>

// прототип функция 
// Function Prototype 

int multiply(int, int)

int main(){

    int result = multiply(2, 2);
    printf("Product: %d\n", result);
    return 0;
}

// Function definition 
int multiply(int a, int b){
    
    return a * b;

}

```

## FUNCTION PARAMETERS 

### PASS BY VALUE (Default) 

- Function gets a **copy** of the argument 
- Changes inside the function, but does not affect the original variable 

```C
#include <stdio.h>

void changeValue(int x) {
    x = 100;  // Only changes local x, not original
}

int main() {
    int num = 10;
    changeValue(num);
    printf("num: %d\n", num); // Still 10
    return 0;
}
```

- Even though x changes within the function, it remains unchanged outside the function. 

### PASS BY REFERENCE (Using Pointers) 

- Function gets the address of the argument (variable) 
- Changes affect the original value 

```C 
#include <stdio.h> 

void changeValue(int *x){
    *x = 100;
}

int main(){
    int num = 10;
    changeValue(&num);
    printf("num: %d\n", num); // Now 100
    return 0;
}
```

- Pointers allow modification of the variable outside the function 
- Pointer exercises in following sections will reinforce this deeper 


## FUNCTIONS RETURNING POINTERS 

- Useful for modifying large data sets 
- Useful for dynamic memory allocation 

### EXAMPLE 

```C
#include <stdio.h>

int *getArray() {
    static int arr[3] = {1, 2, 3};
    return arr;
}

int main(){
    int *ptr = getArray();
    printf("%d\n, ptr[0]); // 1
    return 0;
}
```

- *Note*: Statis is needed because if arr was local, it would not exist after the function returns. 


## FUNCTION POINTERS (Into Only) 

- Function pointers and working with pointers in fucntions will be visited more deeply in coming sections on pointers 
- Functions ALSO have memory addresses 
- You can store a functions address in a pointer 

```C
#include <stdio.h>

void hello() {
    printf("Hello, my friend!\n");
}

int main() {
    void (*funcPtr)() = hello;  // Store function address
    funcPtr(); // Call function via pointer
    return 0;
}
```

- This is foundational for advanced concepts like callbacks, plugin systems, and dynamic execution 


## FUNCTION RECURSION (When a function calls itself) 

- A function calls itself until a base condition has been met 
- Used in traversal, backtracking, sorting, etc. 

```C
#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    printf("Factorial of 5: %d\n", factorial(5));
    return 0;
}
```

- Each call pushes data onto the stack until the base condition stops it 


## INLINE FUNCTIONS (Compiler optimization) 

- Suggests that that compiler replace the function call with its code to reduce function call overhead 

### EXAMPLE USING INLINE KEYWORD 

```C
#include <stdio.h>

inline int square(int x) {
    return x * x;
}

int main() {
    printf("Square: %d\n", square(4));
    return 0;
}
```

*Note*: The compiler may ignore inline keyword if it choses not to optimize. 


## VARIABLE ARGUMENT FUNCTIONS (<stdarg.h>) 

- Allows a function to accept a variable amount of arguments -- printf() uses this 

```C
#include <stdio.h>
#include <stdarg.h>

void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        printf("%d ", va_arg(args, int));
    }
    va_end(args);
}

int main() {
    printNumbers(3, 10, 20, 30);
    return 0;
}
```

*Note*: `va_list()`, `va_start()`, and `va_arg()` enable handling unknown argument counts.



## STACK FRAMES & FUNCTION CALLS - Low Level Breakdown 

### What Happens When You Call a Function? 

- When calling a function in C, the computer follows a step by step process to execute it 
- This process uses the "stack" 
- The stack is like a 'pile of plates' 
    - Each function call adds a new plate to the top of the stack
    - Each function return removes that plate from the top of the 'pile'

- EXAMPLE FUNCTION: 

```C
#include <stdio.h> 

void say_hello(){
    printf("Здравствуйте!\n");
}

int main(){
    say_hello();
    return 0;
}
```

- When `say_hello()` is called, the CPU:
    - Saves the current location (where main() left off)
    - Creats a new 'stack frame' for `say_hello()` 
    - Executes the code in the function 
    - Removes `say_hello()`'s stack frame (pops it off the stack)
    - Resumes execution in main() after the function call (return address) 


### WHAT'S INSIDE THE STACK FRAME 

- Every function gets a stack frame when it runs, and every stack frame gets:

    - Return Address - where to return when function ends 
    - Saved Registers - Important CPU values 
    - Function Arguments - Any values passed to the function 
    - Local Variables - variables inside the function 


### VISUALIZATION OF STACK FRAME IN GDB 

- Compile with debugging info: 
`gcc -g stack_test.c -o stack_test`

*Note*: The -g flag adds debugging symbols, so GDB can find details 

- Run dbg
`dbg ./stack_test.c`

- Set a breakpoint at `say_hello`
`break say_hello`

- Start the program
`run`

- Print the stack
`bt`

```gdb
(gdb) run
Starting program: /home/plastid-debian/projects/cjourney/basics/functions/stack_test 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, say_hello () at ./stack_test.c:4
4	    printf("Привет!");

(gdb) bt
#0  say_hello () at ./stack_test.c:4
#1  0x0000555555555162 in main () at ./stack_test.c:8
```

- `bt` shows the stack trace, listing all function calls 

- Inspect the frame
`info frame`

```gdb
(gdb) info frame
Stack level 0, frame at 0x7fffffffdfa0:
 rip = 0x55555555513d in say_hello (./stack_test.c:4); saved rip = 0x555555555162
 called by frame at 0x7fffffffdfb0
 source language c.
 Arglist at 0x7fffffffdf90, args: 
 Locals at 0x7fffffffdf90, Previous frame's sp is 0x7fffffffdfa0
 Saved registers:
  rbp at 0x7fffffffdf90, rip at 0x7fffffffdf98
```

- This shows the return address, saved registers, and local variables
- rip - this is the instruction pointer, which is the memory address of the next instruction to execute within the function 
- saved rip - this is where execution will return after `say_hello` finishes
    - We can see from the stack trace that this is the address of main()

- These concepts are critical for understanding return-oriented programming and buffer overflow exploitations 
- Looking back into the control flow section, you will find notes that explain overwriting the return address with a buffer overflow to control execution flow

- `called by frame at` -- this tells the stack frame of the caller (previous function) 
- Since `say_hello` was called by main, this is main's stack frame 
- This shows how the 'stack' is linked -- each function knows who called it and how to return when execution is finished 

- `Arglist` is the fuctions arguments, in this case empty because `say_hello` has no arguments 
    - If a function had arguments, their values would be stored here 

- `locals at` - this explains where local variables are stored 
    - `previous frames sp is` tells where the last functions stack frame ended 

- `saved registers` -- every time a function is called certain registers need to be saved so they can be restored when the function ends 
    - registers are small temporary memory locations inside a cpu. They hold temporary values needed for calculations, memory access, and execution
    - As we get deeper into assembly, this will be more important and make more sense 

- `rbp` is base pointer, Points to the start of this function's stack frame 
- `rip` is instruction pointer, Stores where to continue execution adter this function ends 
    - rbp helps the computer keep track of function frames
    - rip is the return address, critical in buffer overflow exploits 

### RETURN ADDRESS EXAMPLE 

- Here we will manually overwrite the saved rip to return to `say_hello` instead of main

```gdb
(gdb) x/10gx $rsp
0x7fffffffdf90:	0x00007fffffffdfa0	0x0000555555555162
0x7fffffffdfa0:	0x0000000000000001	0x00007ffff7df724a
0x7fffffffdfb0:	0x00007fffffffe0a0	0x0000555555555154
0x7fffffffdfc0:	0x0000000155554040	0x00007fffffffe0b8
0x7fffffffdfd0:	0x00007fffffffe0b8	0xc110720402bf72f6

(gdb) set *(long*)0x00007fffffffdfa0 = 0x55555555513d
```

- Here we set the memory address ending dfa0 to the value ending 513d -- which is say hello's rip, instead of ending in 5162 which is the rip for main! 

```gdb
(gdb) run
Starting program: /home/plastid-debian/projects/cjourney/basics/functions/stack_test 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, say_hello () at ./stack_test.c:4
4	    printf("Привет!");
(gdb) info frame
Stack level 0, frame at 0x7fffffffdfa0:
 rip = 0x55555555513d in say_hello (./stack_test.c:4); saved rip = 0x555555555162
 called by frame at 0x7fffffffdfb0
 source language c.
 Arglist at 0x7fffffffdf90, args: 
 Locals at 0x7fffffffdf90, Previous frame's sp is 0x7fffffffdfa0
 Saved registers:
  rbp at 0x7fffffffdf90, rip at 0x7fffffffdf98
(gdb) x/10gx $rsp
0x7fffffffdf90:	0x00007fffffffdfa0	0x0000555555555162
0x7fffffffdfa0:	0x0000000000000001	0x00007ffff7df724a
0x7fffffffdfb0:	0x00007fffffffe0a0	0x0000555555555154
0x7fffffffdfc0:	0x0000000155554040	0x00007fffffffe0b8
0x7fffffffdfd0:	0x00007fffffffe0b8	0x07a64aceed35756e
(gdb) set *(long*)0x7fffffffdf98 = 0x55555555513d
(gdb) x/10gx $rsp
0x7fffffffdf90:	0x00007fffffffdfa0	0x000055555555513d
0x7fffffffdfa0:	0x0000000000000001	0x00007ffff7df724a
0x7fffffffdfb0:	0x00007fffffffe0a0	0x0000555555555154
0x7fffffffdfc0:	0x0000000155554040	0x00007fffffffe0b8
0x7fffffffdfd0:	0x00007fffffffe0b8	0x07a64aceed35756e
(gdb) stepi
0x0000555555555144	4	    printf("Привет!");
(gdb) stepi
0x0000555555555147	4	    printf("Привет!");
(gdb) stepi
0x000055555555514c	4	    printf("Привет!");
(gdb) stepi
0x0000555555555030 in printf@plt ()
(gdb) stepi
0x0000555555555036 in printf@plt ()
(gdb) stepi
0x000055555555503b in printf@plt ()
(gdb) stepi
0x0000555555555020 in ?? ()
(gdb) x/10gx $rsp
0x7fffffffdf80:	0x0000000000000000	0x0000555555555151
0x7fffffffdf90:	0x00007fffffffdfa0	0x000055555555513d
0x7fffffffdfa0:	0x0000000000000001	0x00007ffff7df724a
0x7fffffffdfb0:	0x00007fffffffe0a0	0x0000555555555154
0x7fffffffdfc0:	0x0000000155554040	0x00007fffffffe0b8
(gdb) set *(long*)0x7fffffffdf98 = 0x55555555513d
(gdb) x/10gx $rsp
0x7fffffffdf80:	0x0000000000000000	0x0000555555555151
0x7fffffffdf90:	0x00007fffffffdfa0	0x000055555555513d
0x7fffffffdfa0:	0x0000000000000001	0x00007ffff7df724a
0x7fffffffdfb0:	0x00007fffffffe0a0	0x0000555555555154
0x7fffffffdfc0:	0x0000000155554040	0x00007fffffffe0b8
(gdb) set *(long*)0x7fffffffdf88 = 0x55555555513d
(gdb) x/10gx $rsp
0x7fffffffdf80:	0x0000000000000000	0x000055555555513d
0x7fffffffdf90:	0x00007fffffffdfa0	0x000055555555513d
0x7fffffffdfa0:	0x0000000000000001	0x00007ffff7df724a
0x7fffffffdfb0:	0x00007fffffffe0a0	0x0000555555555154
0x7fffffffdfc0:	0x0000000155554040	0x00007fffffffe0b8
(gdb) continue
Continuing.

Breakpoint 1, say_hello () at ./stack_test.c:4
4	    printf("Привет!");
(gdb) 
```

- Here we hit the breakpoint set in gdb, and inspect the stack and frame
- We see where the rip (return address is stored) 
- We step through function execution, inspecting the stack again just before we expect it to return (after print finishes) 
- We see that the address has changed -- originally the rip was stored at address ending df90
- Right before return, we see return is now stored in df80
- We knew value ending 5151 is the address of main, so we change it to the address of `say_hello` ending in 513d
- Note that we have to change the address of df88, not df80
    - This is because two values are stored here, 8 bytes each (64-bit system). df80 is the starting point, so df88 is where the rip is stored 
- We see that by manually overwriting this value to point back to `say_hello` -- the function executes again instead of returning to main and exiting.


### CONCLUSION 

- This concludes the basic study of functions for now.
- In the pointers section, we will go deeper into using pointers with functions
- Exercises will inforce basic function definition, declaration, and use, while also reinforcing debugging topics
- stepi is a powerful tool in gdb, it allows for checking execution instruction by instruction, helping us verify changes before execution 
- As time and understanding progress, these concepts are critical for securing or exploiting programs by understanding how the stack works,
and how execution flows in a program. 

- By controlling saved rip, we control execution flow. This is the foundation of ROP chains and function hijacking (more to come)



