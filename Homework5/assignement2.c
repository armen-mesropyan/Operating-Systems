#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Input the array size: ");

    int num_elements;
    scanf("%d", &num_elements);

    int *arr;
    arr = (int *)calloc(num_elements, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Array values after calloc:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    printf("Enter the values of an array separated by spaces: ");
    for (int i = 0; i < num_elements; i++) {
        scanf("%d", &arr[i]);
    }
	int sum = 0;
    for(int i = 0; i < num_elements; i++)
	{
		sum = sum + arr[i];	
	}
	
	printf("\nThe average of an array is: %d", sum / num_elements);


    printf("\nArray values after user input:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
