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

enum letters {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V,
		W, X, Y, Z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t,
		u, v, w, x,	y, z};

struct huffmanCodingTree {
	char letter;
	int freq;
	int code[MAXTREESTEPS];
	struct huffmanCodingTree *next;
	struct huffmanCodingTree *left, *right;
};

/*! File pointer to read the file */
FILE *fptr; //fptr file pointer read
/*! File pointer to write the file */
FILE *fptw; //fptw file pointer write
/*! File pointer to edit the file */
FILE *fpte; //fptw file pointer edit
/*! File pointer to write binary file */
FILE *fptwb; //fptwb file pointer write binary

void huffmanCoding(char *file_path);
void generateCodes(struct huffmanCodingTree *rootHCT, int code[], int lastIndex, int *longestCode);
void printCodes(struct huffmanCodingTree *rootHCT);
void encodeMessage(struct huffmanCodingTree *rootHCT);
void decodeMessage(struct huffmanCodingTree *rootHCT, int longestCode);

void openFileRead(char *filePath);
void openFileWrite(char *filePath);
void openFileEdit(char *filePath);
void closeFile(FILE *filePointer);
void openFileWriteBinary(char *filePath);



#endif /* INC_PART1_H_ */
