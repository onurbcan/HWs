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
 * Huffman coding tree. What is expected to be done within the scope of the
 * assignment is explained below:
 * 1. Taking a text file (reference.txt) as input, creating the Huffman coding
 * tree and encrypting each character
 * 2. Encrypting a text requested from the user with character codes created
 * from the coding tree and writing it in a .dat file (encoded.dat)
 * 3. To decode the binary array in encoded.dat and write it to decoded.txt.
 * 4. Calculation of the file size difference between encryption (encoded.dat)
 * and decryption (decoded.txt).
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

void huffmanCodingTree(char *filePath) {
	int i, j, tempFreq, iItem = 0, iItemTemp, nItem, isSame, *allCharFreqs = 0;
	int sumFreq, code[MAXTREESTEPS], lastIndex = 0, longestCode = 0;
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
	while (1) {
		iItem = 0;
		iterHCT = tempRootHCT;
		while (iterHCT != NULL) {
			++iItem;
			iterHCT = iterHCT->next;
		}
		if (iItem == LASTONE) {
			break;
		} else if (iItem == LASTTWO) {
			iterHCT = tempRootHCT;
			tempAddress1 = iterHCT;
			tempAddress2 = iterHCT->next;
			sumFreq = tempAddress1->freq + tempAddress2->freq;
			newAddress = (struct huffmanCodingTree*)malloc(sizeof(struct huffmanCodingTree));
			newAddress->letter = '?';
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
			newAddress->letter = '?'; //'?' represents upper tree nodes
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
	}
	generateCodes(tempRootHCT, code, lastIndex, &longestCode);
	huffmanCodingTreeMenu(rootHCT, longestCode);
	return;
}

void generateCodes(struct huffmanCodingTree *rootHCT, int code[], int lastIndex, int *longestCode) {
	int i;

	if (rootHCT->left) {
		code[lastIndex] = 0;
		generateCodes(rootHCT->left, code, lastIndex + 1, longestCode);
	}
	if (rootHCT->right) {
		code[lastIndex] = 1;
		generateCodes(rootHCT->right, code, lastIndex + 1, longestCode);
	}
	//if the letter is other than '?', then it is a leaf node
	//'?' represents upper tree nodes
	if (rootHCT->letter != '?') {
		for (i = 0; i < lastIndex; ++i)
			rootHCT->code[i] = code[i];
		rootHCT->code[lastIndex] = ENDOFCODE;
		if (lastIndex > *longestCode)
			*longestCode = lastIndex;
	}
	return;
}

void huffmanCodingTreeMenu(struct huffmanCodingTree *rootHCT, int longestCode) {
	int menuChoice;

	system("clear");
	printf("Welcome to the Huffman Coding algorithm encryption and decryption methods.\n");
	do {
		printf("\nPlease choose the operation using the below menu\n");
		printf("1) Print generated codes for each character of the reference text\n");
		printf("2) Encode message and save .dat file\n");
		printf("3) Decode message using .dat file\n");
		printf("0) Quit\n");
		scanf("%d", &menuChoice);
		system("clear");
		switch (menuChoice) {
		case QUIT:
			printf("Good bye!");
			break;
		case PRINT:
			printCodes(rootHCT);
			break;
		case ENCODE:
			encodeMessage(rootHCT);
			break;
		case DECODE:
			decodeMessage(rootHCT, longestCode);
			break;
		default:
			printf("Error occurred! %d is an invalid choice. Please try again.\n", menuChoice);
			break;
		}
		while (getchar() != '\n');
	} while (menuChoice != QUIT);
}

void printCodes(struct huffmanCodingTree *rootHCT) {
	int i, iCode = 1;

	while (1) {
		if (rootHCT == NULL)
			break;
		else if (rootHCT->letter == '?') {
			rootHCT = rootHCT->next;
			continue;
		}
		printf("%2d) %c\t %3d\t", iCode, rootHCT->letter, rootHCT->freq);
		i = 0;
		while (rootHCT->code[i] != ENDOFCODE) {
			printf("%d", rootHCT->code[i]);
			++i;
		}
		printf("\n");
		++iCode;
		rootHCT = rootHCT->next;
	}
	return;
}

void encodeMessage(struct huffmanCodingTree *rootHCT) {
	int i, iBinNums = 0, nBinNums;
	int *binNums = 0;
	char c, filePath[MAXFILEPATHLENGTH];
	struct huffmanCodingTree *iterHCT = rootHCT;

	printf("Please enter the file path for the message to be encoded.\n");
	printf("for e.g: message.txt\n");
	scanf("%s", filePath);
	openFileRead(filePath);
	printf("Message characters and related codes:\n");
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
			binNums = (int*)realloc(binNums, (iBinNums + 1) * sizeof(int));
			binNums[iBinNums] = iterHCT->code[i];
			printf("%d", iterHCT->code[i]);
			++iBinNums;
			++i;
		}
		printf("\n");
	}
	nBinNums = iBinNums;
	closeFile(fptr);
	printf("\nEncoded message to be saved in the .dat file:\n");
	for (i = 0; i < nBinNums; ++i)
		printf("%d", binNums[i]);
	printf("\n\n");
	writeToFileInBytes(binNums, nBinNums);
	return;
}

