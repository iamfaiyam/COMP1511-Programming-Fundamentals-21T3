// A C program which reads a line from its input then reads an integer n from 
// its input
// by Faiyam Islam z5258151

#include <stdio.h> 
#include <assert.h> 

#define MAX_CHARACTERS 256

int main(void) {

    char character[MAX_CHARACTERS] = {0};
    
    fgets(character, MAX_CHARACTERS, stdin); 
    
    int j = 0; 
    scanf("%d", &j); 
    
    assert(j >= 0 && j < MAX_CHARACTERS); 
    printf("The character in position %d is '%c'\n", j, character[j]); 
    
    return 0; 

}
