#include <stdio.h>

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	
	printf("Initial array: ");
		
	for(int i = 0; i < 5; i++)
        {
                printf("%d ", *(array + i));
        }

	for(int i = 0; i < 5; i++)
        {
                *(array + i) = i + 10;
        }
	
	printf("\nModified array printing using pointer: ");

	for(int i = 0; i < 5; i++)
	{
	        printf("%d ", *(array + i));
	}

	printf("\nModified array printing using array name: ");
	
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", array[i]);
	}
		
	return 0;
}
	