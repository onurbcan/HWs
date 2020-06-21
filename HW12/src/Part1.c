/*
 * Part1.c
 * Description: Huffman is a coding method used to compress data without loss in
 * computer science. One of the biggest advantages of Huffman coding is that it
 * makes an encoding according to the frequencies of the characters used, so
 * that the frequently used characters take up less space.
 * Huffman encoding initially takes a large text as input, containing all the
 * characters to be used later, if possible. The frequencies of the characters
 * included in this large text (frequency of passing in the text) will determine
 * the structure of the binary tree to be created. There are "characters" in the
 * leaves of this binary tree, which is created by using the frequencies of the
 * characters. During the movement from root to leaves (i.e. characters), codes
 * of characters will be obtained when each left branch is referenced with the
 * bit '0' and each right branch with the bit '1'.
 * The frequency of a character also refers to the level of compression. The
 * more frequently a character is used, the fewer bits can be expressed in the
 * Huffman coding tree. What is expected to be done within the scope of homework
 * is explained below:
 * 1. Taking a text file (reference.txt) as input, creating the Huffman coding
 * tree and encrypting each character [40pts]
 * 2. Encrypting a text requested from the user with character codes created
 * from the coding tree and writing it in a .dat file (encoded.dat) [20pts]
 * 3. To decode the binary array in encoded.dat and write it to decoded.txt.
 * [20pts]
 * 4. Calculation of the file size difference between encryption (encoded.dat)
 * and decryption (decoded.txt). [20pts]
 * You can use the resources below for a detailed explanation of Huffman Coding:
 * Simulation: https://people.ok.ubc.ca/ylucet/DS/Huffman.html
 * Detailed description: https://www.studytonight.com/data-structures/huffman-coding
 *
 *  Created on: Jun 20, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

void huffmanCoding(char *filePath) {
	int i, j, tempFreq, iItem = 0, iItemTemp, nItem, count;
	int isSame;
	int *allCharFreqs = 0;
	char c, tempItem, *allCharItems = 0;

	struct huffmanCodingTree *rootHCT = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
	rootHCT->left = NULL;
	struct huffmanCodingTree *iterHCT = rootHCT;

	openFileRead(filePath);
	while (1) {
		c = getc(fptr);
		if (c == EOF)
			break;
		iItemTemp = iItem - 1;
		isSame = 0;
		while (iItemTemp >= 0 && iItem != 0) {
			if (allCharItems[iItemTemp] == c) {
				isSame = 1;
				break;
			}
			--iItemTemp;
		}
		if (!isSame) {
			allCharItems = (char*)realloc(allCharItems, (iItem + 1) * sizeof(char));
			allCharFreqs = (int*)realloc(allCharFreqs, (iItem + 1) * sizeof(int));
			allCharItems[iItem] = c;
			allCharFreqs[iItem] = 1;
			++iItem;
		} else {
			++allCharFreqs[iItemTemp];
		}
	}
	closeFile(fptr);

	nItem = iItem;
	for (i = 0; i < nItem - 1; ++i) {
		for (j = i + 1; j < nItem; ++j) {
			if (allCharFreqs[i] > allCharFreqs[j]) {
				tempFreq = allCharFreqs[i];
				allCharFreqs[i] = allCharFreqs[j];
				allCharFreqs[j] = tempFreq;

				tempItem = allCharItems[i];
				allCharItems[i] = allCharItems[j];
				allCharItems[j] = tempItem;
			}
		}
	}
	i = 0;
	while (1) {
		iterHCT->letter = allCharItems[i];
		iterHCT->freq = allCharFreqs[i];
		++i;
		if (i == nItem) {
			iterHCT->right = NULL;
			break;
		} else {
			iterHCT->right = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
			iterHCT->right->left = iterHCT;
			iterHCT = iterHCT->right;
		}
	}
	iterHCT = rootHCT;

	while (1) {
		count = 0;
		iterHCT = rootHCT;
		while (iterHCT != NULL) {
			++count;
			iterHCT = iterHCT->right;
		}
		if (count == 1)
			break;

		iterHCT = rootHCT;

	}
	printf("count: %d", count);

	//printf("%c:\t %d\n", iterHCT->letter, iterHCT->freq);
//	--iItem;
//	while (1) {
//		if (iItem == -1)
//			break;
//
//		printf("%c: \t %d\n", allCharItems[iItem], allCharFreqs[iItem]);
//		--iItem;
//	}




	free(allCharItems);
	free(allCharFreqs);
	return;
}

//void huffmanCoding2(char *filePath) {
//	int i = 0, *allLettersFreq = (int*)malloc(52 * sizeof(int));
//	int iterLetter = letterA;
//	char c, *allLetters = (char*)malloc(52 * sizeof(char));
//
//	openFileRead(filePath);
//	while (1) {
//		c = getc(fptr);
//		if (c == EOF)
//			break;
//		else if (letterA <= c && c <= letterZ)
//			i = (int)c - upperCaseIndexDifference;
//		else if (lettera <= c && c <= letterz)
//			i = (int)c - lowerCaseIndexDifference;
//		else
//			continue;
//		allLetters[i] = (char)c;
//		++allLettersFreq[i];
//	}
//	closeFile(fptr);
//
////	for (i = 0; i < 52; ++i)
////		printf("%d:\t %d\n", i, allLettersFreq[i]);
//
//	struct huffmanCodingTree *rootHCT = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
//	rootHCT->left = NULL;
//	struct huffmanCodingTree *iterHCT = rootHCT;
//
//	i = 0;
//	while (1) {
//		if (allLettersFreq[i] == 0) {
//			++i;
//			continue;
//		}
//		iterHCT->letter = allLetters[i];
//		iterHCT->freq = allLettersFreq[i];
//		++i;
//		if (i == 52)
//			break;
//		if (i == 26)
//			iterLetter = iterLetter + 7;
//		else
//			++iterLetter;
//
//		iterHCT->right = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
//		iterHCT->right->left = iterHCT;
//		iterHCT = iterHCT->right;
//	}
//	//iterHCT = NULL;
//
//	//iterHCT = rootHCT;
//	while (iterHCT != NULL) {
//		printf("%c:\t %d\n", iterHCT->letter, iterHCT->freq);
//		iterHCT = iterHCT->left;
//	}
//
//
////	char c[30] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
////	char d[30] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
////	while (d[i] != 'z') {
////		printf("%c, ", d[i] - 32);
////		++i;
////	}
////	printf("\n%d", i);
//
////	char *c = (char*)malloc((i + 1) * sizeof(char));
////
////	openFileRead(filePath);
////
////	c[i] = getc(fptr);
////	while (c[i] != EOF) {
////		++i;
////		c = (char*)realloc(c, (i + 1) * sizeof(char));
////		c[i] = getc(fptr);
////	}
////
////	i = 0;
////	while (c[i] != EOF) {
////		printf("%c", c[i]);
////		++i;
////	}
////
////	closeFile(fptr);
//	return;
//}


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
