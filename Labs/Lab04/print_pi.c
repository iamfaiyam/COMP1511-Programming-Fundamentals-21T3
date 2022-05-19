// A  C program which prints out the frist n digits of pi
// where n is specified by the user 
// by Faiyam Islam z5258151

#include <stdio.h> 

#define DIGITS 10

int main(void) {
    int pi[DIGITS] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    int i = 0;  
    int digits; 
       
    printf("How many digits of pi would you like to print? "); 
    scanf("%d", &digits);
    while (i < digits) {
        if (i == 1) {
            printf("."); 
        }
        printf("%d", pi[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}


