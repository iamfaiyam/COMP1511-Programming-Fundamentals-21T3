// A C program which reads 3 integers and prints out an instruction 
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int x; 
    int y; 
    int num; 
    int sum; 
    int difference; 
    
    printf("Enter instruction: "); 
    scanf("%d %d %d", &x, &y, &num); 
    
    if (x == 1) {
        sum = y + num; 
        printf("%d\n", sum);
    } else if (x == 2) {
        difference = y - num;
        printf("%d\n", difference);
    }

    return 0; 
}


