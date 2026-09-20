#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() 
{
    pid_t child1 = fork();

    if (child1 == 0) 
    {            
        exit(0);                
    }

    pid_t child2 = fork();
    
    if (child2 == 0) 
    {             
        exit(1);               
    }

    int status;
    pid_t pid;
    
    pid = waitpid(child1, &status, 0);
    
    if (WIFEXITED(status))
        printf("Child 1 (PID=%d) exited normally with code %d\n",
               pid, WEXITSTATUS(status));
    else
        printf("Child 1 (PID=%d) exited abnormally\n", pid);

    
    pid = waitpid(child2, &status, 0);
    
    if (WIFEXITED(status))
        printf("Child 2 (PID=%d) exited with code %d\n", pid , WEXITSTATUS(status));
    else
        printf("Child 2 (PID=%d) exited with error\n", pid);

    return 0;
}
