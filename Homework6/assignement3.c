#include <stdio.h>

struct structure
{
    char a;
    int b;
    double c;
};

#pragma pack(1)
struct structure2
{
    char a;
    int b;
    double c;
};

int main()
{
    struct structure x;

    printf("Initial struct:\n");
    printf("Size of struct: %lu bytes\n", sizeof(x));
    printf("Address of a: %p\n", &x.a);
    printf("Address of b: %p\n", &x.b);
    printf("Address of c: %p\n\n", &x.c);


    struct structure2 y;

    printf("Afer pragma (1) struct:\n");
    printf("Size of struct: %lu bytes\n", sizeof(y));
    printf("Address of a: %p\n", &y.a);
    printf("Address of b: %p\n", &y.b);
    printf("Address of c: %p\n\n", &y.c);
}