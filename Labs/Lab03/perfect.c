// A C program which reads a positive integer n from standard input
// and prints all the factors of n, their sum and indicates 
// whether n is a perfect number. 
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int num;
    int sum = 0;
    int i = 1; 
    
    printf("Enter number: "); 
    scanf("%d", &num); 
    
    printf("The factors of %d are:\n", num); 
    
    while (i <= num) {
        if ((num % i) == 0) {
            printf("%d\n", i); 
            sum = sum + i;
        }  
        i = i + 1;
    }
    
    printf("Sum of factors = %d\n", sum);
    
    if (num == (sum - num)) {
        printf("%d is a perfect number\n", num); 
    } else {
        printf("%d is not a perfect number\n", num);
    }

    return 0;
}
