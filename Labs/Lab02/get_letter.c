// A C program which reads in a character and an integer and prints 
// the letters, given their numbers
// by Faiyam Islam z5258151

#include <stdio.h> 
int main(void) {
    char character; 
    int number; 
    char character_one; 
    char character_two; 
    
    printf("Uppercase: "); 
    scanf("%c", &character); 
    
    if ((character != 'y') && (character != 'n')) {
        printf("You need to enter 'y' or 'n'\n"); 
        printf("Exiting the program with error code 1\n");
        
        return 1;
    }
    
    printf("Index: "); 
    scanf("%d", &number); 
    
    if ((character == 'y') && ((number >= 1) && (number <= 26))) {
        character_one = number + 64; 
        printf("The letter is %c\n", character_one); 
    } else if ((character == 'n') && ((number >= 1) && (number <= 26))) {
        character_two = number + 96; 
        printf("The letter is %c\n", character_two); 
    } else if ((character != 'y') && (character != 'n')) {
        printf("You need to enter 'y' or 'n'\n"); 
        printf("Exiting the program with error code 1\n"); 
    } else {
        printf("You need to enter a number between 1 and 26 inclusive\n");
        printf("Exiting the program with error code 2\n");
    }
    return 0;
}















