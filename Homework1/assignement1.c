#include <stdio.h>

int main()
{
    int val = 10;
    int *valptr = &val;

    printf("%p\n", &val);
    printf("%p", valptr);

    *valptr = 20;
    printf("%d", val);

    return 0;
}