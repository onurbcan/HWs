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
	/*
	char c[1000];
	if((fptr = fopen("files/encrypted_p1.img", "r")) == NULL){
		printf("Error on opening file");
	}

	//open_file();
	fscanf(fptr, "%[^\n]", c);
	printf("%s",c);
	fclose(fptr);
*/
	puts("Process completed!");
	return EXIT_SUCCESS;
}
