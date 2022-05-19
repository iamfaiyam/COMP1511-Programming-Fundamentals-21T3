// A C program which reads an integer n from standard input, and
// prints an nxn pattern of asterisks and dashes in the shape of an "X"
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int size;
    int numbers; 
    int row = 0; 
    int column;
    
    printf("Enter size: "); 
    numbers = scanf("%d", &size); 
    
    if (numbers != 1) {
        return 1; 
    }
    
    if (size < 5 || size % 2 != 1) {
        printf("Error: size has to be odd and >=5.\n"); 
        return 1; 
    }
    
    while (row < size) {
        column = 0; 
        while (column < size) {
            if (row == column || row == size - (column + 1)) {
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

