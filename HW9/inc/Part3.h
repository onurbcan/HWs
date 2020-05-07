/*
 * Part3.h
 *
 *  Created on: May 7, 2020
 *      Author: onur
 */

#ifndef INC_PART3_H_
#define INC_PART3_H_

#define N_SUITS 4
#define N_FACES 13
#define N_CARDS 52

struct card {
	const char *face;
	const char *suit;
};

void playing_cards_deck();
struct card get_new_deck();
void mix_cards(struct card cards[N_CARDS]);
void print_cards(struct card cards[N_CARDS]);

#endif /* INC_PART3_H_ */
