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

void NPuzzle::buildNewTable() {
	nPuzzleBoard.setSize();
	nPuzzleBoard.generateTable();
	return;
}

void NPuzzle::playNPuzzleGame() {
	while (1) {
		cout << "Use the initial letter of your wished navigation direction like Up (U), Down (D), Left (L), Rigth (R)." << endl;
		cout << "You can quit any time using Q or shuffle the table using S. Have fun!" << endl;
		print();
		cin >> m_command;
		//converts lower case letter to upper case
		if (aVALUE <= m_command && m_command <= zVALUE)
			m_command -= LOWERCASEUPPERCASEDIFFERENCE;
		system("clear");
		switch (m_command) {
		case QUIT:
			break;
		case SHUFFLE:
			shuffle();
			break;
		case UP:
		case RIGHT:
		case DOWN:
		case LEFT:
			move();
			break;
		case INTELLIGENT:
			moveIntelligent();
			break;
		case SOLVEPUZZLE:
			solvePuzzle();
			break;
		case PRINTREPORT:
			printReport();
			break;
		case WRITETOFILE:
			writeToFile();
			break;
		case READFROMFILE:
			readFromFile();
			break;
		case MOVERANDOM:
			moveRandom();
			break;
		case RESET:
			reset();
			break;
		default:
			cout << "Error occurred! You entered an invalid input. Please try again." << endl;
			break;
		}
		if (m_command == QUIT)
			break;
	}
	return;
}

void NPuzzle::print() {
	nPuzzleBoard.print();
	return;
}

void NPuzzle::printReport() {
	nPuzzleBoard.printStatus();
	return;
}

void NPuzzle::readFromFile() {
	nPuzzleBoard.readFromFile();
	return;
}

void NPuzzle::writeToFile() {
	nPuzzleBoard.writeToFile();
	return;
}

void NPuzzle::shuffle() {
	nPuzzleBoard.shuffleBoard();
	return;
}

void NPuzzle::reset() {
	nPuzzleBoard.reset();
	return;
}

void NPuzzle::setsize() {
	nPuzzleBoard.setSize();
	return;
}

void NPuzzle::moveRandom() {
	nPuzzleBoard.getRandomMovement();
	nPuzzleBoard.move();
	return;
}

void NPuzzle::moveIntelligent() {
	nPuzzleBoard.getIntelligentMovement();
	nPuzzleBoard.move();
	return;
}

void NPuzzle::move() {
	nPuzzleBoard.getRegularMovement(m_command);
	nPuzzleBoard.move();
	return;
}

void NPuzzle::solvePuzzle() {
	nPuzzleBoard.getIntelligentMovementV2();
	nPuzzleBoard.move();
	return;
}


void NPuzzle::Board::print() {
	for (int i = 0; i < m_nRow; ++i) {
		for (int j = 0; j < m_nColumn; ++j) {
			if (m_num[i][j] == 0) {
				cout << "bb" << " ";
			} else if (m_num[i][j] == -2) {
				cout << "00" << " ";
			} else {
				if (m_num[i][j] < 10)
					cout << "0";
				cout << m_num[i][j] << " ";
			}
		}
		cout << endl;
	}
	return;
}

void NPuzzle::Board::readFromFile() {
	system("clear");
	while (1) {
		cout << "Please enter the name of file that has the data of saved game." << endl;
		cout << "For e.g: n_puzzle_game.txt" << endl;
		cin >> m_filePath;
		getFromFile();
		system("clear");
		if (m_isError) {
			cout << "File path is invalid. Please try again." << endl;
		} else {
			m_nRow = m_sizes[0];
			m_nColumn = m_sizes[1];
			cout << "Saved " << m_nRow << "-by-" << m_nColumn << " table is loaded below. " << endl << endl;
			break;
		}
	}
	return;
}

