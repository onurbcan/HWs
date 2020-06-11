/*
 * Part1.c
 * Description: You will extend the C++ program that you wrote for the N-Puzzle
 * problem. The new extensions are as follows
 * - Your program will accept one optional file name as a command line option.
 * The file name is a text file that contains the shape and the initial
 * configuration of the valid N-Puzzle board. This shape contains the possible
 * positions of the tiles with tile numbers and impossible positions with ‘00’s.
 * The blank tile is marked with ‘bb’. The following is a sample file. Note that
 * your board does not have to be square anymore. There are 40 possible
 * positions for the following board, which means tiles are numbered from 01 to
 * 39. The solution always places the empty tile at the lower right corner.
 * 00 00 00 00 01 02 04 05 00
 * 00 00 00 06 08 09 10 12 13
 * 00 00 00 17 19 14 15 18 07
 * 00 00 00 20 21 23 25 24 29
 * 22 26 28 35 34 31 33 38 39
 * bb 30 31 34 32 36 03 11 16
 * - Your board game will be more intelligent. Sometimes behaving randomly is
 * rational and this strategy can beat other more “intelligent” behavior. As you
 * have observed from your HW1, making intelligent moves all the time often gets
 * you stuck. Random moves will get you out! You will mix random board moves
 * with the “intelligent” moves that you implemented in HW1. For example, you
 * may make a few random moves and then a few intelligent moves and continue
 * until the solution is found. You may try different strategies such as more
 * random moves at the beginning of the game and then less random moves.
 * - You will add the following Input/Action pairs to your table
 * Input	Action
 * V		Solves the problem from the current configuration using the new
 * 			intelligent algorithm.
 * T		Prints a report about how many moves have been done and if the
 * 			solution is found
 * E		Asks a file name and saves the current board configuration as a
 * 			loadable shape file.
 * L		Asks a file name and loads the current board configuration from the
 * 			shape file.
 *
 * Notes:
 * • Do not use any functions from the standard C library (like printf ), use
 * cout, cin, etc.
 * • Your program should have only functions and no classes other than enums.
 * • Do not use any C++ features that we did not learn during the lectures.
 * • You will use all the object oriented techniques that we learned in the class
 * including const, inline, declrtype, auto keywords.
 * • Do not use anything that we did not learn in the lectures.
 * • Do not forget to indent your code and provide comments.
 * • Check the validity of the user input.
 * • Test your programs very carefully at least with 10 different runs and
 * submit your result files for each.
 * • You should submit your work to the moodle page and follow all the
 * submission rules that will be posted.
 *
 *  Created on: May 23, 2020
 *      Author: onur
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include "Part1.h"
using namespace std;

void n_puzzle_game_v2() {
	int menu_choice, *num, n, m, n_num, count = 0;
	char save_choice;

	srand(time(nullptr));
	while (1) {
		/* initial menu screen */
		while (1) {
			cout << "Welcome to the N-Puzzle game." << endl;
			cout << "1) Resume" << endl;
			cout << "2) New Game" << endl;
			cout << "0) Quit" << endl;
			cout << "Please enter your choice." << endl;
			cin >> menu_choice;
			if (!(menu_choice == 0 || menu_choice == 1 || menu_choice == 2))
				cout << menu_choice << " is an invalid choice. Please try again." << endl;
			else
				break;
		}
		switch (menu_choice) {
		case (0):
			do {
				cout << "Would you like to save what you played so far to be ";
				cout << "loaded next time? (Y/N)" << endl;
				cin >> save_choice;
				if (!(save_choice == 'Y' || save_choice == 'y' ||
						save_choice == 'N' || save_choice == 'n')) {
					cout << save_choice << "is an invalid choice. ";
					cout << "Please enter Y for Yes or N for No" << endl;
				}
			} while (!(save_choice == 'Y' || save_choice == 'y' ||
					save_choice == 'N' || save_choice == 'n'));
			if (save_choice == 'Y' || save_choice == 'y') {
				swap_elements(8, num, &n, &m, &count);
				cout << "Game configurations saved successfully. ";
			}
			cout << "Good bye!" << endl;
			break;
		case (1):
			num = resume_screen(&n, &m, &count);
			play_n_puzzle_game(num, &n, &m, &n_num, &count);
			break;
		case (2):
			num = new_game_screen(&n, &m, &n_num);
			play_n_puzzle_game(num, &n, &m, &n_num, &count);
			break;
		default:
			break;
		}
		if (menu_choice == 0)
			break;
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
	case 'O': /* new input letter */
	case 'o': /* new input letter */
		*oper = 9;
		break;
	/* New game */
	case 'N': /* additional input letter */
	case 'n': /* additional input letter */
		*oper = 10;
		break;
	/* Invalid input */
	default:
		*oper = 99;
		break;
	}
	return;
}

