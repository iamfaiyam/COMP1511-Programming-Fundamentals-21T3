// A C program which finds the nth last element in a linked list
// by Faiyam Islam z5258151

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int get_nth_last(int n, struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s n list-elements\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 2, &argv[2]);

    int result = get_nth_last(n, head);
    printf("%d\n", result);

    return 0;
}


// Return the n-th last element of linked list.
// n == 1 returns last element, n == 2, second last element, ....
int get_nth_last(int n, struct node *head) {

    assert(n >= 0);
    
    struct node *pointer = head; 
    int length = 0; 
    struct node *count = head; 
    while (count) {
        length++;
        count = count->next; 
    }
    
    int i = length - n; 
    
    while (i > 0) {
        assert(pointer != NULL);
        pointer = pointer->next; 
        i--;
    }
    
    return pointer->data; 
}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
