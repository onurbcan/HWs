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
	int i, j, k, menu_choice;
	char suits[N_SUITS][L_SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	char faces[N_FACES][L_FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	struct card cards[N_CARDS];

	srand(time(NULL));
	do {
		k = 0;
		for (i = 0; i < N_SUITS; ++i) {
			for (j = 0; j < N_FACES; ++j){
				cards[k].suit = suits[i];
				cards[k].face = faces[j];
				++k;
			}
		}
		printf("A brand new playing cards deck is obtained.\n\n");
		do {
			printf("What would you like to do? Please enter the number of your choice.\n");
			printf("1) See the cards.\n");
			printf("2) Mix the cards.\n");
			printf("3) Get brand new cards deck.\n");
			printf("4) Exit\n");
			scanf("%d", &menu_choice);
			system("clear");
			menu_cases(cards, menu_choice);
			while(getchar() != '\n');
		} while (!(menu_choice == 3 || menu_choice == 4));
	} while (menu_choice != 4);
	return;
}

void menu_cases(struct card cards[N_CARDS], int menu_choice) {
	switch (menu_choice) {
	case (1):
		printf("Here are the cards:\n\n");
		print_cards(cards);
		printf("\n");
		break;
	case (2):
		printf("Playing cards deck has just been mixed.\n\n");
		mix_cards(cards);
		break;
	case (3):
		break;
	case (4):
		printf("Good bye!\n");
		break;
	default:
		printf("Error occurred! %d is an invalid choice. Please try again.\n\n",
				menu_choice);
		break;
	}
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

	for (k = 0; k < 52; ++k) {
		printf("%5s%s%-8s", cards[k].face, " of ", cards[k].suit);
		if ((k + 1) % 2)
			printf("\t");
		else
			printf("\n");
	}
	return;
}
