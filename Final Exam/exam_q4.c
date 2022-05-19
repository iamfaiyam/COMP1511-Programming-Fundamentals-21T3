// A C program where given two arguments, value and head, 
// head is the pointer to the first node in a linked list, 
// deletes before and returns the original list
// by Faiyam Islam z5258151

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_before(int value, struct node *head);
struct node *create_node(int data, struct node *next);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// Delete the node immediately before the first instance of the
// given `value`.
struct node *delete_before(int value, struct node *head) {
   
    struct node *new_node = head, *node1, *node2; 
    if ((new_node != NULL) && (new_node->data == value)) {

        return head; 
    }
    
    node1 = new_node; 
    while ((new_node != NULL) && (new_node->data != value)) {

        node2 = node1; 
        node1 = new_node; 
        
        new_node = new_node->next; 
    }
    
    if (new_node == NULL) { 
        
        return head; 
    } else {
    
        if (node1->next == head->next) {
            head->data = new_node->data; 
            head->next = new_node->next; 
            
            free(new_node); 
            
            return head; 
        } else {
        
            node2 ->next = node1->next; 
            free(node1); 
            
            return head; 
        }
    }
}

//
// DO NOT CHANGE ANYTHING BELOW THIS COMMENT
//

int main(int argc, char *argv[]) {
    int value;
    scanf("%d", &value);
    // create linked list from command line arguments
    struct node *head = NULL;
    if (argc > 1) {
        // list has elements
        head = strings_to_list(argc - 1, &argv[1]);
    }

    struct node *new_head = delete_before(value, head);
    print_list(new_head);

    return 0;
}


// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
