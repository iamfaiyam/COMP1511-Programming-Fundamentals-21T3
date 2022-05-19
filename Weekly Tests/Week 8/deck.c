// Small library to handle various operations on a deck of cards.
// Written by Faiyam Islam (z5258151) on 11/11/21

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#include "deck.h"

struct deck *create_deck() {

    struct deck *new_deck = (struct deck *) malloc(sizeof(struct deck));
    new_deck->n_cards = 0;

    return new_deck;
}

void add_card(struct deck *deck, char *card) {

    strcpy(deck->cards[deck->n_cards], card);
    deck->n_cards += 1;
}

void print_deck(struct deck *deck) {

    int i = 0; 
    while (i < deck->n_cards) {
        printf("%s\n", deck->cards[i]);
        i++;
    }
}

int count_suit(struct deck *deck, char suit) {

    int count = 0;
    int i = 0;
    while (i < deck->n_cards) {
        int n = strlen(deck->cards[i]);
        if (deck->cards[i][n-1] == suit) {
            count++;
        }
        i++;
    }
    return count;
}
