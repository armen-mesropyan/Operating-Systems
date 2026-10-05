#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *arr;
    int size = 10;
    int new_size = 5;

    arr = (int *)malloc(size * sizeof(int));


    if (arr == NULL)
    {
        printf("Initial memory allocation failed!\n");
        return 1;
    }

    printf("Enter the values of an array separated by spaces: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *new_arr = (int *)realloc(arr, new_size * sizeof(int));


    if (new_arr == NULL)
    {
        printf("Memory reallocation failed!\n");
        free(arr);
        return 1;
    }

    printf("Elements after resizing: ");
    
    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", new_arr[i]);
    }

    free(new_arr);

    return 0;
}
