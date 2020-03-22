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

FILE *fptr;

void open_file(char *file_path);
void close_file();
void decrypt_and_print(char *file_path);
char decrypt_numbers(int number);

#endif /* INC_PART1_H_ */
