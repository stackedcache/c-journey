# INTRO 

- Note: This file contains the challenges I went through, and a bunch of notes I took as I went through them.
- There is a lot of "junk" in this file, like my thoughts and roadblocks I hit before getting to the code you see in .c files of this section
- If it's interesting to you, read! Probably it won't be though, but I'm leaving it just for history and my self to refer to for now. Enjoy! :) 

💻 Coding Challenges (To Cement Control Flow)

🔥 Level 1 – Basic Reinforcement

    Write a CLI menu using switch-case
        The user picks 1, 2, or 3 → output different responses.
        Add a default case for invalid input.
    
    - Completed -- control_flow_challenges.c code -- could go deeper with input validation here, but basic flow understood.

    Write an authentication system using if-else
        Ask the user for a password.
        If "letmein", print "Access Granted".
        Else, print "Access Denied".
    
    - Completed with advanced checks from level 2 -- control_flow_challenges.c code

🛠️ Level 2 – Thinking Like a Hacker Simulate a Login Bypass

    Write an if (strcmp(password, "letmein")) statement.
    Experiment with passing "letmein\0" or "letmeinanything"—see what happens.
    
    - Completed -- control_flow_challenges.c code 

    Exploit a switch-case Fall-Through Bug
        Create a switch where missing a break lets a lower-level user get admin privileges.
    
    - Skipping this challenge -- I understand that missing breaks can cause fallthrough bugs 


💣 Level 3 – Breaking Control Flow Modify Execution Flow in GDB

    Write a simple function with return 1;
    Run it in gdb, change the return value to 0 at runtime.
    Understand how return addresses affect execution.

    Jump Table Corruption (Advanced)
        Write a switch-based function.
        Use a buffer overflow to modify its case value and force execution of unintended code.



## CHALLENGE NOTES 

- Challenge 1 I am tripped up on how to take user input, then convert it into a constant for the switch case 
- I know scanf takes input, but as of now only know to store in variable, which switch won't take 
- Doing research before asking for examples 

- scanf can take a format specifier, so I will take it as int %d

- Now thinking about how to restart if no valid input given.. wrap in while
- Riffing with AI about potential solutions while instructing not to give me code
- AI suggesting interesting apporaches while also tying in how each could be exploited potentially 
- Will try now to wrape in while with control variable and see if I can get running 

- Ok.. i wrapped in while, and with valid input all works but if invalid, I have an infinite loop condition for some reason... 
- Will check into this to get ideas from AI without providing my code and trying to debug just thinking
- I have a control variable set to 1, and set to 0 if valid input given. 
- Then switch default case just says invalid, and does not change control variable 
- So not sure why it starts infinite looping 

- OK, got it. AI gave hints and I determined that it's because scanf is not cleaning the input so;
- It's just re-reading the same bad input over and over again. Need to sanitize user input 

- Ok, there are multiple ways to sanitize input... we are trying to focus on control flow here and just get used to 
- writing swtich cases, but this is also valuable.

- If knowing how to sanitize input, we can know where others might fail.

- So what is the problem? We want to take input from the user, and make sure in this case it is ONLY an integer..
- fgets is possible, and loop is possible to read and clear. 
- Just to move on to next concepts, in the default case I will read and clean scanf .. i think
- No, needed to put scanf within an if, check that it != 1 and this will clean bugger with getchar()
- This moves to default switch case 
- because choice is not set, default case is hit, valid check still 1, while repeats
- 1, 2, or 3 hits valid case to break while 

- scanf doesn't behave exactly how i want. example, if user enteres 1rrewtw it will just read 1. 
- However, for a basic program where we're really just practicing switch case, this is ok for now
- for the next challenge, I will practice using fgets() and see if behavior is improved (depending on challenge) 


# CHALLENGE 1 PT 2 

- Password system mockup, if else 
- Questioning whether to use string.h or re-write functions my self 
- For now, I will use string, later we can try to recreate library functions 
- Here i will use strcspn to do check if password is too long, if not, trim newline
- strcspn() Basic Syntax:

size_t strcspn(const char *str1, const char *str2);

    str1: The string to be scanned.
    str2: The string containing characters to match.
    Returns: The index (position) in str1 where the first character from str2 is found.
    If no characters from str2 are found in str1, it returns the length of str1.

- So... what do we need to do? 
- The user is instructed to enter a password of 7 characters
- This means in a correct strcspn case, it should return 8 (7 characters + \n)
- if not 8, print the password is too long, and take another password 
- if 8, replace \n with \0 and move on 
- Actually.. we need to check if short or long. Because user presses enter, will always have a \n
- Therefore, if shorter than 8, password too short, if longer, too long

