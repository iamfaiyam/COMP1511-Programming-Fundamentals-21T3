// A C program which reads in a number and then draws that many 
// square boxes inside each other using asterisks
// by Faiyam Islam z5258151

#include <stdio.h>

int main(void) {
    int boxes; 
    int size; 
    int i = 1;
    
    printf("How many boxes: "); 
    scanf("%d", &boxes); 
    
    size = 3 + (boxes - 1) * 4;
    while (i <= size) {
        int j = 1; 
        int x = 0; 
        while (j <= size) {
            if (i * 2 < size) {
                if (j <= i || j >= size - i + 1) {
                    x = j % 2; 
                }
            } else {
                if (j >= i || j <= size - i + 1) {
                    x = j % 2; 
                }
            }
            if (x == 1) {
                printf("*");
            } else if (x == 0) {
                printf("-");
            }
            j++;
        }
        i++;
        printf("\n");
    }        
    return 0; 
}