int* generate_table(int n, int m, int n_num) {
	int i_num = 0, if_same, temp_num, temp_i_num;
	int *num = (int*)malloc(((n * m) + 1) * sizeof(int));
	while (i_num < (n * m)) {
		if (i_num < n_num) {
			if_same = 0;
			temp_num = rand() % n_num;
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
		} else {
			/* -2 will represent zeros on the table */
			num[i_num] = -2;
		}
		++i_num;
	}
	num[i_num] = -1;
	return (num);
}

void print_table(int *num, int n, int m) {
	int i_num = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (num[i_num] == 0) {
				cout.width(2);
				cout << "bb" << " ";
			} else if (num[i_num] == -2) {
				cout.width(2);
				cout << "00" << " ";
			} else {
				if (num[i_num] < 10)
					cout << "0";
				else
					cout.width(2);
				cout << num[i_num] << " ";
			}
			++i_num;
		}
		cout << endl;
	}
	return;
}

void print_report(int count, int if_done) {
	cout << count << "moves have been done. ";
	if (if_done)
		cout << "Solution has been found already." << endl;
	else
		cout << "Solution has not been found yet. Keep going!" << endl;
	return;
}

int* resume_screen(int *n, int *m, int *count) {
	int if_error, sizes[2], *num;
	string file_path;

	while (1) {
		cout << "Please enter the name of file that has the data of saved game." << endl;
		cout << "For e.g: n_puzzle_game.txt" << endl;
		cin >> file_path;
		num = get_from_file(file_path, &if_error, sizes, count);
		if (if_error)
			cout << "File path is invalid. Please try again." << endl;
		else {
			*n = sizes[0];
			*m = sizes[1];
			cout << "Saved " << *n << "-by-" << *m << " table is loaded below. ";
			break;
		}
	}
	return (num);
}

int* new_game_screen(int *n, int *m, int *n_num) {
	int *num;

	while (1) {
		cout << "Please enter the N size of the game to be built N-by-M table" << endl;
		cin >> *n;
		if (*n < 2)
			cout << "Table sizes have to be greater than 1. Please try again." << endl;
		else
			break;
	}
	while (1) {
		cout << "Please enter the M size of the game to be built N-by-M table" << endl;
		cin >> *m;
		if (*m < 2)
			cout << "Table sizes have to be greater than 1. Please try again." << endl;
		else {
			break;
		}
	}
	while (1) {
		cout << "Please enter the number of numbers on the table. Rest will be zeros." << endl;
		cin >> *n_num;
		if (*n_num > (*n * *m) || *n_num <= 0) {
			cout << "Number of numbers has to be from 1 to " << (*n * *m);
			cout << ".Please try again accordingly." << endl;
		} else {
			num = generate_table(*n, *m, *n_num);
			cout << *n << "-by-" << *m << " table with " << ((*n * *m) - *n_num);
			cout << " zeros is generated below. ";
			break;
		}
	}
	return (num);
}

