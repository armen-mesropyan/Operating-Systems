#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_students;
    float *grades;
    float highest;
    float lowest;

    printf("Number of students: ");
    scanf("%d", &num_students);


    grades = (float *)malloc(num_students * sizeof(float));
        if (grades == NULL) {
            printf("Malloc failed\n");
            return 1;
        }

    printf("Input grades for the students: ");
    for (int i = 0; i < num_students; i++)
    {
        printf("Grade for the student %d: ", i + 1);
        scanf("%f", &grades[i]);
    }

    highest = lowest = grades[0];

    for (int i = 0; i < num_students; i++)
    {
        if (grades[i] > highest)
        {
            highest = grades[i];
        }
        if (grades[i] < lowest)
        {
            lowest = grades[i];
        }
    }

    printf("\nHighest grade: %.2f\n", highest);
    printf("Lowest grade: %.2f\n", lowest);

    free(grades);

    return 0;

}
