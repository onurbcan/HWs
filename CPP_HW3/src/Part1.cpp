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

//void n_puzzle_game_oop() {
//	srand(time(nullptr));
//	n_puzzle new_puzzle;
//
//	new_puzzle.readFromFile();
//	new_puzzle.print();
//	new_puzzle.shuffle();
//	new_puzzle.print();
//}

void n_puzzle_game_oop() {
	int menu_choice;//, *num, n, m, n_num, count = 0;
	char save_choice;
	n_puzzle new_puzzle;

	srand(time(nullptr));
	while (1) {
		// initial menu screen
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
				new_puzzle.writeToFile();
				cout << "Game configurations saved successfully. ";
			}
			cout << "Good bye!" << endl;
			break;
		case (1):
			new_puzzle.readFromFile();
			//play_n_puzzle_game(num, &n, &m, &n_num, &count);
			break;
		case (2):
			//num = new_game_screen(&n, &m, &n_num);
			//play_n_puzzle_game(num, &n, &m, &n_num, &count);
			break;
		default:
			break;
		}
		if (menu_choice == 0)
			break;
	}
	return;
}


void convert_command(char c, int &oper) {
	switch (c) {
	/* Quit */
	case 'Q':
	case 'q':
		oper = -1;
		break;
	/* Shuffle */
	case 'S':
	case 's':
		oper = 0;
		break;
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
	/* Intelligent */
	case 'I':
	case 'i':
		oper = 5;
		break;
	/* Intelligent v2 */
	case 'V':
	case 'v':
		oper = 6;
		break;
	/* Report */
	case 'T':
	case 't':
		oper = 7;
		break;
	/* Save */
	case 'E':
	case 'e':
		oper = 8;
		break;
	/* Load */
	case 'O':
	case 'o':
		oper = 9;
		break;
	/* New game */
	case 'N': /* additional input letter */
	case 'n': /* additional input letter */
		oper = 10;
		break;
	/* Invalid input */
	default:
		oper = 99;
		break;
	}
	return;
}

/*
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
		// integrate save/load file functions
		system("clear");
		swap_elements(oper, num, n, m, count);
		check_if_done(num, &if_done);
		if (if_done) {
			cout << "Problem solved!" << endl;
			break;
		}
		// if any of up (1), right (2), down(3) or left (4) operated, increase the number of  moves
		if (oper == 1 || oper == 2 || oper == 3 || oper == 4)
			++*count;
	}
	return;
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
*/

void n_puzzle::print() {
	new_board.print();
	return;
}

void n_puzzle::printReport() {
	cout << new_board.getCount() << " moves have been done. ";
	if (new_board.getDone())
		cout << "Solution has been found already." << endl;
	else
		cout << "Solution has not been found yet. Keep going!" << endl;
	return;
}

void n_puzzle::readFromFile() {
	new_board.readFromFile();
	return;
}

void n_puzzle::writeToFile() {
	new_board.writeToFile();
	return;
}

void n_puzzle::shuffle() {
	new_board.shuffle_board();
	return;
}

void n_puzzle::reset() {
	new_board.reset();
	return;
}

void n_puzzle::setsize() {
	new_board.setSize();
	return;
}

void n_puzzle::moveRandom() {
	char route;
	new_board.get_random_movement(route);
	new_board.move(route);
	return;
}

void n_puzzle::moveIntelligent() {
	char route;
	new_board.get_intelligent_movement(route);
	new_board.move(route);
	return;
}

void n_puzzle::move(char c) {
	new_board.move(c);
	return;
}

