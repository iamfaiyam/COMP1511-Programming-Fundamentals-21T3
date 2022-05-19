// A C program which reads an integer n from standard input, and
// then scans in n integers from standard input, adds them together,
// then prints the sum 
// by Faiyam Islam z5258151

#include <stdio.h>
#include <stdlib.h>

int number(void);

int main(void) {
    printf("How many numbers: ");
    int total = number();

    int sum = 0;
    int i = 0;
    while (i < total) {
        sum += number();
        i++;
    }

    printf("The sum is: %d\n", sum);

    return 0;
}

int number(void) {
    int x; 
    if (scanf("%d", &x) != 1) {
        printf("Could not read a number\n");
        exit(EXIT_FAILURE);
    }
    return x;
}


