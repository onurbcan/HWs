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

int main(void) {
	char c[1000];
	//decrypt_and_print();
	FILE *fptr;
	if((fptr = fopen("encrypted_p1.img", "r")) == NULL){
		printf("Error on opening file");
	}
	fscanf(fptr, "%[^\n]", c);
	printf("%s",c);
	fclose(fptr);

	puts("Process completed!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
