# DOUBLE FREE 
## WHAT'S A DOUBLE FREE? 

- A double `free()` happens when you free the same memory twice. 
- This corrupts the heap's internal data structures, and under the right conditions, 
you can control them. 

## WHY IS IT DANGEROUS? 

- It can cause heap metadata corruption
- This leads to memory leaks, crashes, or even arbitrary code execution 
- On systems using ptmalloc (glibc default) it can let you: 
    - Overwrite function pointers 
    - Forge heap chunks
    - Redirect `malloc()` calls to attacker-controlled memory 

## REAL WORLD DOUBLE FREE EXPLOITS 

- [CVE-2017-6074](https://nvd.nist.gov/vuln/detail/CVE-2017-6074) - Linux kernel double free -> root priv escalation 
- [CVE-2020-25212](https://nvd.nist.gov/vuln/detail/cve-2020-25212) - GNOME GLib -> UAF double-free
- [CVE-2021-3156](https://nvd.nist.gov/vuln/detail/cve-2021-3156) - sudo off-by-one error -> heap overflow -> root priv escalation

**These bugs are often chained with UAF or heap spraying to gain shells**

## Challenge Code

- Write a simple C program that:

    - Allocates memory
    - Frees it
    - Frees it again (accidentally or deliberately)
    - Observe crash or Valgrind report


