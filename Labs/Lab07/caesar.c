// A C program which reads characters from its input and write the characters
// to its output encrypted with a Caesar cipher
// by Faiyam Islam z5258151

#include <stdio.h> 
#include <stdlib.h>

#define ALPHABET_SIZE 26

int encrypt(int character, int change); 

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <shift>\n", argv[0]);
        return 1;
    }

    int change = atoi(argv[1]);
    
    if (change < 0) {
        change = ALPHABET_SIZE + (change % ALPHABET_SIZE); 
    }
    
    int character = getchar(); 
    while (character != EOF) {
        int encrypted_char = encrypt(character, change); 
        putchar(encrypted_char);
        character = getchar();
    }
    
    return 0;
}

int encrypt(int character, int change) {
    if (character >= 'A' && character <= 'Z') {
        return 'A' + (character - 'A' + change) % ALPHABET_SIZE; 
    } else if (character >= 'a' && character <= 'z') {
        return 'a' + (character - 'a' + change) % ALPHABET_SIZE;
    } else {
        return character;
    }
}


