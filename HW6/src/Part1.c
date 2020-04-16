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
	int complete = 0, quit = 0, correct; //boolean flag operators
	char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH];
	char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH];
	srand(time(0));

	choose_random_words(words);
	fill_board_words(board, words);

	printf("This is a %d%c%d puzzle. There are %d words hidden in this puzzle.\n", Y_DIMENSION_LENGTH, 'x', X_DIMENSION_LENGTH - 1, NUMBER_OF_CHOSEN_WORDS);
	while(1) {
		printf("Word list: (SOLVED/remaining)\n");
		print_words(words);
		printf("\n");
		print_board(board);
		if (complete) {
			printf("\nMission accomplished. Congratulations!\n");
			return;
		}
		solve_board(board, words, &quit, &correct);
		if (quit) {
			//system("clear");
			printf("Good bye!\n");
			return;
		} else if (correct) {
			//system("clear");
			printf("Good job!\n\n");
			are_words_solved(words, &complete);
		} else {
			//system("clear");
			printf("Please try again.\n\n");
		}
	}
	return;
}

//Words list
void choose_random_words(char random_words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]) {
	int i, j, i_random_word, same;//, length;
	char all_words[NUMBER_OF_ALL_WORDS][WORD_LENGTH];

	get_all_words(all_words);
	for (i = 0; i < NUMBER_OF_CHOSEN_WORDS; ++i) {
		i_random_word = rand() % 100;
		same = 0;
		//checks not to choose an already chosen word
		for (j = 0; j < i; ++j) {
			if (strcmp(random_words[j], all_words[i_random_word]) == 0) {
				same = 1;
				break;
			}
		}
		if (!same)
			strcpy(random_words[i], all_words[i_random_word]);
		else
			--i;
	}
	return;
}

//Words list
void get_all_words(char all_words[NUMBER_OF_ALL_WORDS][WORD_LENGTH]) {
	int i_words = 0;
	open_file_read("files/words.txt");
	while (fgets(all_words[i_words], WORD_LENGTH, fptr) != NULL) {
		strtok(all_words[i_words], "\n");
		++i_words;
	}
	close_file(fptr);
	return;
}

//Fill board
void fill_board_words(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH], char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]) {
	int board_y, board_x, words_index, words_array_index = 0, direction, error;
	char temp_words_first_char;
	//check if the number of chosen words does not reach to NUMBER_OF_CHOSEN_WORDS
	while (words_array_index < NUMBER_OF_CHOSEN_WORDS) {
		error = 0;
		words_index = 0;
		temp_words_first_char = ' ';
		direction = rand() % NUMBER_OF_DIRECTIONS;

		do {
			board_y = rand() % Y_DIMENSION_LENGTH;
			board_x = rand() % (X_DIMENSION_LENGTH - 1);
		} while ((96 < board[board_y][board_x] && board[board_y][board_x] < 123)
				&& (board[board_y][board_x]	!= words[words_array_index][words_index]));
		if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
			temp_words_first_char = words[words_array_index][words_index];

		//operations to different directions in cases for a chosen word (word_array_index)
		switch (direction) {
		case N: //North
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_N", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				--board_y;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						++board_y;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						++board_y;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		case NE: //North-East
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_NE", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				--board_y;
				++board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						++board_y;
						--board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						++board_y;
						--board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		case E: //East
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_E", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				++board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						--board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						--board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		case SE: //South-East
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_SE", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				++board_y;
				++board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						--board_y;
						--board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						--board_y;
						--board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		case S: //South
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_S", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				++board_y;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						--board_y;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						--board_y;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		case SW: //South-West
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_SW", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				++board_y;
				--board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						--board_y;
						++board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						--board_y;
						++board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		case W: //West
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_W", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				--board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						++board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						++board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		case NW: //North-West
			while (words[words_array_index][words_index] != '\0') {
				debug_printf(2, "fill_board_words_NW", board_y + 97, board_x);
				board[board_y][board_x] = words[words_array_index][words_index];
				++words_index;
				--board_y;
				--board_x;

				if (board_y
						< 0|| board_x < 0 || board_y > BORDER_INDEX || board_x > BORDER_INDEX) {
					while (words_index > 0) {
						--words_index;
						++board_y;
						++board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				} else if (96 < board[board_y][board_x]	&& board[board_y][board_x] < 123) {
					while (words_index > 0) {
						--words_index;
						++board_y;
						++board_x;
						board[board_y][board_x] = 32; //space character
					}
					error = 1;
					break;
				}
			}
			debug_printf(1, words[words_array_index], error, words[words_array_index][words_index]);
			break;
		default:
			break;
		}
		//if there is no error already, pass to the following word using word_array_index
		if (!error)
			++words_array_index;
		else if (error && (96 < temp_words_first_char && temp_words_first_char < 123))
			board[board_y][board_x] = temp_words_first_char;
	}
	fill_board_random_char(board);
}

//Fill board
void fill_board_random_char(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]) {
	int i, j;

	for (i = 0; i < Y_DIMENSION_LENGTH; ++i) {
		for (j = 0; j < X_DIMENSION_LENGTH - 1; ++j) {
			//check if the current index position is not free
			if (!(96 < board[i][j] && board[i][j] < 123))
				board[i][j] = random_char();
		}
		board[i][j + 1] = '\0';
	}
}

