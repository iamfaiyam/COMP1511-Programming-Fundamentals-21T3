// A C program which helps route an electric car along a long road
// by Faiyam Islam z5258151

#include <stdio.h>
#include <stdbool.h>

#define STATIONS 10000

int nonzero(int size, int array[size]) {
    int i = 0;
    while (i < size) {
        if (array[i] > 0) {
            return true;
        }
        i++;
    }
    return false;
}

int find_max_index(int size, int array[size]) {
    int max_index = 0;
    
    int i = 0;
    while (i < size) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
        i++;
    }
    
    return max_index;
}

int main(void) {
    int stations[STATIONS] = {0};
    int number_stations = 0;
    while (scanf("%d", &stations[number_stations++]) == 1);

    int number_stops = 0;
    int fuel = 1;
    
    while (nonzero(fuel, stations) && fuel < number_stations - 1) {
        int max_index = find_max_index(fuel, stations);
        fuel += stations[max_index];
        stations[max_index] = 0;
        number_stops++;
    }

    if (fuel >= number_stations - 1) {
        printf("%d\n", number_stops);
    } else {
        printf("%d\n", 0);
    }
    return 0;
}