void NPuzzle::Board::writeToFile() {
	while (1) {
		cout << "Please enter the name of file that has the data of saved game." << endl;
		cout << "For e.g: n_puzzle_game.txt" << endl;
		cin >> m_filePath;
		m_sizes[0] = m_nRow;
		m_sizes[1] = m_nColumn;
		saveToFile();
		if (m_isError)
			cout << "File path is invalid. Please try again." << endl;
		else {
			cout << "Game configurations saved successfully. ";
			break;
		}
	}
	return;
}

void NPuzzle::Board::reset() {
	int iNum = 0;

	cout << "Table is reseted to the solution." << endl;
	for (int i = 0; i < m_nRow; ++i) {
		for (int j = 0; j < m_nColumn; ++j) {
			if (iNum < m_nNum - 1)
				m_num[i][j] = iNum + 1;
			else if (iNum == m_nNum - 1)
				m_num[i][j] = 0;
			else
				m_num[i][j] = -2;
			++iNum;
		}
	}
	return;
}

void NPuzzle::Board::setSize(){
	while (1) {
		cout << "Please enter the N size of the game to be built N-by-M table" << endl;
		cin >> m_nRow;
		if (m_nRow < 2 || m_nRow > 9)
			cout << "Table sizes can only have values from 2 to 9. Please try again accordingly." << endl;
		else {
			break;
		}
	}
	while (1) {
		cout << "Please enter the M size of the game to be built N-by-M table" << endl;
		cin >> m_nColumn;
		if (m_nColumn < 2 || m_nColumn > 9)
			cout << "Table sizes can only have values from 2 to 9. Please try again accordingly." << endl;
		else {
			break;
		}
	}
	while (1) {
		cout << "Please enter the number of numbers on the table. Rest will be zeros." << endl;
		cin >> m_nNum;
		if (m_nNum > (m_nRow * m_nColumn) || m_nNum <= 1) {
			cout << "Number of numbers has to be from 2 to " << (m_nRow * m_nColumn);
			cout << ".Please try again accordingly." << endl;
		} else {
			cout << m_nRow << "-by-" << m_nColumn << " table with " << ((m_nRow * m_nColumn) - m_nNum);
			cout << " zeros is generated below. ";
			break;
		}
	}
	return;
}

void NPuzzle::Board::move() {
	getEmptyIndex();
	switch (m_oper) {
	case U:
		if ((m_iEmpty - m_nColumn) < 0) {
			cout << "Error occurred! Target direction is invalid." << endl << endl;
			break;
		}
		m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] = m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn];
		m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn] = 0;
		++m_count;
		break;
	case R:
		if (((m_iEmpty + 1) % m_nColumn) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl << endl;
			break;
		}
		m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1];
		m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1] = 0;
		++m_count;
		break;
	case D:
		if ((m_iEmpty + m_nColumn) >= (m_nRow * m_nColumn)) {
			cout << "Error occurred! Target direction is invalid." << endl << endl;
			break;
		}
		m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] = m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn];
		m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn] = 0;
		++m_count;
		break;
	case L:
		if ((m_iEmpty % m_nColumn) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl << endl;
			break;
		}
		m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1];
		m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1] = 0;
		++m_count;
		break;
	}
	isSolved();
	if (m_isDone) {
		cout << "Problem solved!" << endl;
	}
	return;
}

void NPuzzle::Board::isSolved() {
	m_isDone = 1;
	/* checks if numbers in indices for e.g (3-by-3 game) 0 to 7 are in order */
	for (int i = 1; i < m_nNum - 1; ++i) {
		if (m_num[(i - 1) / m_nColumn][(i - 1) % m_nColumn] > m_num[i / m_nColumn][i % m_nColumn]) {
			m_isDone = 0;
			break;
		}
	}
	return;
}

void NPuzzle::Board::printStatus() {
	cout << m_count << " moves have been done. ";
	if (m_isDone)
		cout << "Solution has been found already." << endl;
	else
		cout << "Solution has not been found yet. Keep going!" << endl;
	return;
}

