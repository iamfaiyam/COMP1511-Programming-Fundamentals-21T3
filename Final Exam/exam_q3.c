// A C program which reads integers from standard input
// input until it reads the value 0 
// by Faiyam Islam z5258151

#include <stdio.h>
#include <stdlib.h>

#define TOTAL 1000

int main(void) {

    int number; 
    int total_values = 0; 
    
    int num[TOTAL] = {};
    
    number = 0;
    
    // Scan 1 value from the array, make sure it isn't 0 and less than 1000
    while (((scanf("%d", &num[number]) == 1)) && 
    (num[number] != 0) && (number < TOTAL)) {
    
        total_values = total_values + 1;
    
        number = number + 1; 
    }
    
    printf("First Half:"); 

    number = 0;
    int individual_values = (total_values + 1) / 2;     
    while (number < individual_values) {

        printf(" %d", num[number]);
        number = number + 1;  
    }
    
    printf("\n"); 
    
// your code here! 

    return 0; 
}


