// Program which allows the user to enter a year, then calculates the date of 
// Easter Sunday for that year 
// by Faiyam Islam z5258151

#include <stdio.h> 

int main(void) {
    int day1, day2, day3, day4, day5, day6, day7, day8, day9, day10, day11, day12, day13; 
    int year, month, date; 
    
    printf("Enter year: "); 
    scanf("%d", &year);
    
    day1 = year % 19; 
    day2 = year / 100; 
    day3 = year % 100; 
    day4 = day2 / 4; 
    day5 = day2 % 4; 
    day6 = (day2 + 8) / 25; 
    day7 = (day2 - day6 + 1) / 3;
    day8 = (19 * day1 + day2 - day4 - day7 + 15) % 30; 
    day9 = day3 / 4;
    day10 = day3 % 4; 
    day11 = (32 + 2 * day5 + 2 * day9 - day8 - day10) % 7; 
    day12 = (day1 + 11 * day8 + 22 * day11) / 451; 
    month = (day8 + day11 - 7 * day12 + 114) / 31; 
    day13 = (day8 + day11 - 7 * day12 + 114) % 31;
    date = day13 + 1; 
    
    printf("Easter is "); 
    
    if (month == 3) {
        printf("March"); 
    } else {
        printf("April"); 
    }
    
    printf(" %d in %d.\n", date, year); 
   
    return 0; 
}

