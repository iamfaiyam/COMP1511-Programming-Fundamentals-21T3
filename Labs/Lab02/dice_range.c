// A program which reads the number of sides on a set of dice and how
// many of them are being rolled. It then outputs the range of possible
// totals that these dice can produce as well as the average value. 
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int size; 
    int num; 
    int lowest; 
    int highest; 
    double average; 
    
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &size); 
    
    printf("Enter the number of dice being rolled: "); 
    scanf("%d", &num); 
    
    lowest = num; 
    highest = num * size; 
    
    average = (lowest + highest) / 2.0; 
    
    if (size <= 0 || highest <= 0) {
        printf("These dice will not produce a range.\n"); 
    } else {
        printf("Your dice range is %d to %d.\n", lowest, highest); 
        printf("The average value is %lf\n", average); 
    }
   
    return 0; 
}


