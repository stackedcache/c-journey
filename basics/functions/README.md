# FUNCTIONS, FUNCTIONS, FUNCTIONS!

In this section, you will find everything you need for understanding functions in C. 
Basic concepts to stack frame manipulation and GDB debugging are covered. 

## FILES AND DIRECTORIES 

- functions-notes.md
    - This file contains an overview of fundamentals to understand functions in C
    - Includes a low-level deep dive on stack frames, and related memory concepts

- stack_test.c - A reference program used in the stack frame deep dive in the functions-notes.md file 

- functions-challenges.md
    - This file contains 10 programming challenges to reinforce functions concepts 

- challenge-code (directory)
    - This directory contains the code to go with each challenge from the challenges file 
    - Also includes `function-7-gdb-notes.md` file which explores:    
        - Return address overwrites
        - Execution flow manipulation 
        - GDB debugging & memory control basics  
        
## HOW TO BUILD AND RUN 

### COMPILING EVERYTHING 
- From the basics directory, or the high level c-journey directory: 
    - run `make` which will compile all programs in /build
    - For gdb usage, it is suggested to compile on your own with `-g` debug flags, or modify the makefile to include the needed flags

### CLEANING UP
- To clean the compiled programs, run `make clean` from a directory that has a Makefile
