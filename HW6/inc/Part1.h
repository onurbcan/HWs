/*
 * Part1.h
 *
 *  Created on: Apr 10, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define DIMENSION_LENGTH 21 //21 rows and 21 columns, last ones will be '\0'
#define NUMBER_OF_WORDS 100
#define WORD_LENGTH 15

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write
FILE *fpte; //fptw file pointer edit

void word_hunter();
void fill_board(char **);
void print_board(char **);
char random_char();
void words_array(char**);
void random_word();

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
