// A C program which decrypts text that's encrypted by substitution.c
// by Faiyam Islam z5258151

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define ALPHABET_SIZE 26

void decode(char mapping[ALPHABET_SIZE], 
char inverse_mapping[ALPHABET_SIZE]);
int decrypt(int character, char  inverse_mapping[ALPHABET_SIZE]);

int main(int argc, char *argv[]) {
    char inverse_mapping[ALPHABET_SIZE] = {0};

    if (argc != 2) {
        printf("Usage: %s <mapping>\n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) != ALPHABET_SIZE) {
        printf("%s: mapping must contain %d letters\n", argv[0], ALPHABET_SIZE);
        return 1;
    }

    decode(argv[1], inverse_mapping);

    int character = getchar();
    while (character != EOF) {
        int decrypted_character = decrypt(character, inverse_mapping);
        putchar(decrypted_character);
        character = getchar();
    }

    return 0;
}

void decode(char mapping[ALPHABET_SIZE], 
char inverse_mapping[ALPHABET_SIZE]) {
    int i = 0;
    while (i < ALPHABET_SIZE) {
        int character = mapping[i];
        assert(character >= 'a' && character <= 'z');
        inverse_mapping[character - 'a'] = 'a' + i;
        i = i + 1;
    }
}

int decrypt(int character, char inverse_mapping[ALPHABET_SIZE]) {
    if (character >= 'A' && character <= 'Z') {
        return inverse_mapping[character - 'A'] - 'a' + 'A';
    } else if (character >= 'a' && character <= 'z') {
        return inverse_mapping[character - 'a'];
    } else {
        return character;
    }
}