void NPuzzle::Board::getFromFile() {
	int i, i_row = 0, i_col = 0, i_sizes = 0, i_line = 0;
	char c, strTemp[5];
	m_nNum = 0;
	fstream fIO;
	fIO.open(m_filePath, ios::in);
	if (!fIO.is_open()) {
		cout << "Error occurred! File not found." << endl;
		m_isError = 1;
		return;
	}
	while (!fIO.eof()) {
		fIO.get(c);
		i = 0;
		if (c == '\n') {
			++i_line;
		} else if (c != ' ' && i_line == 2) {
			while (c != ' ') {
				strTemp[i] = c;
				fIO.get(c);
				++i;
			}
			strTemp[i] = '\0';
			string str(strTemp);
			m_num[i_row][i_col] = stringIntConverter(strTemp);
			if (m_num[i_row][i_col] != -2)
				++m_nNum;
			if (i_col == (m_sizes[1] - 1)) {
				++i_row;
				i_col = 0;
			} else {
				++i_col;
			}
		} else if (c != ' ' && i_line == 0) {
			while (c != ' ') {
				strTemp[i] = c;
				fIO.get(c);
				++i;
			}
			strTemp[i] = '\0';
			string str(strTemp);
			m_sizes[i_sizes] = stringIntConverter(strTemp);
			if (i_sizes == 0) {
				m_num = (int**)realloc(m_num, m_sizes[0] * sizeof(*m_num));
			} else if (i_sizes == 1) {
				for (int j = 0; j < m_sizes[0]; ++j) {
					m_num[j] = (int*)malloc(m_sizes[1] * sizeof(int));
				}
			}
			++i_sizes;
		} else if (c != ' ' && i_line == 1) {
			while (c != ' ') {
				strTemp[i] = c;
				fIO.get(c);
				++i;
			}
			strTemp[i] = '\0';
			string str(strTemp);
			m_count = stringIntConverter(strTemp);
		}
	}
	m_isError = 0;
	fIO.close();
	return;
}

void NPuzzle::Board::saveToFile() {
	fstream fIO;
	fIO.open(m_filePath, ios::trunc | ios::out);
	if (!fIO.is_open()) {
		cout << "Error occurred! File not found." << endl;
		m_isError = 1;
		return;
	}
	/* n and m sizes */
	fIO << m_sizes[0] << " " << m_sizes[1] << " ";
	/* number of moves */
	fIO << endl << m_count << " " << endl;
	/* num data */
	for (int i = 0; i < m_sizes[0]; ++i) {
		for (int j = 0; j < m_sizes[1]; ++j) {
			fIO << m_num[i][j] << " ";
		}
	}
	fIO.close();
	m_isError = 0;
	return;
}

int NPuzzle::Board::stringIntConverter(const string& numStr) {
	int intValue = 0, multiplier = 1;

	for (int i = numStr.length() - 1; i >= 0; --i) {
		if (numStr[i] == '-') {
			intValue *= -1;
			continue;
		}
		intValue += ((numStr[i] - 48) * multiplier);
		multiplier *= 10;
	}
	return (intValue);
}

void NPuzzle::Board::generateTable() {
	int iNum = 0, isSame, randNum, iNumTemp;
	int numTemp[m_nNum];

	m_num = (int**)realloc(m_num, m_nRow * sizeof(*m_num));
	for (int j = 0; j < m_nRow; ++j) {
		m_num[j] = (int*)malloc(m_nColumn * sizeof(int));
	}
	while (iNum < (m_nRow * m_nColumn)) {
		if (iNum < m_nNum) {
			isSame = 0;
			randNum = rand() % m_nNum;
			iNumTemp = iNum - 1;
			while (iNumTemp >= 0) {
				if (randNum == numTemp[iNumTemp]) {
					isSame = 1;
					break;
				}
				--iNumTemp;
			}
			if (isSame)
				continue;
			numTemp[iNum] = randNum;
			m_num[iNum / m_nColumn][iNum % m_nColumn] = randNum;
		} else {
			// -2 will represent zeros on the table
			m_num[iNum / m_nColumn][iNum % m_nColumn] = -2;
		}
		++iNum;
	}
}

