/*
 * Part1.cpp
 * Description: In this homework, you will rewrite our N-Puzzle program using
 * classes. Your overall program will behave very similar to your previous
 * homework but your program structure will be considerably different.
 * Your main class will be named NPuzzle. It will have the following public
 * functions.
 * Fuction Name		Explanation
 * print			Prints the current configuration on the screen by sending it
 * 					to cout
 * printReport		Prints a report about how many moves have been done since
 * 					reset and if the solution is found
 * readFromFile		Reads the current configuration from the file given as
 * 					function parameter. The file format is defined as in HW2.
 * writeToFile		Writes the current configuration to the file given as
 * 					function parameter
 * shuffle			Makes N random moves to shuffle the board. N is given as a
 * 					function parameter.
 * reset			Resets the current configuration to the solution.
 * setsize			Sets the board size to given values. The values are given as
 * 					parameters and they can be at most 9x9. After setting the
 * 					size, the boards should be reset.
 * moveRandom		Makes a valid random move
 * moveIntelligent 	Makes an “intelligent” move
 * move 			Makes a move according to the given char parameter. If the
 * 					parameters is ‘L’ then, the blank tiles moves left, ...,
 * 					etc, as defined in HW1.
 * solvePuzzle		Makes an attempt to solve the puzzle using your own
 * 					algorithm from HW2.
 *
 * Your NPuzzle class defines and uses a private inner class named Board, which
 * represents the board configuration using a private C type 2D array. This
 * class defines the following functions
 * Fuction Name		Explanation
 * print			Prints the board on the screen by sending it to cout
 * readFromFile		Reads the board from the file given as function parameter.
 * 					The file format is defined as in HW2.
 * writeToFile		Writes the board to the file given as function parameter
 * reset			Resets the board to the solution.
 * setSize			Sets the board size to given values. The values are given as
 * 					parameters and they can be at most 9x9. After setting the
 * 					size, the boards should be reset.
 * move				Makes a move according to the given char parameter. If the
 * 					parameters is ‘L’ then the blank tiles moves left, ..., etc,
 * 					as defined in HW1.
 * isSolved			Returns true if the board is a solution
 *
 * Your program will use object or objects of NPuzzle to perform what we did
 * previously in HW1 and HW2. Your command line options and your user interface
 * is the same. The following table is repeated here just for convenience.
 * Input		Action
 * V			Solves the problem from the current configuration using the
 * 				intelligent algorithm.
 * T			Prints a report about how many moves have been done and if the
 * 				solution is found
 * E			Asks a file name and saves the current board configuration as a
 * 				loadable shape file.
 * O			Asks a file name and loads the current board configuration from
 * 				the shape file.
 * L			moves the empty cell left if there is room
 * R			moves the empty cell right if there is room
 * U			moves the empty cell up if there is room
 * D			moves the empty cell down if there is room
 * I			makes an “intelligent” move for you.
 * S			Shuffle- takes the board to the final solution, and makes
 * 				size*size random moves to shuffle the board.
 *
 * Notes:
 * • Do not use any functions from the standard C library (like printf ), use
 * cout, cin, etc.
 * • Your program should have no global functions other than main. Do not use
 * any global variables.
 * • Do not use any C++ features that we did not learn during the lectures.
 * • You will use all the object oriented techniques that we learned in the
 * class including const, inline, declrtype, auto keywords.
 * • Do not forget to indent your code and provide comments.
 * • Check the validity of the user input.
 * • Test your programs very carefully at least with 10 different runs and
 * submit your result files for each.
 * • You should submit your work to the moodle page and follow all the
 * submission rules that will be posted.
 *
 *  Created on: Jun 5, 2020
 *      Author: onur
 */

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
#include "Part1.h"
using namespace std;



void n_puzzle_game_oop() {
	srand(time(nullptr));
	//n_puzzle::board new_board;
	n_puzzle new_puzzle;
	new_puzzle.print();
	cout << new_puzzle.new_board.count << endl;


	//new_board.printReport();
//	new_board.readFromFile();
//	new_board.print();
//	new_board.move('r');
//	new_board.print();

	//new_board.writeToFile();
	//new_board.shuffle();
	//new_board.reset();
	//new_board.isSolved();
	//new_board.setSize();
	//new_board.print();
}

