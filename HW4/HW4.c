/*
 ============================================================================
 Name        : HW4.c
 Author      : Onur
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

int main(int argc, char **argv) {
	decrypt_and_print(argv[1]);

	puts("Process completed!");
	return EXIT_SUCCESS;
}
