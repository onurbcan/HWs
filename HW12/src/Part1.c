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
 * Char		 Freq		Code
 * F		 1			10110101110
 * '		 1			10110101111
 * E		 1			10110101100
 * G		 1			10110101101
 * z		 1			00011110110
 * M		 1			00011110111
 * K		 1			0001111010
 * A		 2			000111100
 * x		 3			101101000
 * Y		 3			101101001
 * R		 3			101101010
 * I		 5			00011111
 * k		 7			11100010
 * g		 8			11100011
 * w		 9			0001110
 * \n		 10			1000000
 * T		 10			1000001
 * .		 13			1011011
 * ,		 13			1110000
 * v		 18			000110
 * b		 22			100001
 * f		 24			101100
 * m		 28			111001
 * p		 28			111010
 * c		 35			111011
 * l		 36			00010
 * y		 42			10001
 * h		 52			10111
 * u		 66			11110
 * d		 66			11111
 * s		 71			0000
 * a		 76			0010
 * n		 78			0011
 * o		 79			0110
 * i		 80			0111
 * r		 84			1001
 * t		 94			1010
 * e		 155		010
 *  		 230		110
 *
 * Message		Code
 * A			000111100
 * t			1010
 * a			0010
 * t			1010
 * u			11110
 * r			1001
 * k			11100010
 *
 * Encoded message
 * 00011110010100010101011110100111100010
 *
 * Decoded message
 * Ataturk
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
	struct huffmanCodingTree *tempRootHCT = rootHCT, *iterHCT = rootHCT;
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
//	i = 1;
//	while (1) {
//		if (iterHCT == NULL)
//			break;
//		printf("%d) %c:\t %d\n", i, iterHCT->letter, iterHCT->freq);
//		iterHCT = iterHCT->next;
//		++i;
//	}

	while (1) {
		count = 0;
		iterHCT = tempRootHCT;
		while (iterHCT != NULL) {
			++count;
			iterHCT = iterHCT->next;
		}
		if (count == 1) {
			break;
		} else if (count == 2) {
			iterHCT = tempRootHCT;
			tempAddress1 = iterHCT;
			tempAddress2 = iterHCT->next;
			sumFreq = tempAddress1->freq + tempAddress2->freq;
			newAddress = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
			newAddress->letter = 'X';
			newAddress->freq = sumFreq;
			newAddress->left = tempAddress1;
			newAddress->right = tempAddress2;
			newAddress->next = NULL;
			tempRootHCT = newAddress;
		} else {
			iterHCT = tempRootHCT;
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
			newAddress->left = tempAddress1;
			newAddress->right = tempAddress2;
			newAddress->next = iterHCT->next;

			if (iterHCT == tempAddress2) {
				tempRootHCT = newAddress;
			} else {
				if (iterHCT->next == NULL)
					newAddress->next = NULL; //if iter is the last one, thus newAddr will be new last one
				iterHCT->next = newAddress;
				tempRootHCT = tempAddress2->next;
			}
		}
		//this block prints all elements
		//if (iterHCT == NULL)
		//	break;
		//printf("%c:\t %d\n", iterHCT->letter, iterHCT->freq);
		//iterHCT = iterHCT->next;
	}
	//printf("count: %d, %d", count, rootHCT->freq);


	generateCodes(tempRootHCT, code, lastIndex);
//	printCodes(rootHCT);
	encodeMessage(rootHCT);
	decodeMessage(rootHCT);
	return;
}

void generateCodes(struct huffmanCodingTree *rootHCT, int code[], int lastIndex) {
	int i;
	if (rootHCT->left) {
		code[lastIndex] = 0;
		generateCodes(rootHCT->left, code, lastIndex + 1);
	}
	if (rootHCT->right) {
		code[lastIndex] = 1;
		generateCodes(rootHCT->right, code, lastIndex + 1);
	}
	//if the letter is other than 'X', then it is a leaf node
	//'X' represents upper tree nodes
	if (rootHCT->letter != 'X') {
		for (i = 0; i < lastIndex; ++i)
			rootHCT->code[i] = code[i];
		rootHCT->code[lastIndex] = ENDOFCODE;
	}
	return;
}

void printCodes(struct huffmanCodingTree *rootHCT) {
	int i;

	while (1) {
		if (rootHCT == NULL)
			break;
		else if (rootHCT->letter == 'X') {
			rootHCT = rootHCT->next;
			continue;
		}
		printf(" * %c\t\t %d\t\t\t", rootHCT->letter, rootHCT->freq);
		i = 0;
		while (rootHCT->code[i] != ENDOFCODE) {
			printf("%d", rootHCT->code[i]);
			++i;
		}
		printf("\n");
		rootHCT = rootHCT->next;
	}
	return;
}

void encodeMessage(struct huffmanCodingTree *rootHCT) {
	int i, iBuffer = 0;
	char c, *buffer;
	struct huffmanCodingTree *iterHCT = rootHCT;

	openFileRead("files/message.txt");
	openFileWriteBinary("files/encoded.bin");
	printf("Message characters and codes:\n");
	while (1) {
		c = getc(fptr);
		if (c == EOF)
			break;
		iterHCT = rootHCT;
		while (iterHCT->letter != c)
			iterHCT = iterHCT->next;
		printf("%c\t", iterHCT->letter);
		i = 0;
		while (iterHCT->code[i] != ENDOFCODE) {
			buffer = (char*)realloc(buffer, (iBuffer + 1) * sizeof(char));
			buffer[iBuffer] = iterHCT->code[i] + 48;
			printf("%c", iterHCT->code[i] + 48);
			++iBuffer;
			++i;
		}
		printf("\n");
	}
	printf("\nEncoded message:\n");
	for (i = 0; i < iBuffer; ++i)
		printf("%c", buffer[i]);
	printf("\n");
	fwrite(buffer, sizeof(char), iBuffer, fptwb);
	closeFile(fptr);
	closeFile(fptwb);
	return;
}

void decodeMessage(struct huffmanCodingTree *rootHCT) {
	char c;
	openFileRead("files/encoded.bin");
	while (1) {
		c = getc(fptr);
		if (c == EOF)
			break;
		printf("%d", c - 48);
	}
	closeFile(fptr);
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

/** 5.5) Open file write binary
 * Opens the file to be written as binary using the address and file name
 * (together with file type) in the parameter path. */
void openFileWriteBinary(char *filePath) {
	if ((fptwb = fopen(filePath, "wb")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}
