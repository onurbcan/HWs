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
	int n, oper, if_done, *num;
	char c;

	srand(time(nullptr));
	/* initial menu screen */
	cout << "Please enter the N size of the game to be built N-by-N table\n";
	cin >> n;
	cout << n << "-by-" << n << " table is generated below. Use the initial letter of your wished navigation direction like Up (U), Down (D), Left (L), Rigth (R)." << endl;
	cout << "You can quit any time using Q or shuffle the table using S. Have fun!" << endl;
	/* N-by-N table generated */
	num = generate_table(n);
	while (1) {
		print_table(num, n);
		cin >> c;
		convert_command(c, &oper);
		if (oper == -1)
			break;
		else if (oper == 0)
			num = generate_table(n);
		else if (oper == 5)
			get_intelligent_movement(num, n, &oper);
		else if (oper == 6)
			get_intelligent_v2_movement(num, n, &oper);
		/* integrate save/load file functions */
		system("clear");
		swap_elements(num, oper, n);
		check_if_done(num, &if_done);
		if (if_done) {
			cout << "Problem solved!" << endl;
			break;
		}
	}
	cout << "Good bye!" << endl;
	return;
}
//	int *num;
//	num = get_from_file("files/sample2.txt");
//	for (int i = 0; num[i] != -1; ++i) {
//		cout << i << ": " << num[i] << endl;
//	}

//	int n = 5, *num = (int*)malloc(sizeof(int));
//	generate_table(num, n);
//	print_table(num, n);
//	save_to_file(num, "files/sample2.txt");

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
	/* New game */
	case 'N': /* new input letter */
	case 'n': /* new input letter */
		*oper = 10;
		break;
	/* Invalid input */
	default:
		*oper = 99;
		break;
	}
	return;
}

int* generate_table(int n) {
	int i_num = 0, if_same, temp_num, temp_i_num;
	int *num = (int*)malloc(((n * n) + 1) * sizeof(int));

	while (i_num < (n * n)) {
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
		++i_num;
	}
	printf("i_num: %d\n", i_num);
	num[i_num] = -1;
	return (num);
}

void print_table(int *num, int n) {
	int i_num = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (num[i_num] == 0) {
				cout.width(2);
				cout << "bb" << " ";
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

void print_report() {




	return;
}

void swap_elements(int *num, int oper, int n) {
	int i_empty;

	get_empty_index(num, &i_empty);
	switch (oper) {
	case (0):
		cout << "Table is shuffled. Good luck!" << endl;
		break;
	case (1):
		if ((i_empty - n) < 0) {
			cout << "Error occurred! Target index is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty - n];
		num[i_empty - n] = 0;
		break;
	case (2):
		if (((i_empty + 1) % n) == 0) {
			cout << "Error occurred! Target index is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty + 1];
		num[i_empty + 1] = 0;
		break;
	case (3):
		if ((i_empty + n) >= (n * n)) {
			cout << "Error occurred! Target index is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty + n];
		num[i_empty + n] = 0;
		break;
	case (4):
		if ((i_empty % n) == 0) {
			cout << "Error occurred! Target index is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty - 1];
		num[i_empty - 1] = 0;
		break;
	case (7):
		print_report();
		break;
	case (8):
		save_to_file(int *num, string file_path);
		break;
	case (9):
		num = get_from_file(string file_path);
		break;
	default:
		cout << "Error occurred! You entered an invalid input. Please try again." << endl;
		break;
	}
	return;
}

void get_intelligent_movement(int *num, int n, int *oper) {
	int i_empty, least = 9;

	get_empty_index(num, &i_empty);
	if ((i_empty - n) >= 0) {
		least = num[i_empty - n];
		*oper = 1;
	}
	if (((i_empty + 1) % n) != 0) {
		if (num[i_empty + 1] < least) {
			least = num[i_empty + 1];
			*oper = 2;
		}
	}
	if ((i_empty + n) < (n * n)) {
		if (num[i_empty + n] < least) {
			least = num[i_empty + n];
			*oper = 3;
		}
	}
	if ((i_empty % n) != 0) {
		if (num[i_empty - 1] < least) {
			least = num[i_empty - 1];
			*oper = 4;
		}
	}
	cout << "Intelligent move chooses ";
	switch (*oper) {
	case (1):
		cout << "U" << endl;
		break;
	case (2):
		cout << "R" << endl;
		break;
	case (3):
		cout << "D" << endl;
		break;
	case (4):
		cout << "L" << endl;
		break;
	default:
		break;
	}
	return;
}

void get_intelligent_v2_movement(int *num, int n, int *oper) {

}

void get_empty_index(int *num, int *i_empty) {
	*i_empty = 0;
	while (num[*i_empty] != -1) {
		if (num[*i_empty] == 0)
			break;
		++*i_empty;
	}
	return;
}

void check_if_done(int *num, int *if_done) {
	*if_done = 1;
	/* checks if numbers in indices for e.g (3-by-3 game) 0 to 7 are in order */
	for (int i = 0; num[i + 2] != -1; ++i) {
		if (num[i] > num[i + 1]) {
			*if_done = 0;
			break;
		}
	}
	return;
}

/* Save to file
 * Saves elements of integer array to the newly created file using the address
 * in the parameter. */
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

/* Get from file
 * Gets numbers that are separated with spaces from the input file and writes
 * them in a dynamically allocated array. */
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
