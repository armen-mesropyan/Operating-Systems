#include <stdio.h>
#include <stdlib.h>

void function1(void)
{
    printf("Function 1 called\n");
}

void function2(void) {
    printf("Function 2 called\n");
}

int main() 
{
    atexit(function1);
    atexit(function2);

    printf("Main function running\n");

    printf("This line will not run if exit() is above this ilne\n");
    exit(0);
    return 0;
}
