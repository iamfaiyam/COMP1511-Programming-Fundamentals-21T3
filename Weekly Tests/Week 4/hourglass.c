// A C program which prompts the user to enter an integer n
// and prints an nxn pattern containing an hourglass
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void){

    int number; 
    int row; 
    int column;

    printf("Please enter a size:");
    scanf("%d", &number);

    row = 1;
    while(row <= number) {
        column = 1; 
        while (column <= number) {

            if ((row <= column && row + column - 1 <= number) ||
                (row >= column && row + column - 1 >= number)) {
                printf("*");
            } else {
                printf("-");
            }
        column++;
        }
        printf("\n");
        row++;
    }

    return 0;

}
