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
#include "Part2.h"
#include "Part3.h"
#include "Part4.h"
#include "Part5.h"

int main(int argc, char **argv) {
	decrypt_and_print(argv[1]);
	deep_decrypt_and_print(argv[2]);
	track_machine();
	encrypt_messages (argv[3]);
	menu();
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
