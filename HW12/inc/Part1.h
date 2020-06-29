/*
 * Part1.h
 *
 *  Created on: Jun 20, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define MAXTREESTEPS 20 //or max length of the code
#define ENDOFCODE -1
#define CHARINTDIFFERENCE 48
#define MAXFILEPATHLENGTH 50

#define LASTELEMENT 0
#define BASE2 2
#define QUATERNARY 4
#define ONEBYTE 8
#define HEXA 10
#define HEXB 11
#define HEXC 12
#define HEXD 13
#define HEXE 14
#define HEXF 15

/*! File pointer to read the file */
FILE *fptr; //fptr file pointer read
/*! File pointer to write the file */
FILE *fptw; //fptw file pointer write
/*! File pointer to edit the file */
FILE *fpte; //fptw file pointer edit
/*! File pointer to write binary file */
FILE *fptwb; //fptwb file pointer write binary
/*! File pointer to read binary file */
FILE *fptrb; //fptr file pointer read binary

enum menuChoices {QUIT = 0, PRINT = 1, ENCODE = 2, DECODE = 3};
enum HCTElements {LASTONE = 1, LASTTWO = 2};

struct huffmanCodingTree {
	char letter;
	int freq;
	int code[MAXTREESTEPS];
	struct huffmanCodingTree *next;
	struct huffmanCodingTree *left, *right;
};

void huffmanCodingTree(char *file_path);
void generateCodes(struct huffmanCodingTree *rootHCT, int code[], int lastIndex, int *longestCode);
void huffmanCodingTreeMenu(struct huffmanCodingTree *rootHCT, int longestCode);
void printCodes(struct huffmanCodingTree *rootHCT);
void encodeMessage(struct huffmanCodingTree *rootHCT);
void writeToFileInBytes(int *binNums, int nbinNums);
void decodeMessage(struct huffmanCodingTree *rootHCT, int longestCode);
int* readFromFileInBytes(int *nBinNums);

void binHexConverter(int *binNums, int nBinNums, char *hexNums, int *nHexNums);
void hexBinConverter(char *hexNums, int nHexNums, int *binNums, int *nBinNums);

void openFileRead(char *filePath);
void openFileWrite(char *filePath);
void openFileEdit(char *filePath);
void closeFile(FILE *filePointer);
void openFileReadBinary(char *filePath);
void openFileWriteBinary(char *filePath);

#endif /* INC_PART1_H_ */
