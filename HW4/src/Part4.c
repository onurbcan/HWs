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
	char character;
	open_file_read(file_path); //fptr file pointer read
	open_file_write("encrypted_p4.img"); //fptw file pointer write
	while (!feof(fptr)) {
		character = fgetc(fptr);
		fprintf(fptw, "%d", encrypt_characters(character));
		if (character == '\n') {
			fprintf(fptw, "\n");
		}
	}
	close_file(fptr);
	close_file(fptw);

	open_file_read("encrypted_p4.img"); //fptr file pointer read

	return;
}

int encrypt_characters(char character) {
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
	default:
		return (0);
	}
}
