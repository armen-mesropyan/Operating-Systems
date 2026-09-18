#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork1 failed");
        return 1;
    }
    if (pid1 == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("execl failed: ls");
        return 1;
    }

    waitpid(pid1, NULL, 0);
    
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork2 failed");
        return 1;
    }
    if (pid2 == 0) {
        execl("/bin/date", "date", NULL);
        perror("execl failed: date");
        return 1;
    }
    
    waitpid(pid2, NULL, 0);

    printf("Parent process done\n");

    return 0;
}