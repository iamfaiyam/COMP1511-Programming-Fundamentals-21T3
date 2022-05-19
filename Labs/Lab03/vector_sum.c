// A C program which reads in two vectors with 3 integer
// components each and store the sum of these components in a new vectors to 
// be printed
// by Faiyam Islam z5258151

#include <stdio.h>

struct vector {
    int num1;
    int num2;
    int num3;
};

int main(void) {

    //////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
    struct vector first_vector;
    struct vector second_vector;

    // Scans in vector values from user
    // Carefully read how these scanf's work ~ Try to understand it
    printf("Please enter the values of the first vector (x, y, z): ");
    scanf("%d %d %d", &first_vector.num1, &first_vector.num2, &first_vector.num3);

    printf("Please enter the values of the second vector (x, y, z): ");
    scanf("%d %d %d", &second_vector.num1, &second_vector.num2, &second_vector.num3);

    struct vector sum_vector;
    //////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

    ////////////////////////////////////////////////////////////////////////////
    ///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    // TODO: Fill in `sum_vector` by adding each component of `first_vector`
    // and `second_vector`
    
    sum_vector.num1 = first_vector.num1 + second_vector.num1;
    sum_vector.num2 = first_vector.num2 + second_vector.num2; 
    sum_vector.num3 = first_vector.num3 + second_vector.num3;

    ////////////////////////////////////////////////////////////////////////////
    ///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    printf("The resulting sum vector is:\n");
    printf("x: %d\n", sum_vector.num1);
    printf("y: %d\n", sum_vector.num2);
    printf("z: %d\n", sum_vector.num3);
    return 0;
}
