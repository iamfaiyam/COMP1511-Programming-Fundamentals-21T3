// A C program which reads characters from its inputs and write the characters
// to its output encrypted with a Substituion cipher
// by Faiyam Islam z5258151

#include <stdio.h> 
#include <string.h> 

#define NUM_ALPHABET 26

int encrypt(int character, char mapping[NUM_ALPHABET]);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Usage: %s <mapping>\n", argv[0]); 
        return 1;
    }
    
    if (strlen(argv[1]) != NUM_ALPHABET) {
        printf("%s: mapping must contain %d letters\n", argv[0], NUM_ALPHABET);
        return 1; 
    }

    int character = getchar();
    while (character != EOF) {
        int encrypted_character = encrypt(character, argv[1]);
        putchar(encrypted_character);
        character = getchar(); 
    }
    
    return 0;
}

int encrypt(int character, char mapping[NUM_ALPHABET]) {
    
    if (character >= 'A' && character <= 'Z') {
        return mapping[character - 'A'] - 'a' + 'A';
    } else if (character >= 'a' && character <= 'z') {
        return mapping[character - 'a'];
    } else {
        return character; 
    }
}
