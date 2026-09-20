**Student - Armen Mesropyan**
# Homework 3 — Processes

**GitHub repository:** https://github.com/armen-mesropyan/Operating-Systems

This report covers five programs exploring process creation and management on Linux using `fork()`, `wait()`, `waitpid()`, `atexit()`, and observing zombie processes. Source code for each assignment is in this folder (`assignment1.c` – `assignment5.c`).


## Assignment 1:

### How it works
`fork()` creates a new process by duplicating the calling process. It is called once but returns twice, once in each process:
- In the **child**, `fork()` returns `0`.
- In the **parent**, `fork()` returns the child's PID, which is positive number.
- If process creation fails, it returns a negative value.

After the fork, both processes run the same code independently, each with its own copy of memory, so the branching logic splits execution: the child takes the "PID is 0" branch and prints its own PID via `getpid()`, while the parent takes the other branch and prints its own PID.
- The parent does not call `wait()`, so it doesn't pause for the child. This means the two printed lines can appear in either order depending on which process the OS scheduler runs first.
- Running the program multiple times can show different orderings of "Parent PID" and "Child PID" in the output. This demonstrates that `fork()` does not guarantee execution order between parent and child.


## Assignment 2:

### How it works
The parent calls `fork()` twice, creating two children:
- **Child 1** is created first. It immediately prints and exits, so it never reaches the second `fork()` call.
- **Child 2** is created by the parent's second `fork()` call. It also prints and exits.
- The **parent** survives both forks and calls:
  - `waitpid()` targeting the second child's PID specifically and waits for **Child 2** to finish.
  - `wait(NULL)` — waits for any remaining child.

- `waitpid()` lets you target a specific child process by PID, whereas `wait()` blocks until any child terminates, useful when you have multiple children and only care about one finishing first.
- Using `NULL` for the status pointer means we don't inspect how the children exited, just that they did.


## Assignment 3:

### How it works
`atexit()` registers a function to be automatically called when the program terminates normally. Multiple functions can be registered, and they are called in **LIFO** order, the most recently registered function runs first.

In this program, `function1` is registered first and `function2` second, so at program termination the call order is reversed: `function2` runs before `function1`.

The final `printf` before `exit(0)` still runs, since it appears *before* the call to `exit()` in the source; only code placed after `exit(0)` is skipped, because `exit()` terminates the process immediately and never returns control back to `main`.

- `atexit()` handlers run in reverse order of registration (LIFO), similar to a stack.


## Assignment 4:

### How it works
The parent creates two children with distinct exit codes:
- **Child 1** exits with code `0` (conventionally means success).
- **Child 2** exits with code `1` (conventionally means a general error).

The parent calls `waitpid()` twice, once per child PID, storing each child's termination information in a `status` variable. Two macros interpret that status:
- `WIFEXITED(status)` — true if the child terminated normally, as opposed to being killed by a signal.
- `WEXITSTATUS(status)` — extracts the actual exit code (0–255) that the child passed to `exit()`.

- Exit codes are a simple way for a child process to communicate a result back to its parent by convention, `0` means success and any nonzero value indicates a specific type of failure.


## Assignment 5:

- A **zombie process** is a process that has finished execution but still has an entry in the process table because its exit status hasn't been read by the parent via `wait()`/`waitpid()`.
- Zombies consume a process table slot but no CPU or memory resources, however, having many of them can exhaust the maximum number of processes a system allows.
- Calling `wait()` (or `waitpid()`) is what tells the kernel "the parent has acknowledged this child's termination," allowing the kernel to fully remove the process table entry.
