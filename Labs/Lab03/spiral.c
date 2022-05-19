// A C program which reads an integer n from standard input
// and prints an nxn pattern of asterisks and dashes in the shape of a spiral.
// by Faiyam Islam z5258151

#include <stdio.h> 
#include <stdlib.h> 

int main(void) {
    int number; 
    
    printf("Enter size: "); 
    if (!scanf("%d", &number) || number % 2 == 0) {
        return 1; 
    }
    
    int row = 0; 
    int column = 0; 
    
    while (row < number) {
        column = 0; 
        
        while (column < number) {
            if (row <= number/2 && row % 2 == 0 && column >= row - 1
             && column <= number - row - 1) {
                printf("*");
            } else if (row > number/2 && row % 2 == 0 && column <= row 
            && column >= number - row - 1) {
                printf("*");
            } else if (column <= number/2 && column % 2 == 0 
            && row >= column + 2 && row < number - column - 1) {
                printf("*");
            } else if (column > number/2 && column % 2 == 0 
            && row <= column && row >= number - column) {
                printf("*");
            } else {
                printf("-");
            }
            column = column + 1; 
        }
        printf("\n");
        row = row + 1; 
    }
       
    return 0;
}
