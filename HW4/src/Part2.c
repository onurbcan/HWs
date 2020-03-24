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
#include "Part1.h"
#include "Part2.h"

void beginning_of_line_operation(int *num1, int *num2, int *num3, int *result) {
	*result = -1; //to check later if result is greater than -1

	if (!feof(fptr)) {
		*num1 = getc(fptr);
	} else {
		return;
	} //fails and concludes if nothing in the file, otherwise gets first integer
	if (!feof(fptr)) {
		*num2 = getc(fptr);
	} else {
		*result = (ascii_converter(*num1)) % 7;
		fprintf(fptw, "%d\n", *result);
		return;
	} //fails and calculates if no second integer in the file, otherwise gets second integer
	if (!feof(fptr)) {
		*num3 = getc(fptr);
	} else {
		*result = (ascii_converter(*num1) + ascii_converter(*num2)) % 7;
		fprintf(fptw, "%d\n", *result);
		return;
	} //fails and calculates if no third integer in the file, otherwise gets third integer
}

void deep_decrypt_and_print(char *file_path) {
	int num1, num2, num3, result;

	open_file_read(file_path);
	open_file_write("output.txt");
	beginning_of_line_operation(&num1, &num2, &num3, &result);

	while (!feof(fptr)) { //if there is still integer in the file
		if (num3 == '\n') { //to separate end of lines
			fprintf(fptw, "\n");
			beginning_of_line_operation(&num1, &num2, &num3, &result);
			if (!(result > -1)) {
				result = (ascii_converter(num1) + ascii_converter(num2)
						+ ascii_converter(num3)) % 7;
				fprintf(fptw, "%d", result);
			}
		} else { //regular calculation for 3 integers
			result = (ascii_converter(num1) + ascii_converter(num2)
					+ ascii_converter(num3)) % 7;
			fprintf(fptw, "%d", result);
		}
		num1 = num2; //shifting 1 integer each time
		num2 = num3; //shifting 1 integer each time
		num3 = getc(fptr); //getting a new integer for the third operand
	}
	close_file(fptr); //closing file to be read
	close_file(fptw); //closing file to be written
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
}
