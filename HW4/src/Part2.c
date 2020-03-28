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

void deep_decrypt_and_print(char *file_path) {
	int num1, num2, num3, new_line;

	open_file_read(file_path);
	open_file_write("output.txt");

	do {
		new_line = 0;

		num1 = getc(fptr);
		if (feof(fptr)) {
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		} else if (num1 == 10) {
			fprintf(fptw, "\n");
			new_line = 1;
			continue;
		} else if (!(num1 >= 48 && num1 <= 54)) {
			printf("Error! Invalid character.\n");
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		}

		num2 = getc(fptr);
		if (feof(fptr)) {
			fprintf(fptw, "%d", (num1 - 48) % 7);
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		} else if (num2 == 10) {
			fprintf(fptw, "%d\n", (num1 - 48) % 7);
			new_line = 1;
			continue;
		} else if (!(num2 >= 48 && num2 <= 54)) {
			fprintf(fptw, "%d", (num1 - 48) % 7);
			printf("Error! Invalid character.\n");
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		}

		num3 = getc(fptr);
		do {
			if (feof(fptr)) {
				fprintf(fptw, "%d", ((num1 - 48) + (num2 - 48)) % 7);
				fprintf(fptw, "%d", (num2 - 48) % 7);
				close_file(fptr); //closing file to be read
				close_file(fptw); //closing file to be written
				return;
			} else if (num3 == 10) {
				fprintf(fptw, "%d", ((num1 - 48) + (num2 - 48)) % 7);
				fprintf(fptw, "%d\n", (num2 - 48) % 7);
				new_line = 1;
			} else if (!(num3 >= 48 && num3 <= 54)) {
				fprintf(fptw, "%d", ((num1 - 48) + (num2 - 48)) % 7);
				printf("Error! Invalid character.\n");
				close_file(fptr); //closing file to be read
				close_file(fptw); //closing file to be written
				return;
			} else {
				fprintf(fptw, "%d",
						((num1 - 48) + (num2 - 48) + (num3 - 48)) % 7);
				num1 = num2;
				num2 = num3;
				num3 = getc(fptr);
			}
		} while (new_line != 1);
	} while (1);
}
