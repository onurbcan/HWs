/*
 * Part1.h
 *
 *  Created on: May 21, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

FILE *fptr;

typedef struct node{
	int num;
	struct node *next;
}n;

void array_vs_linkedlist(char *file_path);
int* read_array(char *file_path, int *num);
n* read_linkedlist(char *file_path, n *root);
float* stats_array();
float* stats_linkedlist();
int string_int_converter(char *num_str);
void open_file_read(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