void n_puzzle::print() {
	new_board.readFromFile();
	new_board.print();
	return;
}

void n_puzzle::board::print() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (num[i][j] == 0) {
				cout << "bb" << " ";
			} else if (num[i][j] == -2) {
				cout << "00" << " ";
			} else {
				if (num[i][j] < 10)
					cout << "0";
				cout << num[i][j] << " ";
			}
		}
		cout << endl;
	}
	return;
}

/*
void n_puzzle::printReport() {
	cout << count << " moves have been done. ";
	if (if_done)
		cout << "Solution has been found already." << endl;
	else
		cout << "Solution has not been found yet. Keep going!" << endl;
	return;
}
*/

void n_puzzle::board::readFromFile() {
	string file_path;

	while (1) {
		cout << "Please enter the name of file that has the data of saved game." << endl;
		cout << "For e.g: n_puzzle_game.txt" << endl;
		cin >> file_path;
		num = get_from_file(file_path, &if_error, sizes, &count);
		if (if_error)
			cout << "File path is invalid. Please try again." << endl;
		else {
			n = sizes[0];
			m = sizes[1];
			cout << "Saved " << n << "-by-" << m << " table is loaded below. " << endl;
			break;
		}
	}
	return;
}

/* Get from file
 * Gets numbers that are separated with spaces from the input file and writes
 * them in a dynamically allocated array. */
int** n_puzzle::board::get_from_file(std::string file_path, int *if_error, int *sizes, int *count) {
	int i, i_row = 0, i_col = 0, i_sizes = 0, i_line = 0;
	int **num = 0;
	char c, temp_str[5];
	n_num = 0;
	fstream fio;
	fio.open(file_path, ios::in);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
		*if_error = 1;
		num[i_row][i_col] = -1;
		return (num);
	}
	while (!fio.eof()) {
		fio.get(c);
		i = 0;
		if (c == '\n') {
			++i_line;
		} else if (c != ' ' && i_line == 2) {
			while (c != ' ') {
				temp_str[i] = c;
				fio.get(c);
				++i;
			}
			temp_str[i] = '\0';
			string str(temp_str);
			num[i_row][i_col] = string_int_converter(temp_str);
			if (num[i_row][i_col] != -2)
				++n_num;
			if (i_col == (sizes[1] - 1)) {
				++i_row;
				i_col = 0;
			} else {
				++i_col;
			}
		} else if (c != ' ' && i_line == 0) {
			while (c != ' ') {
				temp_str[i] = c;
				fio.get(c);
				++i;
			}
			temp_str[i] = '\0';
			string str(temp_str);
			sizes[i_sizes] = string_int_converter(temp_str);
			if (i_sizes == 0) {
				num = (int**)realloc(num, sizes[0] * sizeof(*num));
			} else if (i_sizes == 1) {
				for (int j = 0; j < sizes[0]; ++j) {
					num[j] = (int*)malloc(sizes[1] * sizeof(int));
				}
			}
			++i_sizes;
		} else if (c != ' ' && i_line == 1) {
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
	*if_error = 0;
	fio.close();
	return (num);
}

/* Save to file
 * Saves elements of integer array to the newly created file using the address
 * in the parameter. */
void n_puzzle::board::writeToFile() {
	while (1) {
		cout << "Please enter the name of file that has the data of saved game." << endl;
		cout << "For e.g: n_puzzle_game.txt" << endl;
		cin >> file_path;
		sizes[0] = n;
		sizes[1] = m;
		save_to_file(file_path, &if_error, num, sizes, count);
		if (if_error)
			cout << "File path is invalid. Please try again." << endl;
		else {
			cout << "Game configurations saved successfully." << endl;
			break;
		}
	}
	return;
}

void n_puzzle::board::save_to_file(string file_path, int *if_error, int **num, int *sizes, int count) {
	fstream fio;
	fio.open(file_path, ios::trunc | ios::out);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
		*if_error = 1;
		return;
	}
	/* n and m sizes */
	fio << sizes[0] << " " << sizes[1] << " ";
	/* number of moves */
	fio << endl << count << " " << endl;
	/* num data */
	for (int i = 0; i < sizes[0]; ++i) {
		for (int j = 0; j < sizes[1]; ++j) {
			fio << num[i][j] << " ";
		}
	}
	fio.close();
	*if_error = 0;
	return;
}

