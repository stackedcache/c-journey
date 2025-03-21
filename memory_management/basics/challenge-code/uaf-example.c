#include <stdio.h>
#include <stdlib.h> 

/* Challenge Code

Write a program that:

    Allocates a block with malloc()
    Fills it with some data (e.g., a string)
    Frees the block
    Prints or accesses the pointer after it’s freed
    Observe output or crash with Valgrind
*/

int main() {
    char *arr = (char *)malloc(10 * sizeof(char));
    if (!arr) {
        printf("MALLOC FAILED!");
        return 1;
    }

    snprintf(arr, 10, "%s", "HELLO!");
    
    // Test printing the string  
    printf("%s\n", arr);
    
    free(arr);

    printf("String after free: %s\n", arr);

    return 0;
}

/* LEARNING NOTES: 


    shell $ valgrind --leak-check=full --track-origins=yes ./uaf-example 

    ==52331== Memcheck, a memory error detector
    ==52331== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
    ==52331== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
    ==52331== Command: ./uaf-example
    ==52331== 
    HELLO!
    ==52331== Invalid read of size 1
    ==52331==    at 0x4846782: strlen (vg_replace_strmem.c:494)
    ==52331==    by 0x48C1257: __vfprintf_internal (vfprintf-process-arg.c:397)
    ==52331==    by 0x48B565A: printf (printf.c:33)
    ==52331==    by 0x10920A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Address 0x4a47040 is 0 bytes inside a block of size 10 free'd
    ==52331==    at 0x484317B: free (vg_replace_malloc.c:872)
    ==52331==    by 0x1091EF: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Block was alloc'd at
    ==52331==    at 0x48407B4: malloc (vg_replace_malloc.c:381)
    ==52331==    by 0x10918A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331== 
    ==52331== Invalid read of size 1
    ==52331==    at 0x4846794: strlen (vg_replace_strmem.c:494)
    ==52331==    by 0x48C1257: __vfprintf_internal (vfprintf-process-arg.c:397)
    ==52331==    by 0x48B565A: printf (printf.c:33)
    ==52331==    by 0x10920A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Address 0x4a47041 is 1 bytes inside a block of size 10 free'd
    ==52331==    at 0x484317B: free (vg_replace_malloc.c:872)
    ==52331==    by 0x1091EF: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Block was alloc'd at
    ==52331==    at 0x48407B4: malloc (vg_replace_malloc.c:381)
    ==52331==    by 0x10918A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331== 
    ==52331== Invalid read of size 1
    ==52331==    at 0x48E45C9: _IO_new_file_xsputn (fileops.c:1218)
    ==52331==    by 0x48E45C9: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
    ==52331==    by 0x48C10FE: outstring_func (vfprintf-internal.c:239)
    ==52331==    by 0x48C10FE: __vfprintf_internal (vfprintf-process-arg.c:421)
    ==52331==    by 0x48B565A: printf (printf.c:33)
    ==52331==    by 0x10920A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Address 0x4a47045 is 5 bytes inside a block of size 10 free'd
    ==52331==    at 0x484317B: free (vg_replace_malloc.c:872)
    ==52331==    by 0x1091EF: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Block was alloc'd at
    ==52331==    at 0x48407B4: malloc (vg_replace_malloc.c:381)
    ==52331==    by 0x10918A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331== 
    ==52331== Invalid read of size 1
    ==52331==    at 0x484AE30: mempcpy (vg_replace_strmem.c:1668)
    ==52331==    by 0x48E458B: _IO_new_file_xsputn (fileops.c:1235)
    ==52331==    by 0x48E458B: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
    ==52331==    by 0x48C10FE: outstring_func (vfprintf-internal.c:239)
    ==52331==    by 0x48C10FE: __vfprintf_internal (vfprintf-process-arg.c:421)
    ==52331==    by 0x48B565A: printf (printf.c:33)
    ==52331==    by 0x10920A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Address 0x4a47045 is 5 bytes inside a block of size 10 free'd
    ==52331==    at 0x484317B: free (vg_replace_malloc.c:872)
    ==52331==    by 0x1091EF: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Block was alloc'd at
    ==52331==    at 0x48407B4: malloc (vg_replace_malloc.c:381)
    ==52331==    by 0x10918A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331== 
    ==52331== Invalid read of size 1
    ==52331==    at 0x484AE3D: mempcpy (vg_replace_strmem.c:1668)
    ==52331==    by 0x48E458B: _IO_new_file_xsputn (fileops.c:1235)
    ==52331==    by 0x48E458B: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1196)
    ==52331==    by 0x48C10FE: outstring_func (vfprintf-internal.c:239)
    ==52331==    by 0x48C10FE: __vfprintf_internal (vfprintf-process-arg.c:421)
    ==52331==    by 0x48B565A: printf (printf.c:33)
    ==52331==    by 0x10920A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Address 0x4a47043 is 3 bytes inside a block of size 10 free'd
    ==52331==    at 0x484317B: free (vg_replace_malloc.c:872)
    ==52331==    by 0x1091EF: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331==  Block was alloc'd at
    ==52331==    at 0x48407B4: malloc (vg_replace_malloc.c:381)
    ==52331==    by 0x10918A: main (in /home/plastid-debian/projects/cjourney/memory_management/basics/challenge-code/uaf-example)
    ==52331== 
    String after free: HELLO!
    ==52331== 
    ==52331== HEAP SUMMARY:
    ==52331==     in use at exit: 0 bytes in 0 blocks
    ==52331==   total heap usage: 2 allocs, 2 frees, 1,034 bytes allocated
    ==52331== 
    ==52331== All heap blocks were freed -- no leaks are possible
    ==52331== 
    ==52331== For lists of detected and suppressed errors, rerun with: -s
    ==52331== ERROR SUMMARY: 19 errors from 5 contexts (suppressed: 0 from 0)


    - ==52331==  Address 0x4a47040 is 0 bytes inside a block of size 10 free'd

        - This tells us that we are using memory after free
        - In the real world this can lead to data leaks or execution flow exploitation.
.*
