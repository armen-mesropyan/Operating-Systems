#include <stdio.h>

int main(void) {

    int integer_var;
    char char_var;
    double double_var;
    short short_var;

    printf("size of integer: %ld\n",sizeof(integer_var));
    printf("size of character: %ld\n",sizeof(char_var));
    printf("size of double: %ld\n",sizeof(double_var));
    printf("size of short: %ld\n\n",sizeof(short_var));

    printf("address of integer: %p\n", &(integer_var));
    printf("address of character: %p\n", &(char_var));
    printf("address of double: %p\n", &(double_var));
    printf("address of short: %p\n", &(short_var));


    return 0;
}