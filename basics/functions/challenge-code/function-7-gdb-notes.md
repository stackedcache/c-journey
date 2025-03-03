# DEBUGGING IN GDB
## INSPECTING THE STACK 

- Here we can see as the program runs, what stack frames are created.
- Refer to function-7.c for code, but it is very simple. One function calls another
- As we step through the code after hitting the breakpoint, we can see what stack frames exist.

```gdb
Starting program: /home/plastid-debian/projects/cjourney/basics/functions/challenge-code/function7 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, sayHello () at ./function-7.c:7
7	    printf("Здравствуйте!");

(gdb) bt
#0  sayHello () at ./function-7.c:7
#1  0x0000555555555162 in printStackInfo () at ./function-7.c:11
#2  0x0000555555555173 in main () at ./function-7.c:15

(gdb) next
8	}

(gdb) bt
#0  sayHello () at ./function-7.c:8
#1  0x0000555555555162 in printStackInfo () at ./function-7.c:11
#2  0x0000555555555173 in main () at ./function-7.c:15

(gdb) next
printStackInfo () at ./function-7.c:12
12	}

(gdb) bt
#0  printStackInfo () at ./function-7.c:12
#1  0x0000555555555173 in main () at ./function-7.c:15

(gdb) next
main () at ./function-7.c:16
16	    return 0;

(gdb) bt
#0  main () at ./function-7.c:16

(gdb) next
17	}

(gdb) bt
#0  main () at ./function-7.c:17

(gdb) next
__libc_start_call_main (main=main@entry=0x555555555165 <main>, argc=argc@entry=1, argv=argv@entry=0x7fffffffe048) at ../sysdeps/nptl/libc_start_call_main.h:74
74	../sysdeps/nptl/libc_start_call_main.h: No such file or directory.

(gdb) next
Здравствуйте![Inferior 1 (process 10062) exited normally]

(gdb) bt
No stack.
(gdb) 
```


- *NOTE*: Because of printf behavior, we do not print until we get back to main.
- Printf holds output until there is a newline, or the buffer is flushed
- In this program, there was no \n after the message, so the buffer was not flushed until returning to main. 

## ADDING \n TO THE CODE, CHECKING GDB

```gdb
(gdb) break sayHello
Breakpoint 1 at 0x113d: file ./function-7.c, line 7.

(gdb) run
Starting program: /home/plastid-debian/projects/cjourney/basics/functions/challenge-code/function7 

[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, sayHello () at ./function-7.c:7
7	    printf("Здравствуйте!\n");

(gdb) bt
#0  sayHello () at ./function-7.c:7
#1  0x000055555555515d in printStackInfo () at ./function-7.c:11
#2  0x000055555555516e in main () at ./function-7.c:15

(gdb) next
Здравствуйте!
8	}

(gdb) bt
#0  sayHello () at ./function-7.c:8
#1  0x000055555555515d in printStackInfo () at ./function-7.c:11
#2  0x000055555555516e in main () at ./function-7.c:15

(gdb) next
printStackInfo () at ./function-7.c:12
12	}

(gdb) bt
#0  printStackInfo () at ./function-7.c:12
#1  0x000055555555516e in main () at ./function-7.c:15

(gdb) next
main () at ./function-7.c:16
16	    return 0;

(gdb) bt
#0  main () at ./function-7.c:16

(gdb) next
17	}

(gdb) next
__libc_start_call_main (main=main@entry=0x555555555160 <main>, argc=argc@entry=1, argv=argv@entry=0x7fffffffe048) at ../sysdeps/nptl/libc_start_call_main.h:74
74	../sysdeps/nptl/libc_start_call_main.h: No such file or directory.

(gdb) next
[Inferior 1 (process 10533) exited normally]

(gdb) bt
No stack.
```

- Here we can see that the message is printed right away, and the execution flow and output makes a bit more sense.


## CHANGING RETURN ADDRESS AGAIN 

- Here, we will look deeper into the stack frames and see if we can may sayHello run twice
- We will need to use 'info frame', `x/10gx $rsp`, and set commands to accomplish this

**EXAMPLE SET COMMAND:**

```gdb
(gdb) set *(long*)$rsp = 0x55555555513d  # Replace with sayHello()'s address
```

- Here is the actual code and inspection: 

```gdb
(gdb) run
Starting program: /home/plastid-debian/projects/cjourney/basics/functions/challenge-code/function7 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, sayHello () at ./function-7.c:7
7	    printf("Здравствуйте!\n");

(gdb) info frame
Stack level 0, frame at 0x7fffffffdf20:
 rip = 0x55555555513d in sayHello (./function-7.c:7); saved rip = 0x55555555515d
 called by frame at 0x7fffffffdf30
 source language c.
 Arglist at 0x7fffffffdf10, args: 
 Locals at 0x7fffffffdf10, Previous frame's sp is 0x7fffffffdf20
 Saved registers:
  rbp at 0x7fffffffdf10, rip at 0x7fffffffdf18

(gdb) next
Здравствуйте!
8	}

(gdb) next
printStackInfo () at ./function-7.c:12
12	}

(gdb) x/10gx $rsp
0x7fffffffdf20:	0x00007fffffffdf30	0x000055555555516e
0x7fffffffdf30:	0x0000000000000001	0x00007ffff7df724a
0x7fffffffdf40:	0x00007fffffffe030	0x0000555555555160
0x7fffffffdf50:	0x0000000155554040	0x00007fffffffe048
0x7fffffffdf60:	0x00007fffffffe048	0x68680093bb22d5bc

(gdb) set *(long*) 0x7fffffffdf28 = 0x55555555513d

(gdb) next

Breakpoint 1, sayHello () at ./function-7.c:7
7	    printf("Здравствуйте!\n");

(gdb) finish
Run till exit from #0  sayHello () at ./function-7.c:7
Здравствуйте!
__libc_start_call_main (main=main@entry=0x555555555160 <main>, argc=argc@entry=1, argv=argv@entry=0x7fffffffe048) at ../sysdeps/nptl/libc_start_call_main.h:74
74	../sysdeps/nptl/libc_start_call_main.h: No such file or directory.
(gdb) 
```

- Here, there is nothing new compared to what we did in function notes. 
- We run the program, with a breakpoint set. 
- We inspect the stack frame, getting the memory value for the current instruction: 
    `rip = 0x55555555513d in sayHello (./function-7.c:7); saved rip = 0x55555555515d`

- We step through until we get to the printStackFrame function
- Here, we would normally have an instruction to return back to main, the caller of printStackFrame
    `0x7fffffffdf20:	0x00007fffffffdf30	0x000055555555516e`

- `0x7fffffffdf20` holds the stack frame pointer of printStackFrame
- `0x7fffffffdf28` holds the saved return address, which we overwrite

- We overwrite the value saved at 0x7fffffffdf28 (8 bits up from 0x7fffffffdf20 because of the 64-bit system)
- This makes the saved return address the address of the start of stack frame for sayHello
- This cause sayHello to execute again instead of exit to main
- Without overwriting the value, finish causes the program to complete and exit normally
- Again, not much new here but the more reps in debugging the better.
