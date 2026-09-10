# Pointers — Assignment Report

**Course:** Operating Systems
**Repository:** https://github.com/armen-mesropyan/Operating-Systems

## Assignment 1 — Basics of Pointers
**File:** 'assignement1.c'

'val' is a normal integer, and 'valptr' is storing the address of val. Printing '&val' and 'valptr with '%p' shows the same address, since a pointer's value literally is an address.


### Observations
- '&val' and 'valptr' print identically, confirming that a pointer is just a variable holding an address.
- Writing through '*valptr' and writing to 'val' directly are indistinguishable.


## Assignment 2 — Pointer Arithmetic
**File:** 'assignement2.c'

'array' is a 5-element 'int' array. The first loop reads and prints the original values. The second loop overwrites each element with 'i + 10' using the same pointer-arithmetic form. The array is then printed twice more: once via '*(array + i)' and once via 'array[i]', to demonstrate they access the same data.


### Observations
- '*(array + i)' and 'array[i]' produce identical output because 'array[i]' is defined by the C standard as shorthand for '*(array + i)'.
- Since both access forms point at the same underlying memory, changes made through one are immediately visible through the other.


## Assignment 3 — Pointers and Functions
**File:** 'assignement3.c'

C passes function arguments by value, so a 'swap(int a, int b)' that took plain integers would only swap local copies inside the function and have no effect on 'main()'. To get a real swap, 'swap(int *a, int *b)' instead receives the addresses of 'a' and 'b' from 'main()' (passed as `&a, &b`). 

### Observations
- The swap is permanent in 'main()''s memory, not a copy, because 'swap()' never received values, it received addresses pointing back into 'main()''s stack frame.

## Assignment 4 — Pointers to Pointers
**File:** 'assignement4.c'

'var' is a plain integer, 'ptrvar' is a pointer to 'var', and 'ptrptrvar' is a pointer to 'ptrvar'. '*ptrvar' dereferences once, reaching 'var''s value directly. '**ptrptrvar' dereferences twice: the first '*' follows 'ptrptrvar' to get 'ptrvar', and the second '*' follows that to get 'var''s value. Both expressions arrive at the same value through different numbers of indirection steps.


### Observations
- Both prints show '10', confirming the indirection chain 'ptrptrvar → ptrvar → var' correctly resolves back to the original value regardless of how many levels of pointer are used.
- Double pointers become necessary when a function needs to modify a pointer itself.


## Assignment 5 — Strings and Character Pointers
**File:** 'assignement5.c'

'str' is a character array holding '"Hello"', which the compiler automatically null-terminates (`'H','e','l','l','o','\0'`). 'ptr' is set to point at the first character. The first 'while' loop prints characters one at a time by dereferencing 'ptr' and incrementing it ('ptr++'), stopping when it hits the null terminator ''\0''.


### Observations
- The loop correctly resets 'ptr = str;' before the counting pass.
- '*(ptr + count) != '\0'' is a slightly different but equally valid style compared to incrementing 'ptr' itself



## How to Build and Run
```bash
gcc -Wall -Wextra -o assignement1 assignement1.c && ./assignement1
gcc -Wall -Wextra -o assignement2 assignement2.c && ./assignement2
gcc -Wall -Wextra -o assignement3 assignement3.c && ./assignement3
gcc -Wall -Wextra -o assignement4 assignement4.c && ./assignement4
gcc -Wall -Wextra -o assignement5 assignement5.c && ./assignement5
```
