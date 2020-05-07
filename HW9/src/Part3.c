/*
 * Part3.c
 *
 *  Created on: May 7, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Part3.h"

void playing_cards_deck() {
	int i, j, k = 0;
	char suits[N_SUITS][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	char faces[N_FACES][10] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	struct card cards[N_CARDS];

	srand(time(NULL));
	for (i = 0; i < N_SUITS; ++i) {
		for (j = 0; j < N_FACES; ++j){
			cards[k].suit = suits[i];
			cards[k].face = faces[j];
			++k;
		}
	}

	mix_cards(cards);
	print_cards(cards);
	return;
}

void mix_cards(struct card cards[N_CARDS]) {
	int k, k_rand;
	char *temp_suit, *temp_face;

	for (k = 0; k < N_CARDS; ++k) {
		do {
			k_rand = rand() % 52;
		} while (k_rand == k);

		temp_suit = cards[k].suit;
		cards[k].suit = cards[k_rand].suit;
		cards[k_rand].suit = temp_suit;

		temp_face = cards[k].face;
		cards[k].face = cards[k_rand].face;
		cards[k_rand].face = temp_face;
	}
	return;
}

void print_cards(struct card cards[N_CARDS]) {
	int k;
	char temp_print[20];

	for (k = 0; k < 52; ++k) {
		sprintf(temp_print, "%s of %s", cards[k].face, cards[k].suit);
		printf("%-20s", temp_print);
		if ((k + 1) % 2)
			printf("\t");
		else
			printf("\n");
	}
	return;
}
