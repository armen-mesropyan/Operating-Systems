#include <stdio.h>
#include <unistd.h>        
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        execl("/bin/grep", "grep", "main", "test.txt", NULL);
        perror("execl failed");
        return 1;
    } 
    else 
    {
        waitpid(pid, NULL, 0);
        printf("Parent process done\n");
    }

    return 0;
}