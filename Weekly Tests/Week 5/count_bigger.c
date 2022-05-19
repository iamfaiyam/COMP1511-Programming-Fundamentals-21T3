// A C program which returns a single integer: the number of values
// in the array which are larger than 99 or smaller than -99
// by Faiyam Islam z5258151

#include <stdio.h>

// return the number of "bigger" values in an array (i.e. larger than 99
// or smaller than -99).
int count_bigger(int length, int array[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int bigger = 0; 
    
    int i = 0; 
    while (i < length) {
        if (array[i] > 99 || array[i] < -99) {
            bigger = bigger + 1; 
        }
        i++; 
    }
  
    return bigger; 
}

// This is a simple main function which could be used
// to test your count_bigger function.
// It will not be marked.
// Only your count_bigger function will be marked.

#define TEST_ARRAY_SIZE 8

int main(void) {
    int test_array[TEST_ARRAY_SIZE] = {141, 5, 92, 6, 535, -89, -752, -3};

    int result = count_bigger(TEST_ARRAY_SIZE, test_array);

    printf("%d\n", result);
    return 0;
}
