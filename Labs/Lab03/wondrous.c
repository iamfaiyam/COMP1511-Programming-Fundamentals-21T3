// A C program which reads an integer n from standard input, and
// prints the wondrous numbers of it as a graph of asterisks
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int n;
    int i;  
    
    printf("What number would you like to see: "); 
    scanf("%d", &n); 
    
    while (n > 1) {
        i = 0; 
        while (i < n) {
            printf("*");  // need to print out asterisk before 
            i = i + 1;
        }
        printf("\n");
        if (n % 2 == 0) {
            n = n / 2; 
            
        } else {
            n = n * 3 + 1; 
            
        }
        
    }
 
    return 0;
}


