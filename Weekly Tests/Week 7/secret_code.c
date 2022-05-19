// A C program which allows the user to scan in messages decrypted with Tom's
// Secret Code, and then print them out (ending in a newline)
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {

    int character_one = getchar(); 
    int character_two = getchar(); 
    
    while (character_one != EOF && character_two != EOF) {
        if (character_one < character_two) putchar(character_one);
        
        else putchar(character_two); 
        
        character_one = getchar();
        character_two = getchar();
        
    }
    
    putchar('\n');
}