- Ok.. lots of realizations. I was trying to check if longer than 7 letters, but this is pointless because fgets stops this
- If user enters more than 8 characters, i should clear the buffer with `while (getchar() != '\n' && getchar() != EOF);`
- I overcomplicated the checking and code, but from  a lack of understanding of the functions used -- working now to just check password
- I have really confused my self. I have not gotten the code straight from AI or internet yet. This is what i had: 

```
    while (1) { 
        printf("Enter the secret password, then press enter.\n"
        "The password should be 7 characters only, to 'let you in': ");
        // Use fgets to take input from the user 
        fgets(password, sizeof(password), stdin);
        printf("RETURN OF STRCSPN: %d\n\n", strcspn(password, "\n"));
        if (strcspn(password, "\n") == 7){
            // Clear buffer of stdin because newline wasnt found, meaning input too long
            while (getchar() != '\n' && getchar() != EOF);
            printf("\n\nPassword too long!. Try again!\n\n");
            continue;
        } else if (strcspn(password, "\n") < 7){
            
            printf("\n\nPassword too short!. Try again!\n\n");
            password[strcspn(password, "\n")] = '\0';  // Removes \n if present
            
            // strcmp to check password
            if (strcmp(password, "letmein") < 1){
                printf("\n\nPassword too short. Try again!\n\n");
                continue;
            } else if (strcmp(password, "letmein") == 0) {
                printf("\n\nACCESS GRANTED!\n\n");
                break;
            } else {
            printf("\n\nPassword incorrect. Try again.\n\n");
            continue;
            }
        }
    } 
```

- I will just read the hints again and try to do more simple checks 
- AI suggested this logic, i will just try to implement 

🎯 Control Flow You Actually Want (Logic Only):

1️⃣ User inputs password with fgets().
2️⃣ Check length:

    < 7 → “Too short”
    > 7 → “Too long” (you’ll detect this because fgets() won’t capture \n)
    == 7 → Proceed to comparison
    3️⃣ Check exact match:
    If "letmein" → "ACCESS GRANTED"
    Else → "Incorrect password"


- I got it! 

```
   // Level 1 pt 2 - Write an authentication system using if else 
   // Ask the user for a password
   // If "letmein" print "Access Granted"
   // Else, print Access "Access Denied" 

    // Create string array to store password 
    char password[8];
    
    while (1) { 
        printf("Enter the secret password, then press enter.\n"
        "The password should be 7 characters only, to 'let you in': ");
        // Use fgets to take input from the user 
        fgets(password, sizeof(password), stdin);
        
        // Debug
        printf("RETURN OF STRCSPN: %d\n\n", strcspn(password, "\n"));
        printf("Strlen(): %d\n\n", strlen(password));
        
        // Check if password is too short
        if (strlen(password) < 7){
            printf("\n\nPassword too short!. Try again!\n\n");
            continue;
        } else if (strcspn(password, "\n") == 7){
            if (strcmp(password, "letmein") == 0){
                printf("\n\nACCESS GRANTED!\n\n");
                // Clear the buffer to get rid of waiting \n
                while (getchar() != '\n' && getchar() != EOF);
                break;
            } else {
                printf("\n\nPassword too long!. Try again!\n\n");
                // Clear the buffer because input was too long
                while (getchar() != '\n' && getchar() != EOF);
                continue;
            }
        } else {
            printf("Unhandled error....\n\n");
            continue;
        }
    }
        
    // End of while 
    printf("Outside loop");
```

- This was a big brain teaser for me...
- There was lots of thinking through nested syntax, and how to logically check each condition
- Ends up to work as tested, but for a 'real program' would need improved.
- For some reason, if password is too long, sometimes i have to hit enter twice.
- Could quick f5 compile from vim, will build and test.

- Got this error on make because of strict compile rules:

control_flow/control_flow_challenges.c:64:37: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t’ {aka ‘long unsigned int’} [-Wformat=]
   64 |         printf("RETURN OF STRCSPN: %d\n\n", strcspn(password, "\n"));
      |                                    ~^       ~~~~~~~~~~~~~~~~~~~~~~~
      |                                     |       |
      |                                     int     size_t {aka long unsigned int}
      |                                    %ld
