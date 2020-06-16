/*
 * Part1.cpp
 * Description: In this homework, you will make additions to your N-Puzzle
 * program. We will write an exhaustive search algorithm that will find the best
 * solution even if it takes too long to do so.
 * Your main class will be named NPuzzle. It will have the following public
 * functions, most of which are the same as HW3 (changes are marked with bold
 * letters)
 * Fuction Name		Explanation
 * print			Prints the current configuration on the screen by sending it
 * 					to cout
 * printReport		Prints a report about how many moves have been done since
 * 					reset and if the solution is found
 * readFromFile		Reads the current configuration from the file given as
 * 					function parameter. The file format is defined as in HW2.
 * 					The vector of Board objects is resized to 1. See below for
 * 					details.
 * writeToFile		Writes the current configuration to the file given as
 * 					function parameter.
 * shuffle			Makes N random moves to shuffle the board. N is given as a
 * 					function parameter. The vector of Board objects is resized
 * 					to 1. See below for details.
 * reset			Resets the current configuration to the solution. The vector
 * 					of Board objects is resized to 0.
 * setsize			Sets the board size to given values. The values are given as
 * 					parameters and they can be at most 9x9. After setting the
 * 					size, the boards should be reset.
 * moveRandom		Makes a valid random move. Move is recorded in vector of
 * 					Board objects. The vector of Board objects is resized to 1.
 * 					See below for details.
 * move				Makes a move according to the given char parameter. If the
 * 					parameters is ‘L’ then, the blank tiles moves left, ...,
 * 					etc, as defined in HW1. Move is recorded in vector of Board
 * 					objects. The vector of Board objects is resized to 1. See
 * 					below for details.
 * solvePuzzle		Runs the algorithm described below to solve the problem in
 * 					optimal number of steps.
 * Operator>>		Prints the current configuration on the screen by sending it
 * 					to ostream object
 * Operator<<		Reads the current configuration from the istream object. The
 * 					file format is defined as in HW2.
 *
 * Your NPuzzle class defines and uses a private inner class named Board, which
 * represents the board configuration using a private 2D Vector. The class also
 * has two other data members
 * • The last move that it has performed
 * • The number of moves make on this board from the beginning.
 * Your NPuzzle class does not use any other data to represent the board. This
 * class defines the following functions, most of which are the same as HW3
 * (changes are marked with bold letters)
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
 * 					parameter is ‘L’ then the blank tiles moves left, ..., etc,
 * 					as defined in HW1.
 * isSolved			Returns true if the board is a solution
 * Operator()		Takes two indexes and returns the corresponding cell
 * 					content. Terminates program if the indexes are not valid.
 * Operator==		Two boards are equal, if the boards are the same. This
 * 					operator does not consider last move or the number of steps
 * NumberOfBoards	Returns the number of Board objects created so far.
 * lastMove			Returns the last move, if there is no last move, returns ‘S’
 * numberOfMoves	Returns the number of steps (moves) this board made
 *
 * Your program will use objects of NPuzzle to perform what we did previously in
 * HW3. Your command line options and your user interface is very similar. The
 * following table is repeated here just for convenience.
 * Input	Action
 * V		Solves the problem from the current configuration using the new
 * 			algorithm.
 * T		Prints a report about how many moves have been done and if the
 * 			solution is found
 * E		Asks a file name and saves the current board configuration as a
 * 			loadable shape file.
 * O		Asks a file name and loads the current board configuration from the
 * 			shape file.
 * L		moves the empty cell left if there is room
 * R		moves the empty cell right if there is room
 * U		moves the empty cell up if there is room
 * D		moves the empty cell down if there is room
 * S		Shuffle- takes the board to the final solution, and makes size*size
 * 			random moves to shuffle the board.
 *
 * Your new algorithm follows these steps
 * 1. Your NPuzzle class keeps a vector of Board objects. Initially this vector
 * contains a single object that contains either the board from a file or
 * shuffled board. The number of steps of this board is 0.
 * 2. Take the first element from this vector,
 * 3. Apply all possible moves to this board and push_back each result back to
 * the vector. Before doing the push back, you should check if the same board is
 * already in the vector. If one of the pushed objects is the solution, then
 * your solution is found.
 * 4. Take another element from the vector in order and go to step 3.
 *
 * Note that the above algorithm can stop in two cases: solution is found or
 * there are no elements to take from the vector. We expect that if there is a
 * solution, we will find it. In order to demonstrate the algorithm better,
 * assume the initial 3x3 board vector in step 1 contains
 * 1 2 3
 * 4   5
 * 7 8 6
 * Which will be represented as {((1234b5789),S,0)}, where S is the last move, 0
 * is the number of moves. Step 2 takes this board and pushes back 4 new boards
 * to the vector
 * {((1234b5786),S,0), ((12345b786),R,1), ((123b45786),L,1), ((1b3425786),U,1),
 * ((1234857b6),D,1)}
 * Note that bold letters indicate the vector elements that are not chosen from
 * the vector yet. Since, we did not see the solution, we will pick the next
 * element from the vector and go to step 3, which yields
 * {((1234b5786),S,0), ((12345b786),R,1), ((123b45786),L,1), ((1b3425786),U,1),
 * ((1234857b6),D,1), ((12b453786),U,2), ((12345678b),D,2) }
 * We see that one of the newly added elements is the solution. We terminate the
 * algorithm. From the solution, we can go back to the original board by
 * applying the inverse moves U and L. We see that the solution needs just two
 * moves.
 *
 *  Created on: Jun 15, 2020
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
	init();
	nPuzzleBoard.resize(1);

	nPuzzleBoard[0].setSize();
	nPuzzleBoard[0].generateTable();
//	playNPuzzleGame();
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
	nPuzzleBoard[0].print();
	return;
}

void NPuzzle::printReport() {
	nPuzzleBoard[0].printStatus();
	return;
}

void NPuzzle::readFromFile() {
	init();
	nPuzzleBoard.resize(1);
	nPuzzleBoard[0].readFromFile();
//	playNPuzzleGame();
	return;
}

void NPuzzle::writeToFile() {
	nPuzzleBoard[0].writeToFile();
	return;
}

void NPuzzle::shuffle() {
	nPuzzleBoard.resize(1);
	nPuzzleBoard[0].shuffleBoard();
	return;
}

void NPuzzle::reset() {
	nPuzzleBoard[0].reset();
	return;
}

void NPuzzle::setsize() {
	nPuzzleBoard[0].setSize();
	return;
}

void NPuzzle::moveRandom() {
	nPuzzleBoard.resize(1);
	nPuzzleBoard[0].getRandomMovement();
	nPuzzleBoard[0].move();
	return;
}

void NPuzzle::moveIntelligent() {
	nPuzzleBoard.resize(1);
	nPuzzleBoard[0].getIntelligentMovement();
	nPuzzleBoard[0].move();
	return;
}

void NPuzzle::move() {
	nPuzzleBoard.resize(1);
	nPuzzleBoard[0].getRegularMovement(m_command);
	nPuzzleBoard[0].move();
	return;
}

void NPuzzle::solvePuzzle() {
	int isAvailable;
	int nPBVectorSize = nPuzzleBoard.size();
	int iPBVector = nPBVectorSize - 1;
	cout << "size1: " << nPuzzleBoard.size() << endl;
	nPuzzleBoard[nPBVectorSize - 1].getIntelligentMovementV2(U, isAvailable);
	if (isAvailable) {
		init();
		++iPBVector;
		cout << "iPBV1: " << iPBVector << endl;
		nPuzzleBoard[iPBVector] = nPuzzleBoard[nPBVectorSize - 1];
		nPuzzleBoard[iPBVector].move();
	}
	nPuzzleBoard[nPBVectorSize - 1].getIntelligentMovementV2(R, isAvailable);
	if (isAvailable) {
		init();
		++iPBVector;
		cout << "iPBV2: " << iPBVector << endl;
		nPuzzleBoard[iPBVector] = nPuzzleBoard[nPBVectorSize - 1];
		nPuzzleBoard[iPBVector].move();
	}
	nPuzzleBoard[nPBVectorSize - 1].getIntelligentMovementV2(D, isAvailable);
	if (isAvailable) {
		init();
		++iPBVector;
		cout << "iPBV3: " << iPBVector << endl;
		nPuzzleBoard[iPBVector] = nPuzzleBoard[nPBVectorSize - 1];
		nPuzzleBoard[iPBVector].move();
	}
	nPuzzleBoard[nPBVectorSize - 1].getIntelligentMovementV2(L, isAvailable);
	if (isAvailable) {
		init();
		++iPBVector;
		cout << "iPBV4: " << iPBVector << endl;
		nPuzzleBoard[iPBVector] = nPuzzleBoard[nPBVectorSize - 1];
		nPuzzleBoard[iPBVector].move();
	}
	cout << "size2: " << nPuzzleBoard.size() << endl;
	return;
}

void NPuzzle::Board::print() {
	for (int i = 0; i < m_nRow; ++i) {
		for (int j = 0; j < m_nColumn; ++j) {
			if (m_num[i][j] == REGULARZERO) {
				cout << "bb" << " ";
			} else if (m_num[i][j] == FILLEDZERO) {
				cout << "00" << " ";
			} else {
				if (m_num[i][j] <= MAXSINGLEDIGITNUMBER)
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
				m_num[i][j] = FILLEDZERO;
			++iNum;
		}
	}
	return;
}

void NPuzzle::Board::setSize(){
	while (1) {
		cout << "Please enter the N size of the game to be built N-by-M table" << endl;
		cin >> m_nRow;
		if (!(MINSIZES <= m_nRow && m_nRow <= MAXSIZES))
			cout << "Table sizes can only have values from 2 to 9. Please try again accordingly." << endl;
		else {
			break;
		}
	}
	while (1) {
		cout << "Please enter the M size of the game to be built N-by-M table" << endl;
		cin >> m_nColumn;
		if (!(MINSIZES <= m_nColumn && m_nColumn <= MAXSIZES))
			cout << "Table sizes can only have values from 2 to 9. Please try again accordingly." << endl;
		else {
			break;
		}
	}
	while (1) {
		cout << "Please enter the number of numbers on the table. Rest will be zeros." << endl;
		cin >> m_nNum;
		if (!(MINnNUM <= m_nNum && m_nNum <= (m_nRow * m_nColumn))) {
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
		m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn] = REGULARZERO;
		++m_count;
		break;
	case R:
		if (((m_iEmpty + 1) % m_nColumn) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl << endl;
			break;
		}
		m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1];
		m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1] = REGULARZERO;
		++m_count;
		break;
	case D:
		if ((m_iEmpty + m_nColumn) >= (m_nRow * m_nColumn)) {
			cout << "Error occurred! Target direction is invalid." << endl << endl;
			break;
		}
		m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] = m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn];
		m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn] = REGULARZERO;
		++m_count;
		break;
	case L:
		if ((m_iEmpty % m_nColumn) == 0) {
			cout << "Error occurred! Target direction is invalid." << endl << endl;
			break;
		}
		m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1];
		m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1] = REGULARZERO;
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
	int i, iRow = 0, iColumn = 0, iSizes = 0, iLine = 0;
	char c, strTemp[LENGTHSTRTEMP];
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
			++iLine;
		} else if (c != ' ' && iLine == LINENUM) {
			while (c != ' ') {
				strTemp[i] = c;
				fIO.get(c);
				++i;
			}
			strTemp[i] = '\0';
			string str(strTemp);
			m_num[iRow][iColumn] = stringIntConverter(strTemp);
			if (m_num[iRow][iColumn] != FILLEDZERO)
				++m_nNum;
			if (iColumn == (m_sizes[1] - 1)) {
				++iRow;
				iColumn = 0;
			} else {
				++iColumn;
			}
		} else if (c != ' ' && iLine == LINESIZES) {
			while (c != ' ') {
				strTemp[i] = c;
				fIO.get(c);
				++i;
			}
			strTemp[i] = '\0';
			string str(strTemp);
			m_sizes[iSizes] = stringIntConverter(strTemp);
			if (iSizes == 0) {
				m_num = (int**)realloc(m_num, m_sizes[0] * sizeof(*m_num));
			} else if (iSizes == 1) {
				for (int j = 0; j < m_sizes[0]; ++j) {
					m_num[j] = (int*)malloc(m_sizes[1] * sizeof(int));
				}
			}
			++iSizes;
		} else if (c != ' ' && iLine == LINECOUNT) {
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
		intValue += ((numStr[i] - ASCIINUMBERDIFFERENCE) * multiplier);
		multiplier *= 10; //tenth part selector
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
			// FILLEDZERO (-2) will represent zeros on the table
			m_num[iNum / m_nColumn][iNum % m_nColumn] = FILLEDZERO;
		}
		++iNum;
	}
}

void NPuzzle::Board::getEmptyIndex() {
	m_iEmpty = 0;
	while (m_iEmpty != (m_nRow * m_nColumn)) {
		if (m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] == REGULARZERO)
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

void NPuzzle::Board::getIntelligentMovementV2(const int& route, int& isAvailable) {
//	int least = m_nRow * m_nColumn;


	getEmptyIndex();
	switch (route) {
	case U:
		if ((m_iEmpty - m_nColumn) >= 0) {
			isAvailable = 1;
			m_oper = U;
		} else {
			isAvailable = 0;
		}
		break;
	case R:
		if (((m_iEmpty + 1) % m_nColumn) != 0) {
			isAvailable = 1;
			m_oper = R;
		} else {
			isAvailable = 0;
		}
		break;
	case D:
		if ((m_iEmpty + m_nColumn) < (m_nRow * m_nColumn)) {
			isAvailable = 1;
			m_oper = D;
		} else {
			isAvailable = 0;
		}
		break;
	case L:
		if ((m_iEmpty % m_nColumn) != 0) {
			isAvailable = 1;
			m_oper = L;
		} else {
			isAvailable = 0;
		}
		break;
	default:
		break;
	}
//	if ((m_iEmpty - m_nColumn) >= 0) {
//		if (m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn] < least) {
//			least = m_num[(m_iEmpty / m_nColumn) - 1][m_iEmpty % m_nColumn];
//			m_oper = U;
//		}
//	}
//	if (((m_iEmpty + 1) % m_nColumn) != 0) {
//		if (m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1] < least) {
//			least = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) + 1];
//			m_oper = R;
//		}
//	}
//	if ((m_iEmpty + m_nColumn) < (m_nRow * m_nColumn)) {
//		if (m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn] < least) {
//			least = m_num[(m_iEmpty / m_nColumn) + 1][m_iEmpty % m_nColumn];
//			m_oper = D;
//		}
//	}
//	if ((m_iEmpty % m_nColumn) != 0) {
//		if (m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1] < least) {
//			least = m_num[m_iEmpty / m_nColumn][(m_iEmpty % m_nColumn) - 1];
//			m_oper = L;
//		}
//	}
//	cout << "Solve puzzle move chooses ";
//	getChosenRouteName();
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