void play_n_puzzle_game(int *num, int *n, int *m, int *n_num, int *count) {
	int oper, if_done = 0;
	char c;

	while (1) {
		cout << "Use the initial letter of your wished navigation direction like Up (U), Down (D), Left (L), Rigth (R)." << endl;
		cout << "You can quit any time using Q or shuffle the table using S. Have fun!" << endl;
		print_table(num, *n, *m);
		cin >> c;
		convert_command(c, &oper);
		if (oper == -1)
			break;
		else if (oper == 0) {
			*count = 0;
			num = generate_table(*n, *m, *n_num);
		} else if (oper == 5)
			get_intelligent_movement(num, *n, *m, &oper);
		else if (oper == 6)
			get_intelligent_movement_v2(num, *n, *m, &oper);
		else if (oper == 7)
			print_report(*count, if_done);
		system("clear");
		swap_elements(oper, num, n, m, count);
		check_if_done(num, *n_num, &if_done);
		if (if_done) {
			cout << "Problem solved!" << endl;
			break;
		}
		/* if any of up (1), right (2), down(3) or left (4) operated, increase the number of  moves */
		if (oper == 1 || oper == 2 || oper == 3 || oper == 4)
			++*count;
	}
	return;
}

void swap_elements(int oper, int *num, int *n, int *m, int *count) {
	int i_empty, if_error, sizes[2];
	int i_new, new_n, new_m, new_n_num, new_count, *new_num;
	string file_path;

	get_empty_index(num, &i_empty);
	switch (oper) {
	case (0):
		cout << "Table is shuffled. Good luck!" << endl;
		break;
	case (1):
		if ((i_empty - *m) < 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty - *m];
		num[i_empty - *m] = 0;
		break;
	case (2):
		if (((i_empty + 1) % *m) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty + 1];
		num[i_empty + 1] = 0;
		break;
	case (3):
		if ((i_empty + *m) >= (*n * *m)) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty + *m];
		num[i_empty + *m] = 0;
		break;
	case (4):
		if ((i_empty % *m) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty] = num[i_empty - 1];
		num[i_empty - 1] = 0;
		break;
	case (8):
		while (1) {
			cout << "Please enter the name of file that has the data of saved game." << endl;
			cout << "For e.g: n_puzzle_game.txt" << endl;
			cin >> file_path;
			sizes[0] = *n;
			sizes[1] = *m;
			save_to_file(file_path, &if_error, num, sizes, *count);
			if (if_error)
				cout << "File path is invalid. Please try again." << endl;
			else {
				cout << "Game configurations saved successfully." << endl;
				break;
			}
		}
		break;
	case (9):
		new_num = resume_screen(&new_n, &new_m, &new_count);
		*n = new_n;
		*m = new_m;
		*count = new_count;
		for (i_new = 0; new_num[i_new] != -1; ++i_new) {
			num[i_new] = new_num[i_new];
		}
		num[i_new] = -1;
		free(new_num);
		cout << "New game configurations loaded. Have fun!" << endl;
		break;
	case (10):
		new_num = new_game_screen(&new_n, &new_m, &new_n_num);
		*n = new_n;
		*m = new_m;
		*count = 0;
		for (i_new = 0; new_num[i_new] != -1; ++i_new) {
			num[i_new] = new_num[i_new];
		}
		num[i_new] = -1;
		free(new_num);
		cout << "i_new and num[i_new]: " << i_new << " and " << num[i_new] << endl;
		break;
	default:
		cout << "Error occurred! You entered an invalid input. Please try again." << endl;
		break;
	}
	return;
}

