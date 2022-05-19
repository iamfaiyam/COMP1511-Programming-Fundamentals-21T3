// A C program which reads characters from its input and write the same
// characters to its output, except it does not write lower case vowels
// by Faiyam Islam z5258151

#include <stdio.h> 

int devowel(int character); 

int main(void) {

    int character = getchar(); 
    while (character != EOF) {
        
        if (!devowel(character)) {
            putchar(character);
        }
        
        character = getchar(); 
    }
    
    return 0; 
}

// Function which will leave out all the vowels 

int devowel(int character) {
    
    return character == 'a' || 
           character == 'e' || 
           character == 'i' ||
           character == 'o' ||
           character == 'u';
}