void writeToFileInBytes(int *binNums, int nBinNums) {
	int i, j, last, first, *decNums = 0, iDecNum = 0, nDecNum, tempDecNum;
	int toPowerOf2;
	int nMissingBits = (ONEBYTE - (nBinNums % ONEBYTE)) % ONEBYTE;
	char filePath[MAXFILEPATHLENGTH];

	if (nBinNums >= ONEBYTE) {
		last = nBinNums - 1;
		first = nBinNums - ONEBYTE;
	} else {
		last = nBinNums - 1;
		first = LASTELEMENT;
	}
	while (1) {
		decNums = (int*)realloc(decNums, (iDecNum + 1) * sizeof(int));
		decNums[iDecNum] = 0;
		for (i = last; i >= first; --i) {
			toPowerOf2 = 1;
			for (j = last; j > i; --j)
				toPowerOf2 *= BASE2;
			decNums[iDecNum] += toPowerOf2 * binNums[i];
		}
		++iDecNum;
		if (first == LASTELEMENT) {
			break;
		} else if ((first - ONEBYTE) >= LASTELEMENT) {
			last = last - ONEBYTE;
			first = first - ONEBYTE;
		} else {
			last = last - ONEBYTE;
			first = LASTELEMENT;
		}
	}
	nDecNum = iDecNum;
	//sorts elements last to first, since upper loop starts from the end
	for (i = 0; i < nDecNum / 2; ++i) {
		tempDecNum = decNums[i];
		decNums[i] = decNums[(nDecNum - 1) - i];
		decNums[(nDecNum - 1) - i] = tempDecNum;
	}
	printf("Please enter the file path for the encoded message to be saved.\n");
	printf("for e.g: encoded.dat\n");
	scanf("%s", filePath);
	openFileWriteBinary(filePath);
	//writes to file initially the padding info byte
	fwrite(&nMissingBits, 1, 1, fptwb);
	//writes to file the binary data, 1B each time
	for (i = 0; i < nDecNum; ++i)
		fwrite(&decNums[i], 1, 1, fptwb);
	closeFile(fptwb);
	printf("Encoded file saved successfully.\n");
	return;
}

void decodeMessage(struct huffmanCodingTree *rootHCT, int longestCode) {
	int i, iCode, tempCode[longestCode], isSame, chosenLetterLength, isEOF = 0;
	int *binNums, iBinNums = 0, nBinNums;
	char chosenLetter, filePath[MAXFILEPATHLENGTH];
	struct huffmanCodingTree *iterHCT = rootHCT;

	binNums = readFromFileInBytes(&nBinNums);
	printf("Encoded message that was read from the .dat file:\n");
	for (i = 0; i < nBinNums; ++i)
		printf("%d", binNums[i]);
	printf("\n\n");
	printf("Please enter the file path for the decoded message to be saved.\n");
	printf("for e.g: decoded.txt\n");
	scanf("%s", filePath);
	openFileWrite(filePath);
	printf("Decoded file saved successfully.\n");
	printf("\nDecoded message:\n");
	iCode = 0;
	while (1) {
		if (iBinNums == nBinNums)
			isEOF = 1;
		else
			tempCode[iCode] = binNums[iBinNums];
		iterHCT = rootHCT;
		while (iterHCT != NULL) {
			if (iterHCT->letter == '?') {
				iterHCT = iterHCT->next;
				continue;
			}
			isSame = 1;
			for (i = 0; i < iCode + 1; ++i) {
				if (tempCode[i] != iterHCT->code[i]) {
					isSame = 0;
					break;
				}
			}
			if (isSame) {
				chosenLetter = iterHCT->letter;
				chosenLetterLength = i;
			}
			iterHCT = iterHCT->next;
		}
		//compares codes either up to longest code (in this case 11) or if EOF obtained
		if (iCode == longestCode || isEOF) {
			printf("%c", chosenLetter);
			fprintf(fptw, "%c", chosenLetter);
			iCode = -1; //to set the index iterator to 0 for the next loop iteration
			iBinNums = iBinNums + (chosenLetterLength - longestCode - 1);
		}
		if (isEOF)
			break;
		++iBinNums;
		++iCode;
	}
	closeFile(fptw);
	return;
}