void get_intelligent_movement(int *num, int n, int m, int *oper) {
	int i_empty, least = n * m;

	get_empty_index(num, &i_empty);
	if ((i_empty - m) >= 0) {
		if (num[i_empty - m] < least) {
			least = num[i_empty - m];
			*oper = 1;
		}
	}
	if (((i_empty + 1) % m) != 0) {
		if (num[i_empty + 1] < least) {
			least = num[i_empty + 1];
			*oper = 2;
		}
	}
	if ((i_empty + m) < (n * m)) {
		if (num[i_empty + m] < least) {
			least = num[i_empty + m];
			*oper = 3;
		}
	}
	if ((i_empty % m) != 0) {
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

void get_intelligent_movement_v2(int *num, int n, int m, int *oper) {
	int i_empty, is_random, least = n * m;

	get_empty_index(num, &i_empty);
	is_random = rand() % 2;
	switch (is_random) {
	case (0):
		if ((i_empty - m) >= 0) {
			if (num[i_empty - m] < least) {
				least = num[i_empty - m];
				*oper = 1;
			}
		}
		if (((i_empty + 1) % m) != 0) {
			if (num[i_empty + 1] < least) {
				least = num[i_empty + 1];
				*oper = 2;
			}
		}
		if ((i_empty + m) < (n * m)) {
			if (num[i_empty + m] < least) {
				least = num[i_empty + m];
				*oper = 3;
			}
		}
		if ((i_empty % m) != 0) {
			if (num[i_empty - 1] < least) {
				least = num[i_empty - 1];
				*oper = 4;
			}
		}
		cout << "Intelligent move v2 chooses ";
		break;
	case (1):
		int sides[4] = {0, 0, 0, 0};
		if ((i_empty - m) >= 0)
			sides[0] = 1;
		if (((i_empty + 1) % m) != 0)
			sides[1] = 1;
		if ((i_empty + m) < (n * m))
			sides[2] = 1;
		if ((i_empty % m) != 0)
			sides[3] = 1;
		do {
			*oper = (rand() % 4) + 1;
		} while (sides[*oper - 1] != 1);
		cout << "Intelligent move v2 chooses (randomly) ";
		break;
	}
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

void get_empty_index(int *num, int *i_empty) {
	*i_empty = 0;
	while (num[*i_empty] != -1) {
		if (num[*i_empty] == 0)
			break;
		++*i_empty;
	}
	return;
}

void check_if_done(int *num, int n_num, int *if_done) {
	*if_done = 1;

	if (num[n_num - 1] != 0) {
		*if_done = 0;
		return;
	}
	for (int i = n_num - 2; i > 0; --i) {
		if (num[i] < num[i - 1]) {
			*if_done = 0;
			break;
		}
	}
	return;
}

int string_int_converter(string num_str) {
	int i, p, to_power = 0;
	int num = 0, multiplier;

	for (i = num_str.length() - 1; i >= 0; --i) {
		multiplier = 1;
		for (p = 0; p < to_power; ++p)
			multiplier *= 10;
		num += ((num_str[i] - 48) * multiplier);
		++to_power;
	}
	return (num);
}

/* Save to file
 * Saves elements of integer array to the newly created file using the address
 * in the parameter. */
void save_to_file(string file_path, int *if_error, int *num, int *sizes, int count) {
	fstream fio;
	fio.open(file_path, ios::trunc | ios::out);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
		*if_error = 1;
		return;
	}
	/* num data */
	for (int i = 0; *(num + i) != -1; ++i) {
		fio << *(num + i) << " ";
	}
	/* n and m sizes */
	fio << endl << sizes[0] << " " << sizes[1] << " ";
	/* number of moves */
	fio << endl << count << " ";
	fio.close();
	*if_error = 0;
	return;
}

/* Get from file
 * Gets numbers that are separated with spaces from the input file and writes
 * them in a dynamically allocated array. */
int* get_from_file(std::string file_path, int *if_error, int *sizes, int *count) {
	int i, i_num = 0, i_sizes = 0, i_line = 0;
	int *num = (int*)malloc(sizeof(int));
	char c, temp_str[5];
	fstream fio;
	fio.open(file_path, ios::in);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
		*if_error = 1;
		num[i_num] = -1;
		return (num);
	}
	while (!fio.eof()) {
		fio.get(c);
		i = 0;
		if (c == '\n') {
			++i_line;
		} else if (c != ' ' && i_line == 0) {
			while (c != ' ') {
				temp_str[i] = c;
				fio.get(c);
				++i;
			}
			temp_str[i] = '\0';
			string str(temp_str);
			num[i_num] = string_int_converter(temp_str);
			++i_num;
			num = (int*)realloc(num, (i_num + 1) * sizeof(int));
		} else if (c != ' ' && i_line == 1) {
			while (c != ' ') {
				temp_str[i] = c;
				fio.get(c);
				++i;
			}
			temp_str[i] = '\0';
			string str(temp_str);
			sizes[i_sizes] = string_int_converter(temp_str);
			++i_sizes;
		} else if (c != ' ' && i_line == 2) {
			while (c != ' ') {
				temp_str[i] = c;
				fio.get(c);
				++i;
			}
			temp_str[i] = '\0';
			string str(temp_str);
			*count = string_int_converter(temp_str);
		}
	}
	num[i_num] = -1;
	*if_error = 0;
	fio.close();
	return (num);
}
