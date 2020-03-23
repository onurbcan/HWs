/*
 * Part2.c
 * Description: They say that there could be another message if the numbers in
 * the file is replaced with the numbers gained from the formula:
 * 2
 * Number i = (∑ Number i+j ) % 7
 * j=0
 * 0 1 2 0 5 1 2 0 5 ...
 * 3 3 0 6 1 ...
 * You are asked again to write a function that prints that deep secret messages
 * in such files. By the formula, if there are no longer available three number
 * for any position such as end of lines, you can assume the value of missing
 * numbers are 0. Use encrypted_p2.img file to test your decryption function.
 * Don’t change the original file, just apply the formula when you print the
 * actual character. The function prototype has given below:
 *
 * void deep_decrypt_and_print (char* file_path)
 *
 *  Created on: Mar 23, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part2.h"

void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

void open_file_write(char *file_path) {
	if ((fptw = fopen(file_path, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}

void deep_decrypt_and_print(char *file_path) {
	int num1, num2, num3, result;

	open_file_read(file_path);
	open_file_write("output.txt");

	while (!feof(fptr)) {
		num1 = getc(fptr);
		num2 = getc(fptr);
		num3 = getc(fptr);

		if (num3 == '\n') {
			result = (ascii_converter(num1) + ascii_converter(num2)) % 7;
			fprintf(fptw, "%d\n", result);
		} else {
			result = (ascii_converter(num1) + ascii_converter(num2)
					+ ascii_converter(num3)) % 7;
			fseek(fptr, -2, SEEK_CUR);
			fprintf(fptw, "%d", result);
		}
	}
	close_file(fptr);
	close_file(fptw);
	return;
}

int ascii_converter(int number) {
	switch (number) {
	case ZERO:
		return (0);
	case ONE:
		return (1);
	case TWO:
		return (2);
	case THREE:
		return (3);
	case FOUR:
		return (4);
	case FIVE:
		return (5);
	case SIX:
		return (6);
	default:
		return (0);
	}
	return (0);
}
