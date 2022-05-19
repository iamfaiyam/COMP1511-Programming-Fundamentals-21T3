
// A C program which scans in pairs and replaces corresponding elements
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {

    int painter[36] = {0};
    int scanned_in_value;
    
    while (scanf("%d", &scanned_in_value) == 1) {
        painter[scanned_in_value] = 1; 
    }
    
    int i = 0; 
    while (i < 36) {
        printf("%d", painter[i]);
        i++; 
    }
    printf("\n");
    
    return 0; 
}

