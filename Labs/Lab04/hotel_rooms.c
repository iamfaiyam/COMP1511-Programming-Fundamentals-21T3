// A C program which scans in a certan amount of hotel rooms and
// determines which are suitable according ot how many people the
// user has in their group
// by Faiyam Islam z5258151

#include <stdio.h>

#define MAX_ROOMS 50

struct hotel_room {
    // TODO: fill this in with the details of each hotel room
    int room_number; 
    int capacity; 
    double price; 
};

// Prints the room in the correct format when given the room_number, capacity
// and price of it.
void print_room(int room_number, int capacity, double price);

int main(void) {

    printf("How many rooms? ");
    // TODO: scan in how many rooms in the hotel
    int number_of_rooms; 
    scanf("%d", &number_of_rooms);

    printf("Enter hotel rooms:\n");
    // TODO: scan in the details of each hotel room
    struct hotel_room user; 

    struct hotel_room list_hotel_rooms[MAX_ROOMS];
    
    int i = 0;
    while (i < number_of_rooms) {
        scanf("%d %d %lf", &user.room_number, &user.capacity, &user.price); 
        list_hotel_rooms[i].room_number = user.room_number;
        list_hotel_rooms[i].capacity = user.capacity; 
        list_hotel_rooms[i].price = user.price; 
        i++;
    }

    printf("How many people? ");
    // TODO: scan in how many people are in the user's group
    int user_capacity; 
    scanf("%d", &user_capacity);

    printf("Rooms that fit your group:\n");
    // TODO: print all the rooms that fit the user's group
    int j = 0; 
    while (j < number_of_rooms) {
        if (user_capacity <= list_hotel_rooms[j].capacity) {
            print_room(list_hotel_rooms[j].room_number, 
            list_hotel_rooms[j].capacity, list_hotel_rooms[j].price);
        }
        j++;
    }
    
    return 0;
}

// Prints the room in the correct format when given the room_number, capacity
// and price of it.
//
// Takes in:
// - `room_number` -- The hotel room's room number.
// - `capacity` -- How many people the hotel room can fit.
// - `price` -- How much the hotel room costs.
//
// Returns: nothing.
void print_room(int room_number, int capacity, double price) {

    printf("Room %d (%d people) @ $%.2lf\n", room_number, capacity, price);

    return;
}
