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
	int i, j, tempFreq, iItem = 0, iItemTemp, nItem, isSame, *allCharFreqs = 0;
	int count, sumFreq, code[MAXTREESTEPS], lastIndex = 0;
	char c, tempItem, *allCharItems = 0;

	struct huffmanCodingTree *rootHCT = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
	struct huffmanCodingTree *iterHCT = rootHCT;
	struct huffmanCodingTree *tempAddress1, *tempAddress2, *newAddress;

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
		iterHCT->code = 0;
		iterHCT->left = NULL;
		iterHCT->right = NULL;
		++i;
		if (i == nItem) {
			iterHCT->next = NULL;
			break;
		} else {
			iterHCT->next = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
			iterHCT = iterHCT->next;
		}
	}
//	iterHCT = rootHCT;
//	while (1) {
//		if (iterHCT == NULL)
//			break;
//		printf("%c:\t %d\n", iterHCT->letter, iterHCT->freq);
//		iterHCT = iterHCT->next;
//	}


	while (1) {
		count = 0;
		iterHCT = rootHCT;
		while (iterHCT != NULL) {
			++count;
			iterHCT = iterHCT->next;
		}
		if (count == 1) {
			break;
		} else if (count == 2) {
			iterHCT = rootHCT;
			tempAddress1 = iterHCT;
			tempAddress2 = iterHCT->next;
			sumFreq = tempAddress1->freq + tempAddress2->freq;
			newAddress = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
			newAddress->letter = 'X';
			newAddress->freq = sumFreq;
			newAddress->code = 0;
			newAddress->left = tempAddress1;
			newAddress->right = tempAddress2;
			newAddress->next = NULL;
			rootHCT = newAddress;
		} else {
			iterHCT = rootHCT;
			tempAddress1 = iterHCT;
			tempAddress2 = iterHCT->next;
			sumFreq = tempAddress1->freq + tempAddress2->freq;
			while (1) {
				if (iterHCT->next == NULL)
					break;
				else if (iterHCT->next->freq >= sumFreq)
					break;
				iterHCT = iterHCT->next;
			}
			newAddress = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
			newAddress->letter = 'X'; //'X' represents upper tree nodes
			newAddress->freq = sumFreq;
			newAddress->code = 0;
			newAddress->left = tempAddress1;
			newAddress->right = tempAddress2;
			newAddress->next = iterHCT->next;

			if (iterHCT == tempAddress2) {
				rootHCT = newAddress;
			} else {
				if (iterHCT->next == NULL)
					newAddress->next = NULL; //if iter is the last one, thus newAddr will be new last one
				iterHCT->next = newAddress;
				rootHCT = tempAddress2->next;
			}
			tempAddress1->next = NULL;
			tempAddress2->next = NULL;
		}
		//this block prints all elements
		//if (iterHCT == NULL)
		//	break;
		//printf("%c:\t %d\n", iterHCT->letter, iterHCT->freq);
		//iterHCT = iterHCT->next;
	}
	//printf("count: %d, %d", count, rootHCT->freq);


	printCodes(rootHCT, code, lastIndex);
	return;
}

void printCodes(struct huffmanCodingTree *root, int code[], int lastIndex) {
	int i;
	if (root->left) {
		code[lastIndex] = 0;
		printCodes(root->left, code, lastIndex + 1);
	}
	if (root->right) {
		code[lastIndex] = 1;
		printCodes(root->right, code, lastIndex + 1);
	}
	//if the letter is other than 'X', then it is a leaf node
	//'X' represents upper tree nodes
	if (root->letter != 'X') {
		printf("%c\t", root->letter);
		for (i = 0; i < lastIndex; ++i)
			printf("%d", code[i]);
		printf("\n");
	}
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
