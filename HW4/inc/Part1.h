/*
 * Part1.h
 *
 *  Created on: Mar 19, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define ZERO 48
#define ONE 49
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53
#define SIX 54

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void close_file(FILE *file_pointer);
void decrypt_and_print(char *file_path);
char decrypt_numbers(int number);

#endif /* INC_PART1_H_ */
