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
#include <fstream>
#include <string>
#include "Part1.h"
using namespace std;

class n_puzzle {
public:
	void print();
	void printReport(); //
	void readFromFile();
	void writeToFile();
	void shuffle(); //
	void reset();
	void setsize();
	void moveRandom(); //
	void moveIntelligent(); //
	void move();
	void solvePuzzle(); //

	class board {
	public:
		void print();
		void readFromFile();
		void writeToFile();
		void reset();
		void setSize();
		void move();
		void isSolved();

	private:
		//int num[9] = {1, 2, 3, 0, 5, 6, 4, 8, 7};
		int *num;
		int n, m;
		int n_num = 0;
		int if_error = 0;
		int sizes[2];
		string file_path;
		int count = 0;
	};
private:

	int if_done = 0;
};

void n_puzzle_game_oop() {
	n_puzzle::board new_board;
	//new_board.printReport();
	new_board.readFromFile();
	new_board.print();
	//new_board.writeToFile();
	//new_board.shuffle();
	new_board.reset();
	new_board.print();
}

void n_puzzle::board::print() {
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
		num = get_from_file(file_path, &if_error, sizes, &count, &n_num);
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
int* get_from_file(std::string file_path, int *if_error, int *sizes, int *count, int *n_num) {
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
			//cout << i_num << ": " << num[i_num] << endl;
			++i_num;
			++*n_num;
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
			//cout << sizes[i_sizes] << endl;
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
			//cout << *count << endl;
		}
	}
	num[i_num] = -1;
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

/*
void n_puzzle::shuffle() {
	cout << "Table is shuffled. Good luck!" << endl;
	num = generate_table(n, m, n_num);
	return;
}
*/

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

void n_puzzle::board::reset() {
	int i_num = 0;

	cout << "Table is reseted to the solution." << endl;
	while (i_num < (n * m)) {
		if (i_num < n_num) {
			num[i_num] = i_num + 1;
		} else {
			/* -2 will represent zeros on the table */
			num[i_num] = -2;
		}
		++i_num;
	}
	num[n_num - 1] = 0;
	num[i_num] = -1;
	return;
}

