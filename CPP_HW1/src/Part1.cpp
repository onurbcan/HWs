/*
 * Part1.cpp
 * Description: You will write a C++ program that helps the user to solve the
 * N-Puzzle problem. See descriptions from the web to understand the problem and
 * the rules.
 * When your program starts, it will first ask the user the size of the game
 * (3x3, 4x4, 5x5, ..., 9x9). Then it will show a solvable random initial board
 * configuration. There are some random configurations that can’t be solved, be
 * careful! Then, you will ask the user to input one of the following and take
 * action.
 * Input 	Action
 * L		moves the empty cell left if there is room
 * R		moves the empty cell right if there is room
 * U		moves the empty cell up if there is room
 * D		moves the empty cell down if there is room
 * I		makes an “intelligent” move for you. Intelligent move moves the
 * blank tile in a way that after the move, the tiles are closer to their final
 * positions. You may add extra intelligence if you like!
 * S 		Shuffle- takes the board to the final solution, and makes size*size
 * random moves to shuffle the board.
 * Q		Quits the game
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
	int n, oper, if_done;
	char c;

	/* initial menu screen */
	while (1) {
		cout << "Please enter the N size of the game to be built N-by-M table" << endl;
		cin >> n;
		if (n < 2) {
			system("clear");
			cout << "Table sizes have to be greater than 1. Please try again." << endl;
		} else
			break;
	}
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
		check_if_done(num, n, &if_done);
		if (if_done) {
			cout << "Problem solved!" << endl;
			break;
		}
	}
	cout << "Good bye!" << endl;
	return;
}

void check_if_done(int *num, int n, int *if_done) {
	int i;
	*if_done = 1;
	/* checks if numbers in indices for e.g (3-by-3 game) 0 to 7 are in order */
	for (i = 0; i < (n * n) - 2; ++i) {
		if (num[i] > num[i + 1]) {
			*if_done = 0;
			break;
		}
	}
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
	/* Invalid input */
	default:
		*oper = 99;
		break;
	}
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
	int i_empty, least = n * n;

	get_empty_index(num, n, &i_empty);
	if ((i_empty - n) >= 0) {
		if (num[i_empty - n] < least) {
			least = num[i_empty - n];
			*oper = 1;
		}
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

void swap_elements(int *num, int oper, int n) {
	int i_empty;

	get_empty_index(num, n, &i_empty);
	switch (oper) {
	case (0):
		cout << "Table is shuffled. Good luck!" << endl;
		break;
	case (1):
		if ((i_empty - n) < 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty - n];
		num[i_empty - n] = 0;
		break;
	case (2):
		if (((i_empty + 1) % n) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty + 1];
		num[i_empty + 1] = 0;
		break;
	case (3):
		if ((i_empty + n) >= (n * n)) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty + n];
		num[i_empty + n] = 0;
		break;
	case (4):
		if ((i_empty % n) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
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
