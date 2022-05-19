// A C program which reads 3 characters and indicates whether 
// they are strictly increasing (called "up"), strictly decreasing (called 
// "down"), or neither ("neither")
// by Faiyam Islam z5258151

#include <stdio.h>
   
int main(void) {
    char char1;
    char char2;
    char char3;
    
    printf("Please enter three characters: ");
    scanf("%c %c %c", &char1, &char2, &char3);

 
    if (char1 > char2 && char2 > char3) {
        printf("down\n");
    } 
 
    if (char1 > char3 && char3 > char2) {
        printf("neither\n");
    }
 
    if (char2 > char1 && char1 > char3) {
        printf("neither\n");
    }
 
    if (char2 > char3 && char3 > char1) {
        printf("neither\n");
    }
 
    if (char3 > char1 && char1 > char2) {
        printf("neither\n");
    }
 
    if (char3 > char2 && char2 > char1) {
        printf("up\n");
    }
 
    if (char1 > char2 && char2 == char3) {
        printf("neither\n");
    } 
 
    if (char2 > char3 && char1 == char3) {
        printf("neither\n");
    }
 
    if (char3 > char2 && char1 == char2) {
        printf("neither\n");
    }
 
    if (char1 == char2 && char2 > char3) {
        printf("neither\n");
    } 
 
    if (char2 == char3 && char3 > char1) {
        printf("neither\n");
    }
 
    if (char1 == char3 && char3 > char2) {
        printf("neither\n");
    }
 
    if (char1 == char2 && char2 == char3) {
        printf("neither\n");
    } 
 
    return 0; 
}


