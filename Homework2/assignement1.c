#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        execl("/bin/ls", "ls", NULL);
        perror("execl failed"); // only runs if execl fails
    } else {
        // Parent process: wait for child to finish
        wait(NULL);
        printf("Parent process done\n");
    }

    return 0;
}
