#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
		int a = 10;
		int b = 20;

		printf("Varialbes before swapping: a: %d b: %d\n", a, b);
		swap(&a, &b);
		printf("Varialbes after swapping: a: %d b: %d", a, b);

		return 0;
}