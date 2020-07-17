/*
 * Part1.cpp
 * Description: In this assignment, you will design and implement a class
 * hierarchy for the Board class of the NPuzzle problem. You will also write
 * global functions to use these classes.
 * Your AbstractBoard class represents the board configuration as you did in the
 * previous assignments.
 * Fuction Name			Explanation
 * print				Prints the board on the screen by sending it to cout
 * readFromFile			Reads the board from the file given as function
 * 						parameter. The file format is defined as in HW2.
 * writeToFile			Writes the board to the file given as function parameter
 * reset				Resets the board to the solution.
 * setSize				Sets the board size to given values. The values are
 * 						given as parameters and there are no restrictions on the
 * 						board size. The board is reset after this operation.
 * move					Makes a move according to the given char parameter. If
 * 						the parameter is ‘L’ then the blank tiles moves left,
 * 						..., etc, as defined in HW1.
 * isSolved				Returns true if the board is a solution
 * Operator()			Takes two indexes and returns the corresponding cell
 * 						content.Terminates program if the indexes are not valid.
 * Operator==			Two boards are equal, if the boards are the same. This
 * 						operator does not consider last move or the number of
 * 						steps
 * NumberOfBoards		Returns the number of Board objects created so far.
 * lastMove				Returns the last move, if there is no last move, returns
 * 						‘S’
 * numberOfMoves		Returns the number of steps (moves) this board made
 *
 * Many of the functions above cannot be implemented because your do not know
 * how the board is represented in this abstract base class. You will derive 3
 * new concrete classes from this class that represents the boards in different
 * ways:
 * • BoardVector: The Board is represented using an STL vector of STL vectors.
 * • BoardArray1D: The Board is represented using a one dimensional dynamic C
 * array.
 * • BoardArray2D: The Board is represented using a two dimensional dynamic C
 * array.
 * Write global function that takes an array of AbstractBoard pointers and
 * returns true if the array contains a valid sequence of moves for a solution
 *
 *  Created on: Jul 13, 2020
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
	init(0, 0);
	nPuzzleBoard.resize(1);
	m_countObject = 1; //resets no objects, since vector was resized

	nPuzzleBoard[0].setSize();
	nPuzzleBoard[0].generateTable();
	return;
}

void NPuzzle::playNPuzzleGame() {
	m_eachStepValues.push_back(0);
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
	init(0, 0);
	nPuzzleBoard.resize(1);
	m_countObject = 1; //resets no objects, since vector was resized

	nPuzzleBoard[0].readFromFile();
	return;
}

void NPuzzle::writeToFile() {
	nPuzzleBoard[0].writeToFile();
	return;
}

void NPuzzle::shuffle() {
	nPuzzleBoard.resize(1);
	m_countObject = 1; //resets no objects, since vector was resized
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
	m_countObject = 1; //resets no objects, since vector was resized
	nPuzzleBoard[0].getRandomMovement();
	nPuzzleBoard[0].move();
	return;
}

void NPuzzle::moveIntelligent() {
	nPuzzleBoard.resize(1);
	m_countObject = 1; //resets no objects, since vector was resized
	nPuzzleBoard[0].getIntelligentMovement();
	nPuzzleBoard[0].move();
	return;
}

void NPuzzle::move() {
	nPuzzleBoard.resize(1);
	m_countObject = 1; //resets no objects, since vector was resized
	nPuzzleBoard[0].getRegularMovement(m_command);
	nPuzzleBoard[0].move();
	return;
}

void NPuzzle::solvePuzzle() {
	int isAvailable, isSolved = 0, initialLastVector = 0, finalLastVector = 1;
	int nNPBVector = nPuzzleBoard.size();
	int iNPBVector = nNPBVector - 1;

	if (1 <= nPuzzleBoard[nNPBVector - 1].numberOfMoves()) {
		initialLastVector = m_eachStepValues[nPuzzleBoard[nNPBVector - 1].numberOfMoves() - 1] + 1;
		finalLastVector = m_eachStepValues[nPuzzleBoard[nNPBVector - 1].numberOfMoves()] + 1;
	}
	nPuzzleBoard[nNPBVector - 1].incrementNumberOfMoves();
	for (int i = initialLastVector; i < finalLastVector; ++i) {
		nPuzzleBoard[i].getIntelligentMovementV2(U, isAvailable);
		if (isAvailable) {
			init(i, U);
			++iNPBVector;
			nPuzzleBoard[iNPBVector] = nPuzzleBoard[i]; //using operator=
			nPuzzleBoard[iNPBVector].move();
			if (nPuzzleBoard[iNPBVector].isSolved()) {
				isSolved = 1;
				cout << "Solution found in solvePuzzle command number ";
				cout << nPuzzleBoard[nNPBVector - 1].numberOfMoves();
				cout << " with the last moves of (from last to first) ";
				printPrevMove(iNPBVector);
				cout << ". See below the found solution." << endl;
				nPuzzleBoard[iNPBVector].print();
				cout << endl;
			}
		}
		nPuzzleBoard[i].getIntelligentMovementV2(R, isAvailable);
		if (isAvailable) {
			init(i, R);
			++iNPBVector;
			nPuzzleBoard[iNPBVector] = nPuzzleBoard[i]; //using operator=
			nPuzzleBoard[iNPBVector].move();
			if (nPuzzleBoard[iNPBVector].isSolved()) {
				isSolved = 1;
				cout << "Solution found in solvePuzzle command number ";
				cout << nPuzzleBoard[nNPBVector - 1].numberOfMoves();
				cout << " with the last moves of (from last to first) ";
				printPrevMove(iNPBVector);
				cout << ". See below the found solution." << endl;
				nPuzzleBoard[iNPBVector].print();
				cout << endl;
			}
		}
		nPuzzleBoard[i].getIntelligentMovementV2(D, isAvailable);
		if (isAvailable) {
			init(i, D);
			++iNPBVector;
			nPuzzleBoard[iNPBVector] = nPuzzleBoard[i]; //using operator=
			nPuzzleBoard[iNPBVector].move();
			if (nPuzzleBoard[iNPBVector].isSolved()) {
				isSolved = 1;
				cout << "Solution found in solvePuzzle command number ";
				cout << nPuzzleBoard[nNPBVector - 1].numberOfMoves();
				cout << " with the last moves of (from last to first) ";
				printPrevMove(iNPBVector);
				cout << ". See below the found solution." << endl;
				nPuzzleBoard[iNPBVector].print();
				cout << endl;
			}
		}
		nPuzzleBoard[i].getIntelligentMovementV2(L, isAvailable);
		if (isAvailable) {
			init(i, L);
			++iNPBVector;
			nPuzzleBoard[iNPBVector] = nPuzzleBoard[i]; //using operator=
			nPuzzleBoard[iNPBVector].move();
			if (nPuzzleBoard[iNPBVector].isSolved()) {
				isSolved = 1;
				cout << "Solution found in solvePuzzle command number ";
				cout << nPuzzleBoard[nNPBVector - 1].numberOfMoves();
				cout << " with the last moves of (from last to first) ";
				printPrevMove(iNPBVector);
				cout << ". See below the found solution." << endl;
				nPuzzleBoard[iNPBVector].print();
				cout << endl;
			}
		}
	}
	if (!isSolved) {
		cout << "Solution not found yet. ";
		cout << "Please try again solvePuzzle command." << endl << endl;
	}
	m_eachStepValues.push_back(iNPBVector);
	return;
}

void NPuzzle::printPrevMove(int i) {
	int prevBoard;

	while (i != 0) {
		cout << nPuzzleBoard[i].lastMove();
		nPuzzleBoard[i].getPrevBoard(prevBoard);
		i = prevBoard;
		if (i != 0)
			cout << " ";
	}
	return;
}

void NPuzzle::init(int iRootBoard, int prevMove) {
	BoardVector nextBoard(++m_countObject, iRootBoard, prevMove);
	nPuzzleBoard.push_back(nextBoard);
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
		m_sizes.push_back(m_nRow);
		m_sizes.push_back(m_nColumn);
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

int NPuzzle::Board::numberOfBoards() {
	return m_iObject;
}

char NPuzzle::Board::lastMove() {
	char lastMoveChar;

	switch (m_prevMove)	{
		case (U):
			lastMoveChar = static_cast<char>(UP);
			break;
		case (R):
			lastMoveChar = static_cast<char>(RIGHT);
			break;
		case (D):
			lastMoveChar = static_cast<char>(DOWN);
			break;
		case (L):
			lastMoveChar = static_cast<char>(LEFT);
			break;
		default:
			//returns S letter, if there is no previous move
			lastMoveChar = static_cast<char>(NOMOVE);
			break;
	}
	return lastMoveChar;
}

void NPuzzle::Board::incrementNumberOfMoves() {
	++m_iMove;
}

int NPuzzle::Board::numberOfMoves() {
	return m_iMove;
}

void NPuzzle::Board::printStatus() {
	cout << m_count << " moves have been done. ";
	if (m_isDone)
		cout << "Solution has been found already." << endl;
	else
		cout << "Solution has not been found yet. Keep going!" << endl;
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

void NPuzzle::Board::getIntelligentMovementV2(const int& route, int& isAvailable) {
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

void NPuzzle::Board::getPrevBoard(int& prevBoard) {
	prevBoard = m_iRootBoard;
	return;
}

void NPuzzle::Board::getBoardSettings(int& nRow, int& nColumn) {
	nRow = m_nRow;
	nColumn = m_nColumn;
	return;
}

//operator overloading method
ostream& operator >>(ostream& output, NPuzzle& nPuzzleObject) {
	int nRow, nColumn;

	nPuzzleObject.nPuzzleBoard[0].getBoardSettings(nRow, nColumn);
	for (int i = 0; i < nRow; ++i) {
		for (int j = 0; j < nColumn; ++j) {
			if (nPuzzleObject.nPuzzleBoard[0].printElements(i, j) == REGULARZERO) {
				output << "bb" << " ";
			} else if (nPuzzleObject.nPuzzleBoard[0].printElements(i, j) == FILLEDZERO) {
				output << "00" << " ";
			} else {
				if (nPuzzleObject.nPuzzleBoard[0].printElements(i, j) <= MAXSINGLEDIGITNUMBER)
					output << "0";
				output << nPuzzleObject.nPuzzleBoard[0].printElements(i, j) << " ";
			}
		}
		output << endl;
	}
	return output;
}

//operator overloading method
istream& operator <<(istream& input, NPuzzle& nPuzzleObject) {
	int elementValue, iZeros;
	int nRow, nColumn;

	nPuzzleObject.nPuzzleBoard[0].getBoardSettings(nRow, nColumn);
	system("clear");
	cout << "Please enter the new board configuration to be overwritten on the ";
	cout << "last one. Total of ";
	cout << nRow * nColumn;
	cout << " elements are required to be submitted." << endl;
	while (1) {
		cout << "You can hit enter after each element. ";
		cout << "Please note that bb denoted by " << REGULARZERO;
		cout << " and 0 denoted by " << FILLEDZERO << "." << endl;
		iZeros = 0;
		for (int i = 0; i < nRow; ++i) {
			for (int j = 0; j < nColumn; ++j) {
				input >> elementValue;
				if (elementValue == REGULARZERO)
					++iZeros;
				nPuzzleObject.nPuzzleBoard[0].editElements(i, j, elementValue);
			}
		}
		if (iZeros != 1) {
			system("clear");
			cout << "There should be only one " << REGULARZERO << " on the board. ";
			cout << "Please try again accordingly." << endl;
		} else {
			break;
		}
	}
	return input;
}
