#include <stdio.h>

struct str1
{
    char a;
    int b;
    double c;
};

struct str2
{
    double a;
    int b;
    char c;
};

int main(void) {

    struct str1 x;

    printf("Initial struct:\n");
    printf("Size of struct: %lu bytes\n", sizeof(x));
    printf("Address of a: %p\n", &x.a);
    printf("Address of b: %p\n", &x.b);
    printf("Address of c: %p\n\n", &x.c);


    struct str2 y;

    printf("Changed struct:\n");
    printf("Size of struct: %lu bytes\n", sizeof(y));
    printf("Address of a: %p\n", &y.a);
    printf("Address of b: %p\n", &y.b);
    printf("Address of c: %p\n\n", &y.c);

    return 0;
}