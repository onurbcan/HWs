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

int check_element(int *num, int num_version){
	if(feof(fptr)) {
		close_file(fptr); //closing file to be read
		close_file(fptw); //closing file to be written
		return 0;
	} else if(*num == 10) { //new line
		fprintf(fptw, "\n");
		return 0;
	} else if(!(*num >= 48 && *num <= 54)) {
		//if(num_version == 2)
			//fprintf(fptw, "%d", num1 % 7)
		//else if(num_version == 3)
			//fprintf(fptw, "%d", (num1 + num2) % 7)
		printf("Error! Invalid character");
		close_file(fptr); //closing file to be read
		close_file(fptw); //closing file to be written
		return 0;
	} else {
		*num = *num - 48;
		return 1;
	}

}

void deep_decrypt_and_print(char *file_path) {
	int num1, num2, num3, result;

	open_file_read(file_path);
	open_file_write("output.txt");

	num1 = getc(fptr);
	if(check_element(&num1, 1) == 1) {
		num2 = getc(fptr);
	}
	if(check_element(&num2, 2) == 1) {
		num3 = getc(fptr);
	}
	if(check_element(&num3, 3) == 1) {
		num3 = getc(fptr);
	}


	return;
}

/*
void beginning_of_line_operation(int *num1, int *num2, int *num3, int *result, int *flag) {
	*result = -1; //to check later if result is greater than -1
	*flag = 0; //to separate num3 == '\n' case for this function or a regular line

	if (!feof(fptr)) {	//1st number to read
		*num1 = fgetc(fptr);
		if(*num1 == '\n'){
			*result = 0;
			fprintf(fptw, "\n");
			return;
		}
	} else {
		return;
	} //fails and concludes if nothing in the file, otherwise gets first integer

	if(feof(fptr)) {
			return;
	}

	if (!feof(fptr)) { //2nd number to read
		*num2 = fgetc(fptr);
		if(*num2 == '\n'){
			*result = (ascii_converter(*num1)) % 7;
			fprintf(fptw, "%d\n", *result);
			return;
		}
	} else {
		*result = (ascii_converter(*num1)) % 7;
		fprintf(fptw, "%d\n", *result);
		return;
	} //fails and calculates if no second integer in the file, otherwise gets second integer

	if (!feof(fptr)) { //3rd number to read
		*num3 = fgetc(fptr);
		if(*num3 == '\n'){
			*flag = 1;
			*result = (ascii_converter(*num1) + ascii_converter(*num2)) % 7;
			fprintf(fptw, "%d\n", *result);
			return;
		}
	} else {
		*result = (ascii_converter(*num1) + ascii_converter(*num2)) % 7;
		fprintf(fptw, "%d\n", *result);
		return;
	} //fails and calculates if no third integer in the file, otherwise gets third integer

	if(feof(fptr)) {
		return;
	}
}

void deep_decrypt_and_print(char *file_path) {
	int num1, num2, num3, result, flag;

	open_file_read(file_path);
	open_file_write("output.txt");
	beginning_of_line_operation(&num1, &num2, &num3, &result, &flag);

	while (!feof(fptr)) { //if there is still integer in the file
		if (num3 == '\n') { //to separate end of lines
			fprintf(fptw, "\n");
			do{
				beginning_of_line_operation(&num1, &num2, &num3, &result, &flag);
				if (!(result > -1)) {
					result = (ascii_converter(num1) + ascii_converter(num2)
							+ ascii_converter(num3)) % 7;
					fprintf(fptw, "%d", result);
				}
			} while (num1 == '\n' || num2 == '\n' || flag == 1); //doing the function recursion for 0, 1, 2 integer in a line case
		} else { //regular calculation for 3 integers
			result = (ascii_converter(num1) + ascii_converter(num2)
					+ ascii_converter(num3)) % 7;
			fprintf(fptw, "%d", result);
		}
		num1 = num2; //shifting 1 integer each time
		num2 = num3; //shifting 1 integer each time
		num3 = fgetc(fptr); //getting a new integer for the third operand
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
*/
