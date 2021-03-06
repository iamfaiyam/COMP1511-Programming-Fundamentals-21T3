// A C program which checks for character matches between 
// the string from standard input and multiple strings from the 
// command line. 
// by Faiyam Islam z5258151

#include <stdio.h>
#include <string.h>

#define SIZE 1024
                         
int main(int argc , char *argv[]) {
    
    int word[SIZE] = {0};
    int char_length = 0;
    int character;
    
    while (((character = getchar()) != -1)) {
    
        word[char_length] = character; 
        
        char_length = char_length + 1; 
    }
    
    int index_one = 1; 
    while (index_one < argc) {

        int index_two = 0;
        while (index_two < char_length) {
            if (argv[index_one][index_two] == word[index_two]) {
            
                printf("%d %s\n", index_two, argv[index_one]); 
                
                index_two = char_length;   
            }
            index_two = index_two + 1; 
            
        }
        index_one = index_one + 1; 
    }
    
    //TODO: Your solution should go here
    //You can use functions if you would like to
     return 0;
}

