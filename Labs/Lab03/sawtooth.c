// A C program which reads in two non-negative integers, 
// a height and a length. The height represents how tall the 
// sawtooth pattern will be and the length represents how 
// long the sawtooth will be
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int height, length;
    int height_counter, length_counter, space_counter;  
    
    printf("Please enter the height of the sawtooth: "); 
    scanf("%d", &height); 
    
    printf("Please enter the length of the sawtooth: "); 
    scanf("%d", &length); 
    
    height_counter = 0; 
    while (height_counter < height) {
        length_counter = 0; 
        space_counter = 0; 
        while (length_counter < length) {
            if (length_counter % height == 0) {
                printf("*"); 
            } else if (space_counter <= length + height - 1 &&
            length_counter == height_counter + space_counter * height) {
                printf("*");
                space_counter++;
            } else {
                printf(" ");
            }
            
            length_counter++;
        }
        printf("\n");
        height_counter++;
    }

    return 0;
}



