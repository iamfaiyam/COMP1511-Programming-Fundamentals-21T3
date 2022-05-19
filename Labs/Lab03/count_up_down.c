// A C program which reads one integer n and prints
// all integers from 0 to n inclusive one per line
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int number; 
    int i = 0; 
   
    printf("Enter number: ");
    scanf("%d", &number);
   
    if (number > 0) {
        while (i <= number) {
            printf("%d\n", i);
            i = i + 1;
        }
    
    } else {
        while (i >= number) {
            printf("%d\n", i); 
            i = i - 1; 
        }
    }
   

    return 0;
}
