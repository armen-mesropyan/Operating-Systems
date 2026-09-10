#include <stdio.h>

int main()
{
	char str[] = "Hello";
	char *ptr = str;

	while(*ptr != '\0')
	{
		printf("%c", *ptr);
		ptr++;
		
	}

	int count = 0;
	ptr = str;

	while(*(ptr + count) != '\0')
	{
		count++;
	}

	printf("\nNumber of characters in string: %d", count);
		
	return 0;
}