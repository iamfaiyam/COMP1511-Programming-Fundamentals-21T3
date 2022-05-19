// A C program which determines which quadrant a person is standing 
// based on their coordinates
// by Faiyam Islam z5258151

#include <stdio.h>
#include <stdlib.h>

struct coordinate {
    int x;
    int y;
};

// Return the the first set of coordinates in the third quadrant
// This means both x and y coordinates are negative
struct coordinate struct_quadrant(int size, struct coordinate array[size]) {
    // TODO: Complete this function.
    int quad = 0; 
    while (quad < size) { 
        
        if (array[quad].y < 0 && array[quad].x < 0) {
        
            return array[quad];
            
        }
        quad++;
    }
    return array[quad]; 
}

// This is a simple main function which could be used
// to test your struct_quadrant function.
// It will not be marked.
// Only your step_quadrant function will be marked.

#define TEST_ARRAY_SIZE 3

int main(void) {
    struct coordinate test_array[TEST_ARRAY_SIZE] = {
        { .x = -30, .y = 20},
        { .x = -25, .y = -23},
        { .x = 5, .y = 51}
    };
    struct coordinate third_quad = struct_quadrant(TEST_ARRAY_SIZE, test_array);
    printf("(%d, %d)\n", third_quad.x, third_quad.y);

    return 0;
}
