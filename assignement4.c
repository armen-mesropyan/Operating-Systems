#include <stdio.h>

int main()
{
    int var = 10;
    int *ptrvar = &var;
    int **ptrptrvar = &ptrvar;

    printf("Printed using pointer: %d\n", *ptrvar);
	printf("Printed using double pointer: %d", **ptrptrvar);

	return 0;
}

