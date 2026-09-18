# Homework 2

Git Repository: https://github.com/armen-mesropyan/Operating-Systems/tree/main/Homework2 

This folder contains 5 programs exploring process creation with `fork()`
and program replacement with `execl()`.

## Files

| File | Description |

`assignement0.c` - Calls `fork()` three times in sequence, creating up to 8 processes total. Each process prints its own PID and parent PID, then loops forever (`while(1) sleep(1)`) so the processes can be observed live in `htop`/`ps`. 
`assignement1.c` - Forks once; the child replaces itself with `ls` via `execl`. Parent waits, then prints "Parent process done". 
`assignement2.c` - Forks twice sequentially; first child execs `ls`, second child execs `date`. Parent waits for each in turn. 
`assignement3.c` - Forks once; child execs `echo "Hello from the child process"`. 
`assignement4.c` - Forks once; child execs `grep main test.txt`, printing every line containing "main". 
`test.txt` - Sample text file used by Assignment 4's grep search. 

## How to build and run

From inside this folder:

```bash
gcc -Wall -o prog0 assignement0.c
gcc -Wall -o prog1 assignement1.c
gcc -Wall -o prog2 assignement2.c
gcc -Wall -o prog3 assignement3.c
gcc -Wall -o prog4 assignement4.c
```

Run each one individually:

```bash
./prog1
./prog2
./prog3
./prog4
```

### Important: Assignment 0 runs forever

## Expected output summary

- **Assignment 0**: several lines like `Process created: PID=... Parent PID=...` (order varies each run since it depends on OS scheduling), then the program hangs until killed.
- **Assignment 1**: directory listing, then `Parent process done`.
- **Assignment 2**: `ls` output, then `date` output, then `Parent process done`.
- **Assignment 3**: `Hello from the child process`, then `Parent process done`.
- **Assignment 4**: lines from `test.txt` containing "main" (lines 1, 2, 4, 6, 8, 9), then `Parent process done`.