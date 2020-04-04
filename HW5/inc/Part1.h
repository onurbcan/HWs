/*
 * Part1.h
 *
 *  Created on: Mar 31, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write

void menu();
int menu_cases();
void print_news(int, int);
void print_arrays(char [], int);
int read_news(char [], char [], int);
int number_of_news();
void append_file(char* file_path, char c);

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