void n_puzzle::solvePuzzle() {
	char route;
	new_board.get_intelligent_movement_v2(route);
	new_board.move(route);
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

void n_puzzle::board::readFromFile() {
	string file_path;

	while (1) {
		cout << "Please enter the name of file that has the data of saved game." << endl;
		cout << "For e.g: n_puzzle_game.txt" << endl;
		cin >> file_path;
		num = get_from_file(file_path, if_error, sizes, count);
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

void n_puzzle::board::writeToFile() {
	while (1) {
		cout << "Please enter the name of file that has the data of saved game." << endl;
		cout << "For e.g: n_puzzle_game.txt" << endl;
		cin >> file_path;
		sizes[0] = n;
		sizes[1] = m;
		save_to_file(file_path, if_error, num, sizes, count);
		if (if_error)
			cout << "File path is invalid. Please try again." << endl;
		else {
			cout << "Game configurations saved successfully." << endl;
			break;
		}
	}
	return;
}

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

void n_puzzle::board::setCount(int count_value) {
	count = count_value;
	return;
}

void n_puzzle::board::setDone(int done_value) {
	if_done = done_value;
	return;
}

int** n_puzzle::board::get_from_file(std::string file_path, int &if_error, int *sizes, int &count) {
	int i, i_row = 0, i_col = 0, i_sizes = 0, i_line = 0;
	int **num = 0;
	char c, temp_str[5];
	n_num = 0;
	fstream fio;
	fio.open(file_path, ios::in);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
		if_error = 1;
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
			count = string_int_converter(temp_str);
		}
	}
	if_error = 0;
	fio.close();
	return (num);
}

void n_puzzle::board::save_to_file(string file_path, int &if_error, int **num, int *sizes, int count) {
	fstream fio;
	fio.open(file_path, ios::trunc | ios::out);
	if (!fio.is_open()) {
		cout << "Error occurred! File not found." << endl;
		if_error = 1;
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
	if_error = 0;
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

void n_puzzle::board::get_empty_index(int **num, int *i_empty) {
	*i_empty = 0;

	while (*i_empty != (n * m)) {
		if (num[*i_empty / m][*i_empty % m] == 0)
			break;
		++*i_empty;
	}
	return;
}

void n_puzzle::board::shuffle_board() {
	cout << "Table is shuffled. Good luck!" << endl;
	num = generate_table(n, m, n_num);
	return;
}

void n_puzzle::board::get_intelligent_movement(char &route) {
	int i_empty, least = n * m, oper;

	get_empty_index(num, &i_empty);
	if ((i_empty - m) >= 0) {
		if (num[(i_empty / m) - 1][i_empty % m] < least) {
			least = num[(i_empty / m) - 1][i_empty % m];
			oper = 1;
		}
	}
	if (((i_empty + 1) % m) != 0) {
		if (num[i_empty / m][(i_empty % m) + 1] < least) {
			least = num[i_empty / m][(i_empty % m) + 1];
			oper = 2;
		}
	}
	if ((i_empty + m) < (n * m)) {
		if (num[(i_empty / m) + 1][i_empty % m] < least) {
			least = num[(i_empty / m) + 1][i_empty % m];
			oper = 3;
		}
	}
	if ((i_empty % m) != 0) {
		if (num[i_empty / m][(i_empty % m) - 1] < least) {
			least = num[i_empty / m][(i_empty % m) - 1];
			oper = 4;
		}
	}
	cout << "Intelligent move chooses ";
	switch (oper) {
	case (1):
		cout << "U" << endl;
		route = 'U';
		break;
	case (2):
		cout << "R" << endl;
		route = 'R';
		break;
	case (3):
		cout << "D" << endl;
		route = 'D';
		break;
	case (4):
		cout << "L" << endl;
		route = 'L';
		break;
	default:
		break;
	}
	return;
}

void n_puzzle::board::get_intelligent_movement_v2(char &route) {
	int i_empty, least = n * m, oper;

	get_empty_index(num, &i_empty);
	if ((i_empty - m) >= 0) {
		if (num[(i_empty / m) - 1][i_empty % m] < least) {
			least = num[(i_empty / m) - 1][i_empty % m];
			oper = 1;
		}
	}
	if (((i_empty + 1) % m) != 0) {
		if (num[i_empty / m][(i_empty % m) + 1] < least) {
			least = num[i_empty / m][(i_empty % m) + 1];
			oper = 2;
		}
	}
	if ((i_empty + m) < (n * m)) {
		if (num[(i_empty / m) + 1][i_empty % m] < least) {
			least = num[(i_empty / m) + 1][i_empty % m];
			oper = 3;
		}
	}
	if ((i_empty % m) != 0) {
		if (num[i_empty / m][(i_empty % m) - 1] < least) {
			least = num[i_empty / m][(i_empty % m) - 1];
			oper = 4;
		}
	}
	cout << "Intelligent move v2 chooses ";
	switch (oper) {
	case (1):
		cout << "U" << endl;
		route = 'U';
		break;
	case (2):
		cout << "R" << endl;
		route = 'R';
		break;
	case (3):
		cout << "D" << endl;
		route = 'D';
		break;
	case (4):
		cout << "L" << endl;
		route = 'L';
		break;
	default:
		break;
	}
	return;
}

void n_puzzle::board::get_random_movement(char &route) {
	int i_empty, oper, sides[4] = {0, 0, 0, 0};

	get_empty_index(num, &i_empty);
	if ((i_empty - m) >= 0)
		sides[0] = 1;
	if (((i_empty + 1) % m) != 0)
		sides[1] = 1;
	if ((i_empty + m) < (n * m))
		sides[2] = 1;
	if ((i_empty % m) != 0)
		sides[3] = 1;
	do {
		oper = (rand() % 4) + 1;
	} while (sides[oper - 1] != 1);
	cout << "Random move chooses ";
	switch (oper) {
	case (1):
		cout << "U" << endl;
		route = 'U';
		break;
	case (2):
		cout << "R" << endl;
		route = 'R';
		break;
	case (3):
		cout << "D" << endl;
		route = 'D';
		break;
	case (4):
		cout << "L" << endl;
		route = 'L';
		break;
	default:
		break;
	}
	return;
}
