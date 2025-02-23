💻 Coding Challenges (To Cement Control Flow)

🔥 Level 1 – Basic Reinforcement

    Write a CLI menu using switch-case
        The user picks 1, 2, or 3 → output different responses.
        Add a default case for invalid input.

    Write an authentication system using if-else
        Ask the user for a password.
        If "letmein", print "Access Granted".
        Else, print "Access Denied".

🛠️ Level 2 – Thinking Like a Hacker Simulate a Login Bypass

    Write an if (strcmp(password, "letmein")) statement.
    Experiment with passing "letmein\0" or "letmeinanything"—see what happens.

    Exploit a switch-case Fall-Through Bug
        Create a switch where missing a break lets a lower-level user get admin privileges.

💣 Level 3 – Breaking Control Flow Modify Execution Flow in GDB

    Write a simple function with return 1;
    Run it in gdb, change the return value to 0 at runtime.
    Understand how return addresses affect execution.

    Jump Table Corruption (Advanced)
        Write a switch-based function.
        Use a buffer overflow to modify its case value and force execution of unintended code.


