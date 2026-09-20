#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) 
    {
        printf("Child process (PID=%d)\n", getpid());
        exit(0);
        
    }
    
    else
    {
        wait(NULL);
        printf("Parent (PID=%d), child (PID=%d)\n", getpid(), child_pid);
        sleep(10);
    }

    return 0;
}

