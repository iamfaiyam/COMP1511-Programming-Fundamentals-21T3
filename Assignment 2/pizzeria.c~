//
// Assignment 2 21T3 COMP1511: CS Pizzeria
// pizzeria.c
//
// This program was written by Faiyam Islam (z5258151)
// on 7/11/21
//
// Description of CS Pizzeria:
// A C program which manages a pizzeria through linked lists compiled
// as a multi-file project. This C program is able to manage different types
// of pizzas with various ingredients with different orders of pizzas 
// (previous and orders after). The time, price, name of customer as well as
// the profit is included in this pizzeria. Additional information 
// about the functions of each individual part is explained through comments.  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pizzeria.h"

struct ingredient {

    struct ingredient *next;
    char *name;
    int amount; 
    double price; 

};

struct order {

    // Looking to store a price field? Try putting in "double price;" here!
    char *customer_name;
    char *type_of_pizza;
    int pizza_time;
    int time_allowed;
    double price; 
    struct ingredient *diff_ing; 
    struct order *next; 
};

struct pizzeria {

    struct order *chosen;
    struct order *select;
 
};


// Prints a single order
void print_order (
    int num,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed);

// Prints an ingredient given the name, amount and price in the required format.
// This will be needed for stage 2.
void print_ingredient(char *name, int amount, double price);

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

struct pizzeria *create_pizzeria() {

    // Allocates memory to store a `struct pizzeria` and returns a pointer to
    // it. The variable `new` holds this pointer!
    struct pizzeria *new_pizza = malloc(sizeof(struct pizzeria));

    new_pizza->select = NULL;
    
    new_pizza->chosen = NULL;
    
    return new_pizza;
}

int add_order(
    struct pizzeria *pizzeria,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed)
{
    
    if (price < 0) {
        return INVALID_PRICE;
        
    } else if (time_allowed <= 0) {
        return INVALID_TIME;
    
    }
      
    struct order *new_pizza = malloc(sizeof(struct order));
    new_pizza->customer_name = strdup(customer);
    
    new_pizza->type_of_pizza = strdup(pizza_name);
    
    new_pizza->price = price;
    
    new_pizza->pizza_time = time_allowed;
    
    new_pizza->diff_ing = NULL;

    new_pizza->next = NULL;

    if (pizzeria->select == NULL) {
    
        pizzeria->select = new_pizza;
   
    } else {

        struct order *node = pizzeria->select;
        while (node->next != NULL) {
        
            node = node->next;
        
        } 
        node->next = new_pizza;
    }
    return SUCCESS;
} 
    
// Stage 1.2: Print All Orders
// This function prints the selected order of the pizza, including the 
// type of pizza, the cost of the pizza and the time it will take to 
// create the pizza for each individual customer
void print_all_orders(struct pizzeria *pizzeria) {

    
    int order_number = 1; 
    struct order *node = pizzeria->select;
    while (node != NULL) {
    
        print_order(order_number, node->customer_name, node->type_of_pizza, 
        node->price, node->pizza_time);
        
        order_number++;
        node = node->next;
    }
            
    print_selected_order(pizzeria);
}

