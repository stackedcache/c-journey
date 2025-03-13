# CONTROL FLOW 

Control flow determines how a program executes based on conditions, loops, and jumps. 

## CONDITIONAL STATEMENTS 

Conditional statements are used to make decisions. 

- **if statement:**

    - Executes a block, if the condition evaluates as true. 

```C
if (x > 0){
    printf("Do this. . .\n");
}
```

- **if else statement:**
    
    - Executes different blocks based on the conditions 

```C
if (x > 0){
    printf("X is positive. . .\n");
} else {
    printf("X is negative. . .\n");
}
```

- **if else if else ladder:**

    - For multiple conditions 

```C
if(x > 0){
    printf("X is positive. . .\n");
} else if(x < 0){
    printf("X is negative. . .\n");
} else {
    printf("X is 0. . .\n");
}
```

- **Switch statements:**

    - Alternative to if-else chains
    - Effective for discrete values 

```C
switch (x){
    case 1:
        printf("1. . .\n");
        break;
    case 2:
        printf("2. . .\n");
        break;
    case 3:
        printf("3. . .\n");
        break;
    default:
        printf("Other. . .\n");
        break;
}
```

    - break; prevents 'fall through' condition where other cases are executed
    - default case -- is optional but recommended. 

## Looping Constructs 

Loops execute blocks repeatedly. 

- **While loops:**

    - Executes **while** the condition is true.

```C
int i = 0;
while(i < 5) {
    printf("i = %d\n", i);
    i++;
}
```

- **do-while loops:**

    - Executes at least once before checking the condition

```C
int i = 0;
do {
    printf("i = %d\n", i);
    i++;
} while (i < 5);
```

- **for loops:**

    - Most commonly used loop
    - Format: initilization -> condition -> increment/decrement

```C
for(int i = 0; i < 5; i++){
    printf("i = %d\n", i);
}
```

    - sets i = 0
    - while i < 5, execute the block
    - Then increment / decrement (this case is increment)
    - This would print i five times (0, 1, 2, 3, 4) and stop once i = 5

## LOOP CONTROL STATEMENTS 

These statments are used to modify loop execution.

- **break:**

    - exits loop immediately 

```C
for (int i = 0; i < 10; i++){
    if (i == 5){
        break;
    }
    printf("i = %d\n", i);
}
```

- **continue:**

    - skips execution of the rest of the loop's body for that iteration, but does not break the loop

```C 
for(int i = 0; i < 10; i++){
    if ( i % 2 == 0) { continue; } // skips even numbers
    printf("i = %d\n", i);
}
```

- **goto:**

    - Considered bad practice in C, but exists
    - With goto, a label is set, and goto jumps to that label

```C 
int i = 0;
start: 
    printf("i = %d\n", i);
    i++;
    if (i < 5) goto start;
```

- **Early function exit - return:**
    
    - Used to return from functions early 

```C
int add(int a, int b){
    if (a == 0){
        return b;
    }
    return a + b;
}
```

    - **return** exis a function and optionally returns a value. 

- **Ternary operators (Shorthand for if-else):**

```C
int max = (a > b) ? a : b;
```

- The above code is equivalent to 

```C
if (a > b){
    max = a;
} else {
    max = b;
}
```

- **Infinite loops:**

    - Used when you don't want termination 

```C 
while(1){
    printf("Running forever\n");
}
```

- Using for

```C
for (;;) {
    printf("Running forever\n");
}
```

- Both are functionally equivalent 


## NESTED LOOPS 

- Useful for grids, matrices, sorts (bubble sort)

```C
for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5 - 1; j++){
        printf("%d %d\n", i, j);
    }
}
```

**BEST PRACTICES:**

- Use for loops when count is low 
- Use while when condition controls execution 
- Avoid goto, unless absolutely needed
- Use `break` and `continue` to control execution wisely (not excessively). 


- Some examples exist within challenges, and we will use these constructs throughout the rest of our life with C
- Therefore, I will not do more challenges at this time, but advise you to experiement on your own! 