void NPuzzle::Board::getEmptyIndex() {
	m_iEmpty = 0;
	while (m_iEmpty != (m_nRow * m_nColumn)) {
		if (m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] == 0)
			break;
		++m_iEmpty;
	}
	return;
}

void NPuzzle::Board::shuffleBoard() {
	cout << "Table is shuffled. Good luck!" << endl;
	m_count = 0;
	generateTable();
	return;
}

void NPuzzle::Board::getRegularMovement(const char& route) {
	switch (route) {
	case UP:
		m_oper = U; //Up
		break;
	case RIGHT:
		m_oper = R; //Right
		break;
	case DOWN:
		m_oper = D; //Down
		break;
	case LEFT:
		m_oper = L; //Left
		break;
	default:
		break;
	}
}

void NPuzzle::Board::getIntelligentMovement() {
	int least = m_nRow * m_nColumn;

	getEmptyIndex();
	if ((m_iEmpty - m_nColumn) >= 0) {
		if (m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn] < least) {
			least = m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn];
			m_oper = U;
		}
	}
	if (((m_iEmpty + 1) % m_nColumn) != 0) {
		if (m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1] < least) {
			least = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1];
			m_oper = R;
		}
	}
	if ((m_iEmpty + m_nColumn) < (m_nRow * m_nColumn)) {
		if (m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn] < least) {
			least = m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn];
			m_oper = D;
		}
	}
	if ((m_iEmpty % m_nColumn) != 0) {
		if (m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1] < least) {
			least = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1];
			m_oper = L;
		}
	}
	cout << "Intelligent move chooses ";
	getChosenRouteName();
	return;
}

void NPuzzle::Board::getIntelligentMovementV2() {
	int least = m_nRow * m_nColumn;

	getEmptyIndex();
	if ((m_iEmpty - m_nColumn) >= 0) {
		if (m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn] < least) {
			least = m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn];
			m_oper = U;
		}
	}
	if (((m_iEmpty + 1) % m_nColumn) != 0) {
		if (m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1] < least) {
			least = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1];
			m_oper = R;
		}
	}
	if ((m_iEmpty + m_nColumn) < (m_nRow * m_nColumn)) {
		if (m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn] < least) {
			least = m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn];
			m_oper = D;
		}
	}
	if ((m_iEmpty % m_nColumn) != 0) {
		if (m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1] < least) {
			least = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1];
			m_oper = L;
		}
	}
	cout << "Solve puzzle move chooses ";
	getChosenRouteName();
	return;
}

void NPuzzle::Board::getRandomMovement() {
	int sides[4] = {0, 0, 0, 0};

	getEmptyIndex();
	if ((m_iEmpty - m_nColumn) >= 0)
		sides[0] = 1;
	if (((m_iEmpty + 1) % m_nColumn) != 0)
		sides[1] = 1;
	if ((m_iEmpty + m_nColumn) < (m_nRow * m_nColumn))
		sides[2] = 1;
	if ((m_iEmpty % m_nColumn) != 0)
		sides[3] = 1;
	do {
		m_oper = (rand() % 4) + 1;
	} while (sides[m_oper - 1] != 1);
	cout << "Random move chooses ";
	getChosenRouteName();
	return;
}

void NPuzzle::Board::getChosenRouteName() {
	switch (m_oper) {
	case U:
		cout << "Up" << endl;
		break;
	case R:
		cout << "Right" << endl;
		break;
	case D:
		cout << "Down" << endl;
		break;
	case L:
		cout << "Left" << endl;
		break;
	default:
		break;
	}
	return;
}
