/*
 * Part1.c
 * Description: We were sniffing enemies’ communications, and finally one of our
 * agents capture a folder which contains many files. The files consist of
 * numbers from 0 to 6 and mean nothing in this form but we know there are
 * classified messages in these files, and we need you to decrypt and visualize
 * the files for reading that messages. After perform much effort on the file,
 * our experts notice that the numbers represents some characters such as
 * 0, 1, 2, 3, 4, 5, 6 are ‘ ’, ‘-’, ‘_’, ‘|’, ‘/’, ‘\’, ‘O‘ respectively (The
 * first character is space character). You are asked to write a function that
 * reads such files, decrypt them and visualize the secret messages in these
 * files. Use encrypted_p1.img file to test your decryption function. The
 * function prototype has given below:
 *
 * void decrypt_and_print (char* file_path)
 *
 * Use a helper function for decryption of characters and do it with switch –
 * case structure.
 *
 * char decrypt_numbers (int number)
 *
 *  Created on: Mar 19, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

void open_file_write() {
	if ((fptw = fopen("output.txt", "w")) == NULL) {
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

void decrypt_and_print(char *file_path) {
	int num;
	open_file_read(file_path); //fptr file pointer read
	open_file_write(); //fptw file pointer write
	while (1) {
		num = fgetc(fptr);
		fprintf(fptw, "%c", decrypt_numbers(num));
		if (feof(fptr)) {
			close_file(fptr);
			close_file(fptw);
			return;
		} else if (num == '\n') {
			fprintf(fptw, "\n");
		}
	}
	return;
}

char decrypt_numbers(int number) {
	switch (number) {
	case ZERO:
		return (' ');
	case ONE:
		return ('-');
	case TWO:
		return ('_');
	case THREE:
		return ('|');
	case FOUR:
		return ('/');
	case FIVE:
		return ('\\'); //prints backslash (\) character
	case SIX:
		return ('0');
	default:
		return (' ');
	}
	return (' ');
}
