/*
 * Part1.h
 *
 *  Created on: Jun 20, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define upperCaseIndexDifference 65
#define lowerCaseIndexDifference 71

enum someLetters {letterA = 65, letterZ = 90, lettera = 97, letterz = 122};

enum letters {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V,
		W, X, Y, Z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t,
		u, v, w, x,	y, z};

struct huffmanCodingTree {
	char letter;
	int freq;
	int code;
	struct huffmanCodingTree *left, *right;
};

/*! File pointer to read the file */
FILE *fptr; //fptr file pointer read
/*! File pointer to write the file */
FILE *fptw; //fptw file pointer write
/*! File pointer to edit the file */
FILE *fpte; //fptw file pointer edit

void huffmanCoding(char *file_path);
void huffmanCoding2(char *file_path);

void openFileRead(char *filePath);
void openFileWrite(char *filePath);
void openFileEdit(char *filePath);
void closeFile(FILE *filePointer);



#endif /* INC_PART1_H_ */
