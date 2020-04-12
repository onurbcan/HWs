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
	char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH];

	srand(time(0));
	printf("here1\n");
	fill_board(board);
	printf("here2\n");
	print_board(board);
	printf("here3\n");
	return;
}

void fill_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]) {
	int i, j, direction, board_y, board_x, error, word_index, word_array_index = 0;
	char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH];
	generate_random_words(words);
	printf("here1.1\n");
	do {
		error = 0;
		word_index = 0;
		direction = rand() % 8;
		do {
			board_y = rand() % 20;
			board_x = rand() % 20;
		} while ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index]));
		printf("here1.2\n");
		//operations to different directions in cases for a chosen word (word_array_index)
		switch(direction) {
		case 0: //North
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_y;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.3\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		case 1: //North-East
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_y;
				++board_x;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.4\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		case 2: //East
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_x;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.5\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		case 3: //South-East
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_y;
				++board_x;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.6\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		case 4: //South
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_y;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.7\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		case 5: //South-West
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_y;
				--board_x;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.8\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		case 6: //West
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_x;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.9\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		case 7: //North-West
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_y;
				--board_x;

				if (board_y < 0 || board_x < 0 || board_y > 19 || board_x > 19) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x] && board[board_y][board_x] < 123) && (board[board_y][board_x] != words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.10\n");
			} while (words[word_array_index][word_index] != '\0');
			break;
		}

		//if there is no error already, pass to the following word using word_array_index
		if(!error)
			++word_array_index;
		//check if number of chosen words does not reach to NUMBER_OF_CHOSEN_WORDS
		printf("here1.11\n");
	} while(word_array_index <= NUMBER_OF_CHOSEN_WORDS);
	printf("here1.12\n");

	for (i = 0; i < Y_DIMENSION_LENGTH; ++i) {
		for (j = 0; j < X_DIMENSION_LENGTH - 1; ++j) {
			//check if the current index position is free
			if(96 < board[board_y][board_x] && board[board_y][board_x] < 123)
				continue;
			//otherwise generate random numbers between 0 and 25 as index values for alphabet matrix
			board[i][j] = random_char();
		}
		board[i][j + 1] = '\0';
	}
	printf("here1.13\n");
}

void print_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]) {
	int i, j;

	for (i = 0; i < Y_DIMENSION_LENGTH; ++i) {
		for (j = 0; j < X_DIMENSION_LENGTH - 1; ++j) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	return;
}

char random_char() {
	int i_alphabet;

	char alphabet[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z' };

	i_alphabet = rand() % 26;

	return alphabet[i_alphabet];
}

void words_array(char words[NUMBER_OF_WORDS][WORD_LENGTH]) {
	int i_words = 0;

	open_file_read("files/words.txt");
	while (fgets(words[i_words], WORD_LENGTH, fptr) != NULL) {
		strtok(words[i_words], "\n");
		++i_words;
	}
	close_file(fptr);
}

void generate_random_words(char random_words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]) {
	int i, j, i_random_word;

	char words[NUMBER_OF_WORDS][WORD_LENGTH];

	words_array(words);
	for (i = 0; i < 10; ++i) {
		i_random_word = rand() % 100;
		strcpy(random_words[i], words[i_random_word]);
		j = 0;
		while (j < i) {
			//checks not to choose an already chosen word
			if (strcmp(random_words[j], random_words[i]) == 0) {
				random_words[i][0] = '\0';
				--i;
			}
			++j;
		}
	}

	for (i = 0; i < 10; ++i)
		printf("%d: %s", i, random_words[i]);

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
