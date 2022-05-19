// A C program which reads 3 integers and prints the middle integer
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int num1, num2, num3; 
    int temp; 
    
    printf("Enter integer: "); 
    if (scanf("%d", &num1) != 1) {
        return 1; 
    }
    
    printf("Enter integer: "); 
    
    if (scanf("%d", &num2) != 1) {
        return 1; 
    }
    
    printf("Enter integer: ");
    if (scanf("%d", &num3) != 1) {
        return 1; 
    }
    
    if (num1 > num2) {
        temp = num2; 
        num2 = num1; 
        num1 = temp;
    }
    
    if (num1 > num3) {
        temp = num3; 
        num3 = num1; 
        num1 = temp; 
    }
    
    if (num2 > num3) {
        temp = num3; 
        num3 = num2; 
        num2 = temp; 
    }
    
    printf("Middle: %d\n", num2);
    
    return 0;
}