// Stage 1.3: Next Deadline
// The main function of this stage is that after the user prints out 
// the customer's order for their pizza, if they print an exclamation 
// mark then the function will print out the next deadline for the 
// pizza order. 
int next_deadline(struct pizzeria *pizzeria) {

    struct order *node = pizzeria->select;
    int wrong_call = INVALID_CALL;
    while (node != NULL) {
   
        if ((wrong_call == INVALID_CALL) || (node->pizza_time < wrong_call)) {
       
            wrong_call = node->pizza_time;
        }
        node = node->next;
    }

    return wrong_call;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Stage 2.2: Print Selected Order
// This function will allow the customer to print out the selected 
// order. The command '>' can allow the customer to move to another
// order for the pizza. 
void select_next_order(struct pizzeria *pizzeria) {

    struct order *chosen = pizzeria->chosen; 
    struct order *new_node = pizzeria->select; 
    if (new_node != NULL) {
        
        if (chosen == NULL) {
            chosen = new_node; 
        } else {
            chosen = chosen->next; 
        }
    }
    
    pizzeria->chosen = chosen; 
    
    return;
}

// Stage 2.3: Select Previous Order
// The customer here is able to print the next order using '>'
// but unlike stage 2.2, the customer is able to go back to the 
// previous order, with details of price and time given. 
void select_previous_order(struct pizzeria *pizzeria) {

    if (pizzeria->select == NULL) {

        pizzeria->chosen = NULL;
        
        return;
    }

    struct order *node = pizzeria->select;
    while (node->next != NULL && node->next != pizzeria->chosen) {
   
        node = node->next;
    }

    if (pizzeria->chosen == pizzeria->select) { 
    
        pizzeria->chosen = NULL;
    
    } else {
   
        pizzeria->chosen = node;
    }

    return;
}

void print_selected_order(struct pizzeria *pizzeria) {

    if (pizzeria->chosen == NULL) {
    
        printf("\nNo selected order.\n");
    
    } else {
   
        printf("\nThe selected order is %s's %s pizza",
        pizzeria->chosen->customer_name, pizzeria->chosen->type_of_pizza); 
        
        printf("($%.2lf) due in %d minutes.\n",
        pizzeria->chosen->price, pizzeria->chosen->pizza_time);
              
        struct ingredient *node = pizzeria->chosen->diff_ing;
        while (node != NULL) {
        
            print_ingredient(node->name, node->amount, node->price);
            node = node->next;
        }
    }
}

// Stage 2.4: Add Ingredient
// With this function, the customer is able to select the individual
// ingredients in each of the pizzas. This function will specify
// the pizza which the customer has ordered, such as Margherita pizza.  
int add_ingredient(
    struct pizzeria *pizzeria,
    char *ingredient_name,
    int amount,
    double price)
{
    struct order *chosen = pizzeria->chosen;
    if (chosen == NULL) {
        return INVALID_ORDER;
        
    } else if (amount <= 0) {
        return INVALID_AMOUNT;
        
    } else if (price < 0) {
        return INVALID_PRICE;

    }
    
    struct ingredient *counter = malloc(sizeof(struct ingredient));
    counter->name = strdup(ingredient_name);
    
    counter->amount = amount;
    
    counter->next = NULL;
    
    counter->price = price;

    if ((chosen->diff_ing == NULL) || (strcmp(chosen->diff_ing->name, 
    counter->name)) > 0) {
    
        counter->next = chosen->diff_ing;
        chosen->diff_ing = counter;
        
    } else {
    
        struct ingredient *node = chosen->diff_ing;
        while ((node->next != NULL) && (strcmp(counter->name, 
        node->next->name)) > 0) {
        
            node = node->next;
        }
        if (strcmp(counter->name, node->name) == 0) {
   
            node->amount = node->amount + counter->amount;
            
        } else if ((node->next != NULL) && strcmp(counter->name, 
        node->next->name) == 0) {
        
            node = node->next;
            
            node->amount = node->amount + counter->amount;
        
        } else {
       
            counter->next = node->next;
            
            node->next = counter;
        }
    }

    return SUCCESS;
}

// Stage 2.5: Calculate Total Profit
// The crux of this function is to calculate the total profit
// of the type of pizza which a customer orders, based on ingredients.
double calculate_total_profit(struct pizzeria *pizzeria) {

    struct ingredient *current; 
    double profit = 0.0;
    double previous_price; 
    double ingredient_price; 
    
    if (pizzeria->chosen == NULL) {
        
        return INVALID_ORDER;
        
    } else {
        
        current = pizzeria->chosen->diff_ing; 
        ingredient_price = 0; 
        while (current != NULL) {
 
            previous_price = current->price * current->amount; 
            
            ingredient_price = ingredient_price + previous_price;
            
            current = current->next;
            
        }
        
        profit = pizzeria->chosen->price - ingredient_price; 
  
    }
            
    return profit;
      
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

int cancel_order(struct pizzeria *pizzeria)
{
   
    // TODO: fill in the rest of this function
   
    return SUCCESS;
}

void free_pizzeria(struct pizzeria *pizzeria)
{

    return;
}

int refill_stock(
    struct pizzeria *pizzeria,
    char *ingredient_name,
    int amount,
    double price)
{

    // TODO: fill in the rest of this function

    return SUCCESS;
}

void print_stock(struct pizzeria *pizzeria)
{

    // TODO: fill in the rest of this function

    return;
}

int can_complete_order(struct pizzeria *pizzeria)
{

    // TODO: fill in the rest of this function

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

int complete_order(struct pizzeria *pizzeria)
{

    return SUCCESS;
}

int save_ingredients(struct pizzeria *pizzeria, char *file_name)
{

    return SUCCESS;
}

int load_ingredients(struct pizzeria *pizzeria, char *file_name)
{

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////
//               HELPER FUNCTIONS - Add your own here                 //
////////////////////////////////////////////////////////////////////////


// Prints a single order
//
// `print_order` will be given the parameters:
// - `num` -- the integer that represents which order it is sequentially.
// - `customer` -- the name of the customer for that order.
// - `pizza_name` -- the pizza the customer ordered.
// - `price` -- the price the customer is paying for the pizza.
// - `time_allowed` -- the time the customer will wait for the order.
//
// `print_order` assumes all parameters are valid.
//
// `print_order` returns nothing.
//
// This will be needed for Stage 1.
void print_order(
    int num,
    char *customer,
    char *pizza_name,
    double price,
    int time_allowed)
{

    printf("%02d: %s ordered a %s pizza ($%.2lf) due in %d minutes.\n",
           num, customer, pizza_name, price, time_allowed);

    return;
}

// Prints a single ingredient
//
// `print_ingredient` will be given the parameters:
// - `name` -- the string which contains the ingredient's name.
// - `amount` -- how many of the ingredient we either need or have.
// - `price` -- the price the ingredient costs.
//
// `print_ingredient` assumes all parameters are valid.
//
// `print_ingredient` returns nothing.
//
// This will be needed for Stage 2.
void print_ingredient(char *name, int amount, double price)
{
    printf("    %s: %d @ $%.2lf\n", name, amount, price);
}