int n_puzzle::board::string_int_converter(string num_str) {
	int num = 0, multiplier = 1;

	for (int i = num_str.length() - 1; i >= 0; --i) {
		if (num_str[i] == '-') {
			num *= -1;
			continue;
		}
		num += ((num_str[i] - 48) * multiplier);
		multiplier *= 10;
	}
	return (num);
}

/*
void n_puzzle::shuffle() {
	cout << "Table is shuffled. Good luck!" << endl;
	num = generate_table(n, m, n_num);
	return;
}
*/

void n_puzzle::board::reset() {
	int i_num = 0;

	cout << "Table is reseted to the solution." << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i_num < n_num - 1)
				num[i][j] = i_num + 1;
			else if (i_num == n_num - 1)
				num[i][j] = 0;
			else
				num[i][j] = -2;
			++i_num;
		}
	}
	return;
}

void n_puzzle::board::setSize(){
	if (n > 9 || m > 9) {
		cout << "Error occurred! Board axis cannot be greater 9. ";
		cout << "Please correct them accordingly and try again." << endl;
	} else {
		num = generate_table(n, m, n_num);
	}
	return;
}

int** n_puzzle::board::generate_table(int n, int m, int n_num) {
	int i_num = 0, if_same, rand_num, temp_i_num;
	int temp_arr[n_num];
	int **num = (int**)malloc(n * sizeof(*num));
	for (int j = 0; j < n; ++j) {
		num[j] = (int*)malloc(m * sizeof(int));
	}

	while (i_num < (n * m)) {
		if (i_num < n_num) {
			if_same = 0;
			rand_num = rand() % n_num;
			temp_i_num = i_num - 1;
			while (temp_i_num >= 0) {
				if (rand_num == temp_arr[temp_i_num]) {
					if_same = 1;
					break;
				}
				--temp_i_num;
			}
			if (if_same)
				continue;
			temp_arr[i_num] = rand_num;
			num[i_num / m][i_num % m] = rand_num;
		} else {
			// -2 will represent zeros on the table
			num[i_num / m][i_num % m] = -2;
		}
		++i_num;
	}
	return (num);
}

void n_puzzle::board::move(char c) {
	int oper, i_empty;

	switch (c) {
	/* Up */
	case 'U':
	case 'u':
		oper = 1;
		break;
	/* Right */
	case 'R':
	case 'r':
		oper = 2;
		break;
	/* Down */
	case 'D':
	case 'd':
		oper = 3;
		break;
	/* Left */
	case 'L':
	case 'l':
		oper = 4;
		break;
	}

	get_empty_index(num, &i_empty);
	switch (oper) {
	case (1):
		if ((i_empty - m) < 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty / m][i_empty % m] = num[(i_empty / m) - 1][i_empty % m];
		num[(i_empty / m) - 1][i_empty % m] = 0;
		break;
	case (2):
		if (((i_empty + 1) % m) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty / m][i_empty % m] = num[i_empty / m][(i_empty % m) + 1];
		num[i_empty / m][(i_empty % m) + 1] = 0;
		break;
	case (3):
		if ((i_empty + m) >= (n * m)) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty / m][i_empty % m] = num[(i_empty / m) + 1][i_empty % m];
		num[(i_empty / m) + 1][i_empty % m] = 0;
		break;
	case (4):
		if ((i_empty % m) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl;
			break;
		}
		num[i_empty / m][i_empty % m] = num[i_empty / m][(i_empty % m) - 1];
		num[i_empty / m][(i_empty % m) - 1] = 0;
		break;
	}
	return;
}

void n_puzzle::board::get_empty_index(int **num, int *i_empty) {
	*i_empty = 0;

	while (*i_empty != (n * m)) {
		if (num[*i_empty / m][*i_empty % m] == 0)
			break;
		++*i_empty;
	}
	return;
}

void n_puzzle::board::isSolved() {
	if_done = 1;
	/* checks if numbers in indices for e.g (3-by-3 game) 0 to 7 are in order */
	for (int i = 1; i < n_num - 1; ++i) {
		if (num[(i - 1) / m][(i - 1) % m] > num[i / m][i % m]) {
			if_done = 0;
			break;
		}
	}
	return;
}

