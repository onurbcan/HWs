/*
 ============================================================================
 Name        : HW12.c
 Author      : Onur
 Version     :
 Copyright   : 
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

int main(int argc, char **argv) {
	huffmanCoding(argv[1]);

//	unsigned char buffer[6];
//	openFileReadBinary("files/encoded.bin");
//	fread(buffer, 1, 6, fptrb);
//	closeFile(fptrb);
//	for (int i = 0; i < 6; ++i)
//		printf("%d ", buffer[i]);


//	unsigned char c;
//	openFileRead("files/encoded.bin");
//	while (1) {
//		c = getc(fptr);
//		if (feof(fptr) == 1)
//			break;
//		printf("%d ", c);
//	}
//	closeFile(fptr);


////	int binNm = 0x1D;
////	int binNm2 = 0xFF;
//	int binNm = 255;
//	openFileWriteBinary("files/encoded.bin");
//	fwrite(&binNm, 1, 1, fptwb);
////	fwrite(&binNm2, 1, 1, fptwb);
//	closeFile(fptwb);


	return EXIT_SUCCESS;
}
