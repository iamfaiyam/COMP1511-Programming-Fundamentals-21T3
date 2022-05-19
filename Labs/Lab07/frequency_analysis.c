// A C program which reads characters from its input until end of input.
// It should then print the occurrence frequency of the 26 letters 'a'..'z'.
// by Faiyam Islam z5258151

#include <stdio.h>

#define NOT_A_LETTER (-1)
#define ALPHABET_SIZE  26

int get_letter_frequencies(int letter_count[ALPHABET_SIZE]);
int letter_index(int character);
void print_frequencies(int letter_count[ALPHABET_SIZE], int n_letters_read);

int main(int argc, char *argv[]) {
    int letter_count[ALPHABET_SIZE] = {0};  

    int n_letters_read = get_letter_frequencies(letter_count);
    print_frequencies(letter_count, n_letters_read);
    return 0;
}

int get_letter_frequencies(int letter_count[ALPHABET_SIZE]) {
    int character = getchar();
    int n_letters_read = 0;
    while (character != EOF) {
        int index =  letter_index(character);
        if (index != NOT_A_LETTER) {
            letter_count[index] = letter_count[index] + 1;
            n_letters_read = n_letters_read + 1;
        }
        character = getchar();
    }
    return n_letters_read;
}


int letter_index(int character) {
    if (character >= 'A' && character <= 'Z') {
        return character - 'A';
    } else if (character >= 'a' && character <= 'z') {
        return character - 'a';
    } else {
        return NOT_A_LETTER;
    }
}

void print_frequencies(int letter_count[ALPHABET_SIZE], int n_letters_read) {
    if (n_letters_read == 0) {
        return;
    }
    int i = 0;
    while (i < ALPHABET_SIZE) {
        printf("'%c' %lf %d\n", 'a' + i, letter_count[i]/(double) 
        n_letters_read, letter_count[i]);
        i = i + 1;
    }
}

