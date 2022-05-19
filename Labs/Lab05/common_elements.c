// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination
// by Faiyam Islam z5258151

#include <stdio.h> 

int common_elements(int length, int source1[length], int source2[length], 
    int destination[length]) {

    int number = 0;
    int another_one = 0;
    while (another_one < length) {
        int element = 0;
        int another_two = 0;
        while (another_two < length && !element) {
            if (source1[another_one] == source2[another_two]) {
                element = 1;
            }
            another_two++;
        }
        if (element) {
            destination[number] = source1[another_one];
            number++;
        }
        another_one++;
    }
    return number;
}

    
int main(void) {

    printf("this code legit took me 3 hours");

    return 0;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
