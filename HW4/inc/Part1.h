/*
 * Part1.h
 *
 *  Created on: Mar 19, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6

FILE *fptr;

void open_file(char *file_path);
void decrypt_and_print(char *file_path);
char decrypt_numbers(int number);

#endif /* INC_PART1_H_ */
