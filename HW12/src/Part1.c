/*
 * Part1.c
 *
 *  Created on: Jun 20, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

void huffmanCoding(char *filePath) {
	int i = 0, *allLettersFreq = (int*)malloc(52 * sizeof(int));
	int iterLetter = letterA;
	char c, *allLetters = (char*)malloc(52 * sizeof(char));

	openFileRead(filePath);
	while (1) {
		c = getc(fptr);
		if (c == EOF)
			break;
		else if (letterA <= c && c <= letterZ)
			i = (int)c - upperCaseIndexDifference;
		else if (lettera <= c && c <= letterz)
			i = (int)c - lowerCaseIndexDifference;
		else
			continue;
		allLetters[i] = (char)c;
		++allLettersFreq[i];
	}
	closeFile(fptr);

//	for (i = 0; i < 52; ++i)
//		printf("%d:\t %d\n", i, allLettersFreq[i]);

	struct huffmanCodingTree *rootHCT = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
	struct huffmanCodingTree *iterHCT = rootHCT;

	i = 0;
	while (1) {
		if (allLettersFreq[i] == 0) {
			++i;
			continue;
		}
		iterHCT->letter = allLetters[i];
		iterHCT->freq = allLettersFreq[i];
		++i;
		if (i == 52)
			break;
		if (i == 26)
			iterLetter = iterLetter + 7;
		else
			++iterLetter;

		iterHCT->right = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
		iterHCT = iterHCT->right;
	}
	iterHCT = NULL;

	iterHCT = rootHCT;
	while (iterHCT != NULL) {
		printf("%c:\t %d\n", iterHCT->letter, iterHCT->freq);
		iterHCT = iterHCT->right;
	}


//	char c[30] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
//	char d[30] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
//	while (d[i] != 'z') {
//		printf("%c, ", d[i] - 32);
//		++i;
//	}
//	printf("\n%d", i);

//	char *c = (char*)malloc((i + 1) * sizeof(char));
//
//	openFileRead(filePath);
//
//	c[i] = getc(fptr);
//	while (c[i] != EOF) {
//		++i;
//		c = (char*)realloc(c, (i + 1) * sizeof(char));
//		c[i] = getc(fptr);
//	}
//
//	i = 0;
//	while (c[i] != EOF) {
//		printf("%c", c[i]);
//		++i;
//	}
//
//	closeFile(fptr);
	return;
}


/** 5.1) Open file read
 * Opens the file to be read using the address and file name (together with
 * file type) in the parameter path.*/
void openFileRead(char *filePath) {
	if ((fptr = fopen(filePath, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

/** 5.2) Open file write
 * Opens the file to be written using the address and file name (together with
 * file type) in the parameter path. */
void openFileWrite(char *filePath) {
	if ((fptw = fopen(filePath, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

/** 5.3) Open file edit
 * Opens the file to be edited using the address and file name (together with
 * file type) in the parameter path. */
void openFileEdit(char *filePath) {
	if ((fpte = fopen(filePath, "a+")) == NULL) {
		printf("Error! File not edited.");
		exit(1);
	}
	return;
}

/** 5.4) Close file
 * Closes the file using the file pointer in the parameter. */
void closeFile(FILE *filePointer) {
	if (fclose(filePointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}
