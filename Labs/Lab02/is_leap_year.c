// A C program which tests if a year is a leap year or not
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int year;
    
    printf("Enter year: "); 
    if (scanf("%d", &year) != 1) {
        return 1; 
    }
    
    if (year % 4 != 0) {
        printf("%d is not a leap year.\n", year);
    } else if (year % 100 != 0) {
        printf("%d is a leap year.\n", year); 
    } else if (year % 400 != 0) {
        printf("%d is not a leap year.\n", year); 
    } else {
        printf("%d is a leap year.\n", year); 
    }
    
    return 0; 
}


