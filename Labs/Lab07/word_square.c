// A C program which prompts the user to enter a word, and afterwards, prints
// that word out n amount of times, where n is the length of the word
// by Faiyam Islam z5258151

#include <stdio.h> 

#define MAX_SIZE 1024

int main(void) {

    int character; 
    int counter = 0; 
    
    char arr[MAX_SIZE] = {};
    
    printf("Input word: "); 
    character = getchar(); 
    
    while (character != '\n') {
    
        arr[counter] = character; 
        counter++;
        character = getchar(); 
    }
    
    printf("\n");
    printf("Word square is:\n");
    int i = 0; 
    while (i < counter) {
        int j = 0; 
        while (j < counter) {
            putchar(arr[j]);
            j++;
        }
        printf("\n");
        i++;
    }
    
    return 0;
}
