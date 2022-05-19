// A program which calculates the sum of two integers
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int x, y; 
    int sum;
    
    printf("Please enter the number of students and tutors: "); 
    scanf("%d %d", &x, &y); 
    
    sum = x + y; 
    
    printf("%d + %d = %d\n", x, y, sum);

    return 0;
}


