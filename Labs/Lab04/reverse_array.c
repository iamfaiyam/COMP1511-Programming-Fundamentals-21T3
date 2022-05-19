// A C program which reads integers line by line, and when it reaches the end
// of inputs, prints those integers in reverse order, line by line
// by Faiyam Islam z5258151

#include <stdio.h>

#define NUMBERS 100

int main(void) {
    
    int i = 0;
    int scan = 0;
    int value;
    int numbers[NUMBERS];

    printf("Enter numbers forwards:\n");

    while (scanf("%d", &value) == 1) {
        numbers[i] = value;
        scan = 1;
        i++;
    }
    
    printf("Reversed:\n");

    while (i > 0 && scan) {
        i--;
        printf("%d\n", numbers[i]);
    }

    return 0;
}

