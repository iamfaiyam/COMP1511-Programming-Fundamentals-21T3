// Find the largest sum of numbers in a z shape.
// by Faiyam Islam z5258151

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 100

int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE];

    // Get the array size.
    int size;
    printf("Enter 2D array side length: ");
    scanf("%d", &size);
    assert(size >= 3);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            assert(scanf("%d", &array[i][j]) == 1);
            j++;
        }
        i++;
    }

    printf("The largest z sum is %d.\n", largest_z_sum(size, array));

    return 0;
}

// Return the largest sum of numbers in a z shape.
int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE]) {
    // Put your code here.
    int size1 = 3; 
    
    int total_sum = array[0][0] + array[0][1] + array[0][2] + array[1][1] 
                    + array[2][0] + array[2][1] + array[2][2];

    while (size1 <= size) {
        int z_y = 0;
        while (z_y <= size - size1) {
            int z_x = 0; 
            while(z_x <= size - size1) {
            
                int top_row_sum = 0; 
                int i = 0; 
                while (i < size1 - 1) {
                    top_row_sum += array[z_y][z_x + i];
                    i++;
                }
                
                int diagonal_total = 0; 
                i = 0; 
                while (i < size1) {
                    diagonal_total += array[z_y + i][z_x + (size1 - 1) - i];
                    i++;
                }
                
                int bottom_sum = 0; 
                i = 1; 
                
                while (i < size1) {
                    bottom_sum += array[z_y + (size1 - 1)][z_x + i];
                    i++;
                }
                
                int total = top_row_sum + diagonal_total + bottom_sum; 
                if (total > total_sum) {
                    total_sum = total;
                }
                
                z_x++;
            }
            
            z_y++;
        }
        
        size1++;
    }        
   
    return total_sum;
}
