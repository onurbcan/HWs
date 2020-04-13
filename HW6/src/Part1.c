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
	solve_board(board);
	print_board(board);
	return;
}

void fill_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]) {
	int i, j, direction, count, error, word_index, word_array_index = 0;
	char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH];
	generate_random_words(words);
	printf("here1.1\n");
	//board_y = 0;
	//board_x = 0;

	//check if the number of chosen words does not reach to NUMBER_OF_CHOSEN_WORDS
	while (word_array_index < NUMBER_OF_CHOSEN_WORDS) {
		error = 0;
		word_index = 0;
		direction = rand() % NUMBER_OF_DIRECTIONS;
		//direction = 4;
		//board_y = 0;
		//++board_x;

		do {
			board_y = rand() % (BORDER_INDEX + 1);
			board_x = rand() % (BORDER_INDEX + 1);
		} while ((96 < board[board_y][board_x] && board[board_y][board_x] < 123)
				&& (board[board_y][board_x]
						!= words[word_array_index][word_index]));

		printf("here1.2\n");
		//operations to different directions in cases for a chosen word (word_array_index)
		switch (direction) {
		case 0: //North
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_y;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.3\n");
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		case 1: //North-East
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_y;
				++board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.4 %d %d\n", board_y, board_x);
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		case 2: //East
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.5 %d %d\n", board_y, board_x);
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		case 3: //South-East
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_y;
				++board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.6 %d %d\n", board_y, board_x);
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		case 4: //South
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_y;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.7 %d %d\n", board_y, board_x);
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		case 5: //South-West
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				++board_y;
				--board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.8 %d %d\n", board_y, board_x);
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		case 6: //West
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.9 %d %d\n", board_y, board_x);
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		case 7: //North-West
			do {
				board[board_y][board_x] = words[word_array_index][word_index];

				++word_index;

				--board_y;
				--board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					error = 1;
					break;
				} else if ((96 < board[board_y][board_x]
						&& board[board_y][board_x] < 123)
						&& (board[board_y][board_x]
								!= words[word_array_index][word_index])) {
					error = 1;
					break;
				}
				printf("here1.10 %d %d\n", board_y, board_x);
			} while (words[word_array_index][word_index] != '\0');
			printf("%d %d\n", error, words[word_array_index][word_index]);
			break;
		default:
			break;
		}

		//if there is no error already, pass to the following word using word_array_index
		if (!error)
			++word_array_index;
		printf("here1.11\n");
	}
	printf("here1.12\n");

	for (i = 0; i < Y_DIMENSION_LENGTH; ++i) {
		for (j = 0; j < X_DIMENSION_LENGTH - 1; ++j) {
			//check if the current index position is free
			if (96 < board[i][j] && board[i][j] < 123)
				continue;
			//otherwise generate random numbers between 0 and 25 as index values for alphabet matrix
			else {
				board[i][j] = random_char();
				++count;
			}
		}
		board[i][j + 1] = '\0';
	}
	printf("count: %d\n", count);
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

void solve_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]) {
	int i, word_index = 0, success, directions[NUMBER_OF_DIRECTIONS];
	char word[WORD_LENGTH], coordinate[COORDINATE_LENGTH];

	printf("Please enter the coordinate and the word: (e.g: a00 word)\n");
	scanf("%s %s", coordinate, word);
	board_y = coordinate[0] - 97;
	board_x = ((coordinate[1] - 48) * 10) + (coordinate[2] - 48);
	printf("%d %d\n", board_y, board_x);
	if (board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
		printf("%s is not a valid coordinate. Please try again.\n", coordinate);

	} else if (board[board_y][board_x] != word[word_index]) {
		printf(
				"Typed word does not match the word on the coordinate. Please try again.\n");

	} else {
		//watch out! word_index set to 0 in the beginning of the function
		//++word_index;
		if (board[board_y - 1][board_x] == word[word_index + 1]) {
			directions[N] = 1; //North
		}
		if (board[board_y - 1][board_x + 1] == word[word_index + 1]) {
			directions[NE] = 1; //North-East
		}
		if (board[board_y][board_x + 1] == word[word_index + 1]) {
			directions[E] = 1; //East
		}
		if (board[board_y + 1][board_x + 1] == word[word_index + 1]) {
			directions[SE] = 1; //South-East
		}
		if (board[board_y + 1][board_x] == word[word_index + 1]) {
			directions[S] = 1; //South
		}
		if (board[board_y + 1][board_x - 1] == word[word_index + 1]) {
			directions[SW] = 1; //South-West
		}
		if (board[board_y][board_x - 1] == word[word_index + 1]) {
			directions[W] = 1; //West
		}
		if (board[board_y - 1][board_x - 1] == word[word_index + 1]) {
			directions[NW] = 1; //North-West
		}
	}

	for (i = 0; i < NUMBER_OF_DIRECTIONS; ++i) {
		if (directions[i] != 1)
			continue;

		switch(i){
		case N:
			success = 1;
			printf("here_new1.0\n");
			while (word[word_index] != '\0') {
				++word_index;
				--board_y;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					++board_y;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		case NE:
			success = 1;
			printf("here_new1.1\n");
			while (word[word_index] != '\0') {
				++word_index;
				--board_y;
				++board_x;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					++board_y;
					--board_x;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		case E:
			success = 1;
			printf("here_new1.2\n");
			while (word[word_index] != '\0') {
				++word_index;
				++board_x;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					--board_x;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		case SE:
			success = 1;
			printf("here_new1.3\n");
			while (word[word_index] != '\0') {
				++word_index;
				++board_y;
				++board_x;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					--board_y;
					--board_x;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		case S:
			success = 1;
			printf("here_new1.4\n");
			while (word[word_index] != '\0') {
				++word_index;
				++board_y;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					--board_y;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		case SW:
			success = 1;
			printf("here_new1.5\n");
			while (word[word_index] != '\0') {
				++word_index;
				++board_y;
				--board_x;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					--board_y;
					++board_x;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		case W:
			success = 1;
			printf("here_new1.6\n");
			while (word[word_index] != '\0') {
				++word_index;
				--board_x;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					++board_x;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		case NW:
			success = 1;
			printf("here_new1.7\n");
			while (word[word_index] != '\0') {
				++word_index;
				--board_y;
				--board_x;
				if (word[word_index] != '\0' && board[board_y][board_x] != word[word_index]) {
					success = 0;
					directions[i] = 0;
					continue;
				}
			}
			if (success) {
				while (word_index >= 0) {
					--word_index;
					++board_y;
					++board_x;
					board[board_y][board_x] -= 32;
				}
			}
			break;
		default:
			break;
		}
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

void generate_random_words(
		char random_words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]) {
	int i, j, i_random_word;

	char words[NUMBER_OF_WORDS][WORD_LENGTH];

	words_array(words);
	for (i = 0; i < NUMBER_OF_CHOSEN_WORDS; ++i) {
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

	for (i = 0; i < NUMBER_OF_CHOSEN_WORDS; ++i)
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
