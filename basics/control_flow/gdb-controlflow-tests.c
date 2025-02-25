/* How to "hack" this program!
- Compile with debug flags
- Load into gdb

plastid-debian@plastid-linux:~/projects/cjourney/basics/control_flow$ gcc -g ./gdb-controlflow-tests.c -o gdb-control-flow-tests
plastid-debian@plastid-linux:~/projects/cjourney/basics/control_flow$ gdb ./gdb-control-flow-tests 

- set breakpoint at authenticate `break authenticate`
- Step through until $rax is set with 1
- set $rax=0
- continue
- prints HACKED!
- See 'challenges.md' # CHALLENGE 3 section for further details and output! 
*/

#include <stdio.h>

int checkpassword(){
    return 1;
}

int authenticate() {
    if (checkpassword() == 1) {
        printf("ACCESS DENIED!\n");
        return 1;
    }
    printf("\n\n\nHACKED!!!!!\n\n\n");
    return 0;
}


int main(){
    authenticate();
    return 0;
}
