/*
 * Part1a.cpp
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

void NPuzzle::BoardVector::print() {
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

void NPuzzle::BoardVector::reset() {
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

void NPuzzle::BoardVector::move() {
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
	if (isSolved()) {
		cout << "Problem solved!" << endl;
	}
	return;
}

int NPuzzle::BoardVector::isSolved() {
	m_isDone = 1;
	//checks if numbers in indices for e.g (3-by-3 game) 0 to 7 are in order
	for (int i = 1; i < m_nNum - 1; ++i) {
		if (m_num[(i - 1) / m_nColumn][(i - 1) % m_nColumn] > m_num[i / m_nColumn][i % m_nColumn]) {
			m_isDone = 0;
			break;
		}
	}
	return m_isDone;
}

void NPuzzle::BoardVector::getFromFile() {
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
			m_num[iRow].push_back(stringIntConverter(strTemp));
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
			m_sizes.push_back(stringIntConverter(strTemp));
			if (iSizes == 1)
				for (int j = 0; j < m_sizes[0]; ++j)
					m_num.push_back(std::vector<int>());
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

void NPuzzle::BoardVector::saveToFile() {
	fstream fIO;
	fIO.open(m_filePath, ios::trunc | ios::out);
	if (!fIO.is_open()) {
		cout << "Error occurred! File not found." << endl;
		m_isError = 1;
		return;
	}
	//n and m sizes
	fIO << m_sizes[0] << " " << m_sizes[1] << " ";
	//number of moves
	fIO << endl << m_count << " " << endl;
	//num data
	for (int i = 0; i < m_sizes[0]; ++i) {
		for (int j = 0; j < m_sizes[1]; ++j) {
			fIO << m_num[i][j] << " ";
		}
	}
	fIO.close();
	m_isError = 0;
	return;
}

void NPuzzle::BoardVector::getEmptyIndex() {
	m_iEmpty = 0;
	while (m_iEmpty != (m_nRow * m_nColumn)) {
		if (m_num[m_iEmpty / m_nColumn][m_iEmpty % m_nColumn] == REGULARZERO)
			break;
		++m_iEmpty;
	}
	return;
}

void NPuzzle::BoardVector::generateTable() {
	int iNum = 0, isSame, randNum, iNumTemp;
	int numTemp[m_nNum];

	for (int j = 0; j < m_nRow; ++j)
		m_num.push_back(std::vector<int>());
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
			m_num[iNum / m_nColumn].push_back(randNum);
		} else {
			//FILLEDZERO (-2) will represent zeros on the table
			m_num[iNum / m_nColumn].push_back(FILLEDZERO);
		}
		++iNum;
	}
}

void NPuzzle::BoardVector::getIntelligentMovement() {
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

int NPuzzle::BoardVector::printElements(int iIndex, int jIndex) {
	return m_num[iIndex][jIndex];
}

void NPuzzle::BoardVector::editElements(int iIndex, int jIndex, int elementValue) {
	m_num[iIndex][jIndex] = elementValue;
	return;
}

//operator overloading method
bool NPuzzle::BoardVector::operator ==(const BoardVector& otherObject) {
	int isSame = 1;
	for (int i = 0; i < m_nRow; ++i) {
		for (int j = 0; j < m_nColumn; ++j) {
			if (m_num[i][j] != otherObject.m_num[i][j])
				isSame = 0;
		}
	}
	return isSame;
}

//operator overloading method
int NPuzzle::BoardVector::operator ()(int indexX, int indexY) {
	if (!((2 <= indexX && indexX <= m_nRow) &&
		  (2 <= indexY && indexY <= m_nColumn)))
		exit(0);
	return m_num[indexX][indexY];
}

//operator overloading method
NPuzzle::BoardVector& NPuzzle::BoardVector::operator =(const BoardVector& otherObject) {
	m_nRow = otherObject.m_nRow;
	m_nColumn = otherObject.m_nColumn;
	m_nNum = otherObject.m_nNum;
	m_count = otherObject.m_count;
	m_iMove = otherObject.m_iMove;
	m_oper = otherObject.m_oper;

	for (int i = 0; i < m_nRow; ++i) {
		m_num.push_back(std::vector<int>());
		for (int j = 0; j < m_nColumn; ++j) {
			m_num[i].push_back(otherObject.m_num[i][j]);
		}
	}
	return *this;
}
