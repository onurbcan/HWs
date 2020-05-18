/*
 * Part3.h
 *
 *  Created on: May 7, 2020
 *      Author: onur
 */

#ifndef INC_PART3_H_
#define INC_PART3_H_

#define N_CARDS 52 /* number of all cards */
#define N_SUITS 4 /* number of all suits */
#define N_FACES 13 /* number of all faces */
#define L_SUITS 9 /* length of a suit name */
#define L_FACES 6 /* length of a face name */

struct card {
	const char *face;
	const char *suit;
};

void playing_cards_deck();
void menu_cases(struct card cards[N_CARDS], int menu_choice);
void mix_cards(struct card cards[N_CARDS]);
void print_cards(struct card cards[N_CARDS]);

#endif /* INC_PART3_H_ */
