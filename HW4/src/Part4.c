/*
 * Part4.c
 * Description: Our tracking machine works like a charm! There is only one thing
 * left to do. We want to manipulate the enemies’ plans by leaking our messages
 * into their network. The opponents use a new encryption algorithm that uses
 * the formula below:
 * 2
 * Number i = (∑ Number i − j ) % 7
 * j=0
 * 000 1 2 0 5 1 2 0 5 ...
 * 0 1 3 3 0 ...
 * Therefore, you are asked to write a function that takes a message string as
 * input and encrypts the message by using the formula below. The function saves
 * the encrypted message in encrypted_p4.img file. Use decrypted_p4.img file for
 * encryption. Use zeros as much as you need when encoding the first two numbers.
 *
 * void encrypt_messages (char* file_path)
 *
 *  Created on: Mar 24, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"
#include "Part4.h"

void encrypt_messages(char *file_path) {
	int num1, num2, num3;

	open_file_read(file_path);
	open_file_write("output.txt");

	do {
		num1 = getc(fptr);
		if (num1 == EOF) {
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		} else if (num1 == 10) {
			fprintf(fptw, "\n");
			continue;
		} else if (check_invalid_characters(num1)) {
			printf("Error! Invalid character.\n");
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		} else {
			num1 = encrypt_characters(num1);
			fprintf(fptw, "%d", num1 % 7);
		}

		num2 = getc(fptr);
		if (num2 == EOF) {
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		} else if (num2 == 10) {
			fprintf(fptw, "\n");
			continue;
		} else if (check_invalid_characters(num2)) {
			printf("Error! Invalid character.\n");
			close_file(fptr); //closing file to be read
			close_file(fptw); //closing file to be written
			return;
		} else {
			num2 = encrypt_characters(num2);
			fprintf(fptw, "%d", (num1 + num2) % 7);
		}

		num3 = getc(fptr);
		do {
			if (num3 == EOF) {
				close_file(fptr); //closing file to be read
				close_file(fptw); //closing file to be written
				return;
			} else if (num3 == 10) {
				fprintf(fptw, "\n");
				break;
			} else if (check_invalid_characters(num3)) {
				printf("Error! Invalid character.\n");
				close_file(fptr); //closing file to be read
				close_file(fptw); //closing file to be written
				return;
			} else {
				num3 = encrypt_characters(num3);
				fprintf(fptw, "%d", (num1 + num2 + num3) % 7);
				num1 = num2;
				num2 = num3;
				num3 = getc(fptr);
			}
		} while (1);
	} while (1);
}

int check_invalid_characters(int character) {
	switch (character) {
	case 32: // ‘ ’
		return (0);
	case 45: // ‘-’
		return (0);
	case 95: // ‘_’
		return (0);
	case 124: // ‘|’
		return (0);
	case 47: // ‘/’
		return (0);
	case 92: // ‘\’
		return (0);
	case 79: // ‘O‘
		return (0);
	default:
		return (1);
	}
}

	int encrypt_characters(int character) {
		switch (character) {
		case ' ':
			return (0);
		case '-':
			return (1);
		case '_':
			return (2);
		case '|':
			return (3);
		case '/':
			return (4);
		case '\\': //backslash (\) character
			return (5);
		case 'O':
			return (6);
		default:
			return (0);
		}
	}
