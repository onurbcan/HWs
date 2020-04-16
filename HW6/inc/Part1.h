/*
 * Part1.h
 *
 *  Created on: Apr 10, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

//#define DEBUG 1

//Board properties
#define X_DIMENSION_LENGTH 21 //21 columns, last ones will be '\0'
#define Y_DIMENSION_LENGTH 20 //20 rows
#define BORDER_INDEX 19

//Game settings
#define NUMBER_OF_ALL_WORDS 100
#define NUMBER_OF_CHOSEN_WORDS 10
#define NUMBER_OF_DIRECTIONS 8

//User inputs
#define COORDINATE_LENGTH 5
#define WORD_LENGTH 15

//All directions
#define N 0 //North
#define NE 1 //North-East
#define E 2 //East
#define SE 3 //South-East
#define S 4 //South
#define SW 5 //South-West
#define W 6 //West
#define NW 7 //North-West

//File pointers
FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write
FILE *fpte; //fptw file pointer edit

//Word hunter game
void word_hunter();

//Words list
void choose_random_words(char random_words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);
void get_all_words(char all_words[NUMBER_OF_ALL_WORDS][WORD_LENGTH]);

//Fill board
void fill_board_words(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH], char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);
void fill_board_random_char(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
char random_char();

//Print
void print_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
void print_words(char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);

//Solve board
void solve_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH], char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *quit, int *correct);
void is_word_valid(char word[WORD_LENGTH], int *word_valid);
void find_in_words(char word[WORD_LENGTH], char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *word_array_index);
void are_words_solved(char words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH], int *complete);

//File operations
void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

void myprintf(char str[255]);

#endif /* INC_PART1_H_ */