int* readFromFileInBytes(int *nBinNums) {
	int j, k, nMissingBits, *binNums = 0, iBinNums = 0, binMultiplier;
	int decNum;
	char filePath[MAXFILEPATHLENGTH];

	printf("Please enter the file path for the encoded message to be read.\n");
	printf("for e.g: encoded.dat\n");
	scanf("%s", filePath);
	openFileReadBinary(filePath);
	nMissingBits = getc(fptrb); //gets initially the padding information
	while (1) {
		decNum = getc(fptrb);
		if (feof(fptrb) == 1)
			break;
		for (j = ONEBYTE; j > 0; --j) {
			binMultiplier = 1;
			for (k = 0; k < j - 1; ++k)
				binMultiplier *= BASE2;
			//removes padding bits
			if (nMissingBits > 0) {
				--nMissingBits;
				continue;
			}
			binNums = (int*)realloc(binNums, (iBinNums + 1) * sizeof(int));
			if ((decNum / binMultiplier) >= 1) {
				binNums[iBinNums] = 1;
				decNum = decNum % binMultiplier;
			} else  {
				binNums[iBinNums] = 0;
			}
			++iBinNums;
		}
	}
	closeFile(fptrb);
	*nBinNums = iBinNums;
	return binNums;
}

void binHexConverter(int *binNums, int nBinNums, char *hexNums, int *nHexNums) {
	int i, j, ihexNums = 0, hexNum, last, first, toPowerOf2;
	char tempHexNum;

	if (nBinNums >= QUATERNARY) {
		last = nBinNums - 1;
		first = nBinNums - QUATERNARY;
	} else {
		last = nBinNums - 1;
		first = LASTELEMENT;
	}

	while (1) {
		hexNum = 0;
		for (i = last; i >= first; --i) {
			toPowerOf2 = 1;
			for (j = last; j > i; --j)
				toPowerOf2 *= BASE2;
			hexNum += toPowerOf2 * binNums[i];
		}
		hexNums = (char*)realloc(hexNums, (ihexNums + 1) * sizeof(char));
		switch (hexNum) {
		case HEXA:
			hexNums[ihexNums] = 'A';
			break;
		case HEXB:
			hexNums[ihexNums] = 'B';
			break;
		case HEXC:
			hexNums[ihexNums] = 'C';
			break;
		case HEXD:
			hexNums[ihexNums] = 'D';
			break;
		case HEXE:
			hexNums[ihexNums] = 'E';
			break;
		case HEXF:
			hexNums[ihexNums] = 'F';
			break;
		default:
			hexNums[ihexNums] = hexNum + CHARINTDIFFERENCE;
			break;
		}

		if (first == LASTELEMENT) {
			break;
		} else if ((first - QUATERNARY) >= LASTELEMENT) {
			last = last - QUATERNARY;
			first = first - QUATERNARY;
		} else {
			last = last - QUATERNARY;
			first = LASTELEMENT;
		}
		++ihexNums;
	}
	*nHexNums = ihexNums + 1;
	for (i = 0; i < *nHexNums / 2; ++i) {
		tempHexNum = hexNums[i];
		hexNums[i] = hexNums[(*nHexNums - 1) - i];
		hexNums[(*nHexNums - 1) - i] = tempHexNum;
	}
	return;
}

void hexBinConverter(char *hexNums, int nHexNums, int *binNums, int *nBinNums) {
	int i, j, k, decNum, binMultiplier, iBinNums = 0;

	for (i = 0; i < nHexNums; ++i) {
		switch (hexNums[i]) {
		case 'A':
			decNum = HEXA;
			break;
		case 'B':
			decNum = HEXB;
			break;
		case 'C':
			decNum = HEXC;
			break;
		case 'D':
			decNum = HEXD;
			break;
		case 'E':
			decNum = HEXE;
			break;
		case 'F':
			decNum = HEXF;
			break;
		default:
			decNum = hexNums[i] - CHARINTDIFFERENCE;
			break;
		}
		for (j = QUATERNARY; j > 0; --j) {
			binMultiplier = 1;
			for (k = 0; k < j - 1; ++k)
				binMultiplier *= BASE2;
			binNums = (int*)realloc(binNums, (iBinNums + 1) * sizeof(int));
			if ((decNum / binMultiplier) >= 1) {
				binNums[iBinNums] = 1;
				decNum = decNum % binMultiplier;
			} else  {
				binNums[iBinNums] = 0;
			}
			++iBinNums;
		}
	}
	*nBinNums = iBinNums;
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

/** 5.5) Open file read binary
 * Opens the file to be written as binary using the address and file name
 * (together with file type) in the parameter path. */
void openFileReadBinary(char *filePath) {
	if ((fptrb = fopen(filePath, "rb")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

/** 5.6) Open file write binary
 * Opens the file to be written as binary using the address and file name
 * (together with file type) in the parameter path. */
void openFileWriteBinary(char *filePath) {
	if ((fptwb = fopen(filePath, "wb")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}
