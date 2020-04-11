/*
 * Part1.c
 * Description: The word hunter game typically consists of scrambled letters in
 * a grid in which a player seeks for hidden meaningful words. Hidden words are
 * placed vertically, horizontally or diagonally. They may overlap but cannot be
 * in a zigzag form or wrap around. Your task is to create a word hunter puzzle
 * and let the player play the game.
 *
 * Example:
 * This is a 6x6 puzzle. There are 4 words hidden in this puzzle.
 * Words and their positions are:
 * • “hello” [d,0] & [d,4]
 * • “world” [b,0] & [e,4]
 * • “great” [a,0] & [a,4]
 * • “random” [e,5] & [a,5]
 * Note that: Row Numbers are denoted with letters a to z.
 *
 * Assignment:
 * You will create a puzzle map with a 20x20 grid where each cell contains a
 * character. To build a puzzle map, you must do the followings:
 * • You are given a list of 100 words. You will choose 10 random words from
 * this list and place them in the puzzle table with random directions and
 * positions. (Remember words can be scribed left to right, top-down, diagonally
 * or in the reverse order of these directions)
 * • Following word placement, you will fill the rest of the board with random
 * characters.
 *
 * Gameplay: On each turn, the puzzle and the selected word list are printed on
 * the screen with lower-case characters. Puzzle board should be printed with
 * the corresponding coordinates as a chessboard. The coordinate of the top-left
 * corner should be a0 and the bottom right should be o14
 * All characters should be lowercase. The program asks for a word and a
 * coordinate (r=row, c=column).
 *
 * Example:
 * ➢ Please enter the coordinate and the word:
 * ➢ E5 random
 * As soon as the player enters a makes a guess, the program must search for all
 * 8 directions If the guess is correct(both positions of the word are and list
 * contains the word), the corresponding word on the board and the list must be
 * converted to uppercase and reprinted. Otherwise, there is no change on board
 * and the list.
 *
 * Termination Conditions:
 * • The player finds all the words in the puzzle.
 * • Player types “Exit”.
 *
 *  Created on: Apr 10, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Part1.h"

void word_hunter() {
	int i, j;
	char board[DIMENSION_LENGTH][DIMENSION_LENGTH];

	srand(time(0));


	/*
	fill_board(board);
	print_board(board);
	*/
	for (i = 0; i < DIMENSION_LENGTH - 1; ++i) {
		for (j = 0; j < DIMENSION_LENGTH - 1; ++j) {
			//generating random numbers between 0 and 25 as index values for alphabet matrix
			//i_alphabet = rand() % 26;
			//board[i][j] = alphabet[i_alphabet];
			board[i][j] = random_char();
		}
		board[i][j + 1] = '\0';
	}
	for (i = 0; i < DIMENSION_LENGTH - 1; ++i) {
		for (j = 0; j < DIMENSION_LENGTH - 1; ++j) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	return;
}
/*
void fill_board(char **board) {
	int i, j;

	for (i = 0; i < DIMENSION_LENGTH - 1; ++i) {
		for (j = 0; j < DIMENSION_LENGTH - 1; ++j) {
			//generating random numbers between 0 and 25 as index values for alphabet matrix
			board[i][j] = random_char();
		}
		board[i][j + 1] = '\0';
	}
}

void print_board(char **board) {
	int i, j;

	for (i = 0; i < DIMENSION_LENGTH - 1; ++i) {
		for (j = 0; j < DIMENSION_LENGTH - 1; ++j) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	return;
}
*/
char random_char() {
	int i_alphabet;

	char alphabet[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z' };

	i_alphabet = rand() % 26;

	return alphabet[i_alphabet];
}

void words_array(char** words) {
	int i_words = 0;


	open_file_read("files/words.txt");
	while (fgets(words[i_words], WORD_LENGTH, fptr) != NULL) {
		strtok(words[i_words], "\n");
		++i_words;
	}
	close_file(fptr);
}

void random_word() {
	//char random_word[WORD_LENGTH];
	char words[NUMBER_OF_WORDS][WORD_LENGTH];
	words_array(words);
	printf("%s", words[5]);

	return;
}

void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

void open_file_write(char *file_path) {
	if ((fptw = fopen(file_path, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

void open_file_edit(char *file_path) {
	if ((fpte = fopen(file_path, "a+")) == NULL) {
		printf("Error! File not edited.");
		exit(1);
	}
	return;
}

void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}
