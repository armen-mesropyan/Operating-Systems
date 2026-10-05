#include <stdio.h>
#include <stdlib.h>

int main() {
    int initial_size = 3;
    int new_size = 5;
    char **strings;

    strings = (char **)malloc(initial_size * sizeof(char *));
    if (strings == NULL) {
        printf("Memory allocation for string pointers failed\n");
        return 1;
    }

    printf("Enter three strings (each up to 50 characters)\n");

    for (int i = 0; i < initial_size; i++) {
        strings[i] = (char *)malloc(50 * sizeof(char));
        if (strings[i] == NULL) {
            printf("Memory allocation failed\n");
            for (int j = 0; j < i; j++)
                free(strings[j]);
            free(strings);
            return 1;
        }
        scanf("%50s", strings[i]);
    }
    printf("\nInputted strings: ");
    for (int i = 0; i < initial_size; i++) {
        printf("%s ", strings[i]);
    }

    printf("\n");
    char **temp = (char **)realloc(strings, new_size * sizeof(char *));

    if (temp == NULL) {
        printf("realloc failed\n");
        for (int i = 0; i < initial_size; i++)
            free(strings[i]);
        free(strings);
        return 1;
    }
    strings = temp;

    printf("\nEnter 2 more strings (each up to 50 characters):\n");
    for (int i = initial_size; i < new_size; i++) {
        strings[i] = (char *)malloc(50 * sizeof(char));
        if (strings[i] == NULL) {
            printf("Memory allocation failed!\n");
            for (int j = 0; j < i; j++)
                free(strings[j]);
            free(strings);
            return 1;
        }
        scanf("%50s", strings[i]);
    }


    printf("\nAll strings after resizing: ");
    for (int i = 0; i < new_size; i++) {
        printf("%s ", strings[i]);
    }

    for (int i = 0; i < new_size; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}
