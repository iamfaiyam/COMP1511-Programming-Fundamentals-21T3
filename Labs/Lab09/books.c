//
// Author: Faiyam Islam (z5258151)
// Date: 12/11/21
//
// Description:
// A C program which maintains a list of books
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "books.h"

struct book {
    // TODO: You are required to fill in the fields of the struct.
    // You will need a next pointer and character arrays to store the title
    // and author.
    
    int num_pages; 
    char author[MAX_STR_LENGTH];
    char title[MAX_STR_LENGTH];
    
    struct book *next;    
};

struct book *insert_book(struct book *head, char *title, char *author, int num_pages) {
    // TODO: complete the function.

    struct book *new_book = malloc(sizeof(struct book));
     
    strcpy(new_book->title, title);
    strcpy(new_book->author, author); 
    
    new_book->num_pages = num_pages; 
    new_book->next = NULL; 

    struct book *curr_book = head; 
    
    if (head == NULL) {
        
        head = new_book; 
        return new_book; 
    
    }

    while (curr_book->next != NULL) {
        curr_book = curr_book->next; 
    }
    
    new_book->next = curr_book->next; 
    curr_book->next = new_book;
    
    return head;
}

void print_books(struct book *head) {
    // TODO: complete the function.

    struct book *current = head; 
    
    while (current != NULL) {
        
        printf("%s by %s (%d pages)\n", current->title, current->author, 
        current->num_pages);
        
        current = current->next; 
        
    }

    return;
}
