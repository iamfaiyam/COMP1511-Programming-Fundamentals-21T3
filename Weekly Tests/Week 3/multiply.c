// A C program which reads 2 integers and prints their absolute multiple
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int number1;
    int number2; 
    
    scanf("%d", &number1); 
    scanf("%d", &number2); 
    
    if (number1 * number2 == 0) {
        printf("zero\n");
    } else if (number1 * number2 > 0) {
        printf("%d\n", number1 * number2);
    } else {
        printf("%d\n", number1 * number2 * -1);
    }
    
    return 0; 
}
