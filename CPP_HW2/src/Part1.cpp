/*
 * Part1.c
 *
 *  Created on: May 23, 2020
 *      Author: onur
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "Part1.h"
using namespace std;

void n_puzzle_game_v2() {
	srand(time(nullptr));
//	string line;
//	get_from_file(line);
//	save_to_file(line);

	int *num;
	num = get_from_file("files/sample2.txt");
	for (int i = 0; num[i] != -1; ++i) {
		cout << i << ": " << num[i] << endl;
	}

//	int n = 3, *num = (int*)malloc(sizeof(int));
//	generate_table(num, n);
//	print_table(num, n);
//	save_to_file(num, "files/sample2.txt");
	return;
}

void convert_command(char c, int *oper) {
	switch (c) {
	/* Quit */
	case 'Q':
	case 'q':
		*oper = -1;
		break;
	/* Shuffle */
	case 'S':
	case 's':
		*oper = 0;
		break;
	/* Up */
	case 'U':
	case 'u':
		*oper = 1;
		break;
	/* Right */
	case 'R':
	case 'r':
		*oper = 2;
		break;
	/* Down */
	case 'D':
	case 'd':
		*oper = 3;
		break;
	/* Left */
	case 'L':
	case 'l':
		*oper = 4;
		break;
	/* Intelligent */
	case 'I':
	case 'i':
		*oper = 5;
		break;
	/* Intelligent v2 */
	case 'V':
	case 'v':
		*oper = 6;
		break;
	/* Report */
	case 'T':
	case 't':
		*oper = 7;
		break;
	/* Save */
	case 'E':
	case 'e':
		*oper = 8;
		break;
	/* Load */
	case 'F': /* new input letter */
	case 'f': /* new input letter */
		*oper = 9;
		break;
	/* Invalid input */
	default:
		*oper = 99;
		break;
	}
	return;
}

void generate_table(int *num, int n) {
	int i = 0, i_num = 0, if_same, temp_num, temp_i_num;
	num = (int*)realloc(num, ((n * n) + 1) * sizeof(int));
	while (i < (n * n)) {
		if_same = 0;
		temp_num = (rand() % (n * n));
		temp_i_num = i_num - 1;
		while (temp_i_num >= 0) {
			if (temp_num == num[temp_i_num]) {
				if_same = 1;
				break;
			}
			--temp_i_num;
		}
		if (if_same)
			continue;
		num[i_num] = temp_num;
		++i;
		++i_num;
	}
	num[i_num] = -1;
}

void print_table(int *num, int n) {
	int i_num = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (num[i_num] == 0) {
				cout.width(2);
				cout << ' ' << " ";
			} else {
				cout.width(2);
				cout << num[i_num] << " ";
			}
			++i_num;
		}
		cout << endl;
	}
	return;
}

int* get_from_file(std::string file_path) {
	int i = 0;
	int *num = (int*)malloc(sizeof(int));
	char c;
	fstream fio;
	fio.open(file_path, ios::in);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
		num[i] = -1;
		return (num);
	}
	while (!fio.eof()) {
		fio.get(c);
		if (c != ' ') {
			num[i] = static_cast<int>(c) - 48;
			cout << i << ": " << num[i] << endl;
			++i;
			num = (int*)realloc(num, (i + 1) * sizeof(int));
		}
	}
	num[i] = -1;
	fio.close();
	return (num);
}

void save_to_file(int *num, string file_path) {
	fstream fio;
	fio.open(file_path, ios::out);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
	}
	for (int i = 0; *(num + i) != -1; ++i) {
		fio << *(num + i) << " ";
	}
	fio.close();
	return;
}

/* Open file
 * Opens the file to be read using the address and file name (together with
 * file type) in the parameter path.*/
void cpp_open_file_edit(char *file_path) {
	//fstream fio;
//	fio.open(file_path);
//	if (!fio.is_open()) {
//		cout << "Error! File not found." << endl;
//		exit(1);
//	}
	return;
}


/* Close file
 * Closes the file using the file pointer in the parameter. */
void cpp_close_file_edit(fstream fio) {
	if (!fio.is_open()) {
		cout << "Error! No open file to be closed." << endl;
		exit(1);
	}
	fio.close();
	return;
}