control_flow/control_flow_challenges.c:65:28: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘size_t’ {aka ‘long unsigned int’} [-Wformat=]
   65 |         printf("Strlen(): %d\n\n", strlen(password));
      |                           ~^       ~~~~~~~~~~~~~~~~
      |                            |       |
      |                            int     size_t {aka long unsigned int}
      |                           %ld
Compiling variable_types/variable_types.c -> ../build/basics/variable_types/variable_types
gcc -Wall -Wextra -pedantic -o ../build/basics/variable_types/variable_types variable_types/variable_types.c
plastid-debian@plastid-linux:~/projects/cjourney/basics$ 

- Fix by removing prints or doing %lu

- This did fix compile
- doing make did not change the double enter behavior. 
- I will now show my code to AI, ask about this double enter thing to see if I can figure out, and then sleep

- Right now, I am focusing on why the prompt "hangs" sometimes after input is too long as in: 
- The prompt does not print right away after an input that is long. It prints the "too long" message, then sits, waiting for enter
- Simply puts() instead of print did not fix, AI suggesting to flush stdout, will try
- fflush(stdout); after the puts also does not solve it. Trying fflush(stdout) after the too long
- also not a fix!
- AI suggested a more "aggressive" flush with this method

```
int c;
while ((c = getchar()) != '\n' && c != EOF);
```

- This does stop the problem! Why? 
- AI says stdin and terminal buffering 
- When entering more than expected by fgets, stdin stores ALL of it in terminal 
- fgets() reads ONLY what it can get .. 7 chars + \0 (size 8)
- all of the extra STAYS in stdin
- getchar() reads one character at a time 
- long story short, something about the buffering of stdout / stdin was causing this
- For now, because main focus is just control flow, not going to super deep dive this

- We still have a problem -- if user enters 'letmein-bunchofjunkextra' -- it still grants access
- To fix this, we should store in fgets enough for both \n and \0 (size 9)
- Then, we should stringcompare only for EXACT matches

- COOL! I implemented everything, and it seems to work as intended! 
- Issue is my nested ladders are a bit ugly and could probably be done better
- We have gone way deeper than basic if else compare check for this basic section, but thats not horrible.
- I asked AI to clean my code up, and will possibly come back to clean this later.
- For now, committing and moving on 

# CHALLENGE 3 - GDB DEBUGGING AND HACKING 

- Will work with AI to step through and 'hack' with gdb. New code for this one.
- Return 1 indicates failure, so may be used to terminate on something like authentication checking
- bypassing this we can possibly hijack control flow

- Created gdb-control-flow-tests.c
- This code defines checkpassword() and authenticate() functions
- in authenticate(), if checkpassword() returns 1, authenticate  prints access denied and returns 1
- checkpassword() is simply coded to return 1
- after the if check in authneticate(), i added print HACKED! just to see if we can bypass
- by setting break in gdb at authenticate, and changing the register value from 1 to 0 (because checkpassword did return 1)
  we bypass control flow and print HACKED.

- Here is how that looked: 

```
plastid-debian@plastid-linux:~/projects/cjourney/basics/control_flow$ gcc -g ./gdb-controlflow-tests.c -o gdb-control-flow-tests
plastid-debian@plastid-linux:~/projects/cjourney/basics/control_flow$ gdb ./gdb-control-flow-tests 
GNU gdb (Debian 13.1-3) 13.1
Copyright (C) 2023 Free Software Foundation, Inc.

<snip>

Reading symbols from ./gdb-control-flow-tests...

(gdb) break authenticate
Breakpoint 1 at 0x1148: file ./gdb-controlflow-tests.c, line 8.

(gdb) run
Starting program: /home/plastid-debian/projects/cjourney/basics/control_flow/gdb-control-flow-tests 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, authenticate () at ./gdb-controlflow-tests.c:8

8	    if (checkpassword() == 1) {

(gdb) step
checkpassword () at ./gdb-controlflow-tests.c:4
4	    return 1;

// CHECK WHAT THE REGISTER HOLDS, STEP UNTIL ITS SET TO 1:
(gdb) info registers rax
rax            0x0                 0
eax            0x0                 0

(gdb) step
5	}

(gdb) info registers rax
rax            0x1                 1

// SET THE REGISTER TO 0 TO BYPASS FAILURE 
(gdb) set $rax=0

// CHECK REGISTERS 
(gdb) info registers rax
rax            0x0                 0

// CONTINUE TO SEE OUTPUT 
(gdb) continue
Continuing.



HACKED!!!!!


[Inferior 1 (process 88466) exited normally]
(gdb) 
```

- Here we can see how manipulating register values can modify program control flow 


