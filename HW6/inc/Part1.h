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
#define NUMBER_OF_WORDS 100
#define WORD_LENGTH 15
#define NUMBER_OF_CHOSEN_WORDS 10

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write
FILE *fpte; //fptw file pointer edit

void word_hunter();
void fill_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
void print_board(char board[Y_DIMENSION_LENGTH][X_DIMENSION_LENGTH]);
char random_char();
void words_array(char words[NUMBER_OF_WORDS][WORD_LENGTH]);
void generate_random_words(char random_words[NUMBER_OF_CHOSEN_WORDS][WORD_LENGTH]);

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
