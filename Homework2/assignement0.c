#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    fork();
    fork();
    fork();

    printf("Process created: PID = %d, Parent PID = %d\n", getpid(), getppid());

    // Making processes alive to observe them in htop.
    while (1) {
        sleep(1);
    }

    return 0;
}
