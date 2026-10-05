#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    printf("Enter %d numbers separated by spaces: ", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray contents:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    int array_sum = 0;

    for(int i = 0; i < n; i++)
    {
   
       array_sum = array_sum + arr[i];
    }

    printf("\nSum of elements of an array: %d\n", array_sum);
    
    free(arr);
    return 0;
}