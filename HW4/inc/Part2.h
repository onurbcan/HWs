/*
 * Part2.h
 *
 *  Created on: Mar 23, 2020
 *      Author: onur
 */

#ifndef INC_PART2_H_
#define INC_PART2_H_

#define ZERO 48
#define ONE 49
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53
#define SIX 54

FILE *fptr;
FILE *fptw;

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void close_file(FILE *file_pointer);
void deep_decrypt_and_print (char* file_path);
int ascii_converter(int number);

#endif /* INC_PART2_H_ */
