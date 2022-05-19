// A C program which reads command line arguments then prints them out 
// When it prints out, it will convert all upper case letters to lower case
// by Faiyam Islam z5258151

#include <stdio.h>
#include <ctype.h>

void print_lower_word(char *word);

int main(int argc, char *argv[]) {
    int i = 1;
    while (i < argc) {
        print_lower_word(argv[i]);
        putchar(' ');
        i++;
    }
    putchar('\n');
}

void print_lower_word(char *word) {
    int i = 0;
    while (word[i] != '\0') {
        putchar(tolower(word[i]));
        i++;
    }
}


