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
void menu_cases();
void newfunc();
void read_news(char buffer[500], char file_path[10], int is_Only_Title);

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
