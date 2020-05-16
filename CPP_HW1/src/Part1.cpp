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
	int n, oper;
	char c;

	/* initial menu screen */
	cout << "Please enter the N size of the game to be built N-by-N table\n";
	cin >> n;
	cout << n << "-by-" << n << " table is generated below. Use the initial letter of your wished navigation direction like Up (U), Down (D), Left (L), Rigth (R)." << endl;
	cout << "You can quit any time using Q or shuffle the table using S. Have fun!" << endl;
	/* N-by-N table declared */
	int num[n * n];
	srand(time(nullptr));
	generate_table(num, n);
	while (1) {
		print_table(num, n);
		cin >> c;
		convert_command(c, &oper);
		if (oper == -1)
			break;
		else if (oper == 0)
			generate_table(num, n);
		else if (oper == 5)
			get_intelligent_movement(num, n, &oper);
		system("clear");
		swap_elements(num, oper, n);
	}
	cout << "Good bye!" << endl;
	return;
}

void generate_table(int *num, int n) {
	int i = 0, i_num = 0, if_same, temp_num, temp_i_num;

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

void convert_command(char c, int *oper) {
	/* Quit */
	if (c == 'Q' || c == 'q')
		*oper = -1;
	/* Shuffle */
	else if (c == 'S' || c == 's')
		*oper = 0;
	/* Up */
	else if (c == 'U' || c == 'u')
		*oper = 1;
	/* Right */
	else if (c == 'R' || c == 'r')
		*oper = 2;
	/* Down */
	else if (c == 'D' || c == 'd')
		*oper = 3;
	/* Left */
	else if (c == 'L' || c == 'l')
		*oper = 4;
	/* Intelligent */
	else if (c == 'I' || c == 'i')
		*oper = 5;
	/* Invalid input */
	else
		*oper = 99;
	return;
}

void get_empty_index(int *num, int n, int *i_empty) {
	*i_empty = 0;
	while (*i_empty < (n * n)) {
		if (num[*i_empty] == 0)
			break;
		++*i_empty;
	}
	return;
}

void get_intelligent_movement(int *num, int n, int *oper) {
	int i_empty, least = 9;

	get_empty_index(num, n, &i_empty);
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
	int i_empty;

	get_empty_index(num, n, &i_empty);
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
		cout << "Error occurred! You entered an invalid input. Please try again." << endl;
		break;
	}
	return;
}
