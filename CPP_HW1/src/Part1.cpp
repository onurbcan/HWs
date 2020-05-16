/*
 * Part1.cpp
 *
 *  Created on: May 16, 2020
 *      Author: onur
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Part1.h"
using namespace std;

void n_puzzle_game() {
	int n = 3, oper;
	char c;
	int num[n * n];
	srand(time(nullptr));
	generate_table(num, n);
	while (1) {
		print_table(num, n);
		cin >> c;
		convert_command(c, &oper);
		//cout << oper;
		if (oper == -1)
			break;
		else if (oper == 0)
			generate_table(num, n);
		else if (oper == 5)
			get_intelligent_movement(num, n, &oper);
		swap_elements(num, oper, n);
	}
	return;
}

void generate_table(int *num, int n) {
	int j = 0, same, i_num = 0, temp, temp_i_num;

	while (j < (n * n)) {
		same = 0;
		temp = (rand() % (n * n));
		temp_i_num = i_num - 1;
		while (temp_i_num >= 0) {
			if (temp == num[temp_i_num]) {
				same = 1;
				break;
			}
			--temp_i_num;
		}
		if (same) continue;
		num[i_num] = temp;
		++j;
		++i_num;
	}
}

void print_table(int *num, int n) {
	int i, j, i_num = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (num[i_num] == 0)
				cout << ' ' << " ";
			else
				cout << num[i_num] << " ";
			++i_num;
		}
		cout << endl;
	}
	return;
}

void convert_command(char c, int *oper) {
	/* Quit */
	if (c == 'Q')
		*oper = -1;
	/* Shuffle */
	else if (c == 'S')
		*oper = 0;
	/* Up */
	else if (c == 'U')
		*oper = 1;
	/* Right */
	else if (c == 'R')
		*oper = 2;
	/* Down */
	else if (c == 'D')
		*oper = 3;
	/* Left */
	else if (c == 'L')
		*oper = 4;
	/* Intelligent */
	else if (c == 'I')
		*oper = 5;
	return;
}

void get_intelligent_movement(int *num, int n, int *oper) {
	int i_empty = 0, least = 9;
	while (1) {
		if (num[i_empty] == 0)
			break;
		++i_empty;
	}
	if ((i_empty - n) >= 0) {
		least = num[i_empty - 3];
		*oper = 1;
	}
	if (((i_empty + 1) % n) != 0) {
		if (num[i_empty + 1] < least) {
			least = num[i_empty + 1];
			*oper = 2;
		}
	}
	if ((i_empty + n) < (n * n)) {
		if (num[i_empty + 3] < least) {
			least = num[i_empty + 3];
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

void swap_elements(int *num, int oper, int n) {
	int i_empty = 0;
	while (1) {
		if (num[i_empty] == 0)
			break;
		++i_empty;
	}
	switch (oper) {
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
		num[i_empty] = num[i_empty + 3];
		num[i_empty + 3] = 0;
		break;
	case (4):
		if ((i_empty % n) == 0) {
			cout << "Error occurred! Target index is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty - 1];
		num[i_empty - 1] = 0;
		break;
	default:
		break;
	}
	return;
}
