/*
 * Part1.h
 *
 *  Created on: Apr 10, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

/*! Switch to on/off debugging feature */
#define DEBUG 1

/*! Length of X-axis dimension (21 columns) together with last character of
 * '\0' */
#define X_DIMENSION_LENGTH 21
/*! Length of Y-axis dimension (20 columns) */
#define Y_DIMENSION_LENGTH 20
/*! Index of the last character in a row or column to check if the border is
 * reached */
#define BORDER_INDEX 19

/*! Game settings for the number of all words */
#define NUMBER_OF_ALL_WORDS 100
/*! Game settings for the number of chosen words */
#define NUMBER_OF_CHOSEN_WORDS 10
/*! Game settings for the number of directions */
#define NUMBER_OF_DIRECTIONS 8

/*! Player input properties for the coordinate section */
#define COORDINATE_LENGTH 5
/*! Player input properties for the word section */
#define WORD_LENGTH 15

/*! Constant representing the North directions */
#define N 0
/*! Constant representing the North-East directions */
#define NE 1
/*! Constant representing the East directions */
#define E 2
/*! Constant representing the South-East directions */
#define SE 3
/*! Constant representing the South directions */
#define S 4
/*! Constant representing the South-West directions */
#define SW 5
/*! Constant representing the West directions */
#define W 6
/*! Constant representing the North-West directions */
#define NW 7

/*! File pointer to read the file */
FILE *fptr; //fptr file pointer read
/*! File pointer to write the file */
FILE *fptw; //fptw file pointer write
/*! File pointer to edit the file */
FILE *fpte; //fptw file pointer edit

/*! 1.0) Word hunter game */
void word_hunter();

/*! 2.0) Words list */
void choose_random_words(char random_words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);
void get_all_words(char all_words[NUMBER_OF_ALL_WORDS][WORD_LENGTH]);

/*! 3.0) Fill board */
void fill_board_words(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH],
		char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);
void fill_board_random_char(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
char random_char();

/*! 4.0) Print */
void print_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
void print_words(char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);

/*! 5.0) Solve board */
void solve_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH],
		char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *quit,
		int *correct);
void is_word_valid(char word[WORD_LENGTH], int *word_valid);
void find_in_words(char word[WORD_LENGTH],
		char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *word_array_index);
void are_words_solved(char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH],
		int *complete);

/*! 6.0) File operations */
void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

/*! 7.0) Debug */
void debug_printf(int debug_value, char str[255], char c, int x);

#endif /* INC_PART1_H_ */