//Fill board
char random_char() {
	int i_alphabet;
	char alphabet[27] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z' };
	i_alphabet = rand() % 26;

	return alphabet[i_alphabet];
}

//Print
void print_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]) {
	int i, j;

	for (i = -2; i < Y_DIMENSION_LENGTH; ++i) {
		if (i == -2)
			printf("10* ");
		else if (i == -1)
			printf(" 1* ");
		else
			printf("(%c)  ", i + 97);
		for (j = 0; j < X_DIMENSION_LENGTH - 1; ++j) {
			if (i == -2)
				printf("-%d", j / 10);
			else if (i == -1)
				printf("-%d", j % 10);
			else
				printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	return;
}

//Print
void print_words(char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]) {
	int i;

	for (i = 0; i < NUMBER_OF_CHOSEN_WORDS; ++i) {
		printf("%d) %s", i + 1, words[i]);
	}
	return;
}

//Solve board
void solve_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH], char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *exit, int *correct) {
	int i_direction, word_index = 0, board_y, board_x;
	int temp_word_index, temp_board_y, temp_board_x;
	int words_array_index, success, word_valid;
	int directions[NUMBER_OF_DIRECTIONS];
	char word[WORD_LENGTH], coordinate[COORDINATE_LENGTH];
	*correct = 0;

	printf("Please enter (using lowercase character) the coordinate and the word: (e.g: a00 word)\n");
	printf("Or enter exit now to quit the program: (e.g: exit now)\n");
	scanf("%s %s", coordinate, word);

	board_y = coordinate[0] - 97;
	board_x = ((coordinate[1] - 48) * 10) + (coordinate[2] - 48);
	debug_printf(2, "solve_board_scanf", board_y + 97, board_x);
	is_word_valid(word, &word_valid);

	if (strcmp(coordinate, "exit") == 0 && strcmp(word, "now") == 0) {
		*exit = 1;
		return;
	} else if (!(96 < coordinate[0] && coordinate[0] < 123)) {
		printf("%c is an invalid y-axis coordinate. Please use only lowercase letters from a to z.\n", coordinate[0]);
		return;
	} else if (!(((47 < coordinate[1] && coordinate[1] < 50) || coordinate[1] == 120) || ((47 < coordinate[2] && coordinate[2] < 58) || coordinate[2] == 105))) {
		printf("%c%c is an invalid x-axis coordinate. Please use values from 00 to 19.\n", coordinate[1], coordinate[2]);
		return;
	} else if (!word_valid) {
		printf("%s is an invalid word. Please use only lowercase letters from a to z.\n", word);
		return;
	} else if (board[board_y][board_x] != word[word_index]) {
		printf("Typed word does not match the word on the coordinate.\n");
		return;
	} else {
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
	for (i_direction = 0; i_direction < NUMBER_OF_DIRECTIONS; ++i_direction) {
		if (directions[i_direction] != 1)
			continue;
		switch(i_direction){
		case N:
			success = 1;
			temp_word_index = word_index;
			temp_board_y = board_y;

			debug_printf(2, "solve_board_N", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_y = temp_board_y;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				--board_y;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					++board_y;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		case NE:
			success = 1;
			temp_word_index = word_index;
			temp_board_y = board_y;
			temp_board_x = board_x;

			debug_printf(2, "solve_board_NE", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_y = temp_board_y;
					board_x = temp_board_x;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				--board_y;
				++board_x;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					++board_y;
					--board_x;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		case E:
			success = 1;
			temp_word_index = word_index;
			temp_board_x = board_x;

			debug_printf(2, "solve_board_E", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_x = temp_board_x;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				++board_x;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					--board_x;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		case SE:
			success = 1;
			temp_word_index = word_index;
			temp_board_y = board_y;
			temp_board_x = board_x;

			debug_printf(2, "solve_board_SE", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_y = temp_board_y;
					board_x = temp_board_x;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				++board_y;
				++board_x;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					--board_y;
					--board_x;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		case S:
			success = 1;
			temp_word_index = word_index;
			temp_board_y = board_y;

			debug_printf(2, "solve_board_S", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_y = temp_board_y;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				++board_y;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					--board_y;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		case SW:
			success = 1;
			temp_word_index = word_index;
			temp_board_y = board_y;
			temp_board_x = board_x;

			debug_printf(2, "solve_board_SW", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_y = temp_board_y;
					board_x = temp_board_x;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				++board_y;
				--board_x;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					--board_y;
					++board_x;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		case W:
			success = 1;
			temp_word_index = word_index;
			temp_board_x = board_x;

			debug_printf(2, "solve_board_W", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_x = temp_board_x;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				--board_x;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					++board_x;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		case NW:
			success = 1;
			temp_word_index = word_index;
			temp_board_y = board_y;
			temp_board_x = board_x;

			debug_printf(2, "solve_board_NW", board_y + 97, board_x);
			while (word[word_index] != '\0') {
				if (board[board_y][board_x] != word[word_index]) {
					success = 0;
					word_index = temp_word_index;
					board_y = temp_board_y;
					board_x = temp_board_x;
					directions[i_direction] = 0;
					break;
				}
				++word_index;
				--board_y;
				--board_x;
			}
			find_in_words(word, words, &words_array_index);
			if (success && words_array_index >= 0) {
				while (word_index > 0) {
					--word_index;
					++board_y;
					++board_x;
					if (96 < board[board_y][board_x] && board[board_y][board_x] < 123)
						board[board_y][board_x] -= 32;
					words[words_array_index][word_index] -= 32;
				}
			}
			break;
		default:
			break;
		}
	}
	for (i_direction = 0; i_direction < NUMBER_OF_DIRECTIONS; ++i_direction) {
		if (directions[i_direction] == 1) {
			*correct = 1;
			directions[i_direction] = 0;
		}
	}
	while (getchar() != '\n');
	return;
}

//Solve board
void is_word_valid(char word[WORD_LENGTH], int *word_valid) {
	int i = 0;
	*word_valid = 1;

	while (word[i] != '\0') {
		if(!(96 < word[i] && word[i] < 123)) {
			*word_valid = 0;
			return;
		}
		++i;
	}
	return;
}

//Solve board
void find_in_words(char word[WORD_LENGTH], char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *word_array_index) {
	int i, j, count;
	*word_array_index = -1; //removes value from previous call to prevent to return it wrong

	for (i = 0; i < NUMBER_OF_CHOSEN_WORDS; ++i) {
		count = 0;
		for (j = 0; j < strlen(word); ++j) {
			if (word[j] == words[i][j])
				++count;
		}
		if (count == strlen(word)) {
			*word_array_index = i;
			return;
		}
	}
	return;
}

//Solve board
void are_words_solved(char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *complete) {
	int i, j;
	*complete = 1;

	for (i = 0; i < NUMBER_OF_CHOSEN_WORDS; ++i) {
		for (j = 0; j < strlen(words[i]); ++j) {
			if (96 < words[i][j] && words[i][j] < 123) {
				*complete = 0;
				return;
			}
		}
	}
	return;
}

//File operations
void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

//File operations
void open_file_write(char *file_path) {
	if ((fptw = fopen(file_path, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

//File operations
void open_file_edit(char *file_path) {
	if ((fpte = fopen(file_path, "a+")) == NULL) {
		printf("Error! File not edited.");
		exit(1);
	}
	return;
}

//File operations
void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}

//Debug
void debug_printf(int debug_value, char str[255], char c, int x) {
#ifdef DEBUG
#if (DEBUG == 1)
	if (debug_value == 1)
		printf("Word to be printed: %sError status: %d. Last letter after delete char: %c\n\n", str, c, x);
	else if (debug_value == 2)
		printf("%s: %c%02d\n", str, c, x);
#endif
#endif
}
