/*
 * Part1.h
 *
 *  Created on: Apr 10, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_


#define X_DIMENSION_LENGTH 21 //21 columns, last ones will be '\0'
#define Y_DIMENSION_LENGTH 20 //20 rows
#define BORDER_INDEX 19
#define NUMBER_OF_WORDS 100
#define WORD_LENGTH 15
#define COORDINATE_LENGTH 4
#define NUMBER_OF_CHOSEN_WORDS 2
#define NUMBER_OF_DIRECTIONS 8

#define N 0 //North
#define NE 1 //North-East
#define E 2 //East
#define SE 3 //South-East
#define S 4 //South
#define SW 5 //South-West
#define W 6 //West
#define NW 7 //North-West

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write
FILE *fpte; //fptw file pointer edit

int board_y, board_x;

void word_hunter();
void fill_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
void print_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
void solve_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
char random_char();
void words_array(char words[NUMBER_OF_WORDS][WORD_LENGTH]);
void generate_random_words(char random_words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
