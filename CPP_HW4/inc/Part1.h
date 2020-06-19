/*
 * Part1.h
 *
 *  Created on: Jun 15, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#include <vector>

#define aVALUE 97
#define zVALUE 122
#define LOWERCASEUPPERCASEDIFFERENCE 32
#define ASCIINUMBERDIFFERENCE 48

#define REGULARZERO 0
#define FILLEDZERO -2

#define MINSIZES 2
#define MAXSIZES 9
#define MINnNUM 2
#define MAXSINGLEDIGITNUMBER 9

#define LENGTHSTRTEMP 5
#define LINESIZES 0
#define LINECOUNT 1
#define LINENUM 2

enum menuOptions {
	EXIT = 0, RESUME = 1, NEWGAME = 2, YES = 'Y', NO = 'N'
};

enum commands {
	Q = -1, S = 0, U = 1, R = 2, D = 3, L = 4, I = 5, V = 6, T = 7, E = 8,
	O = 9, N = 10, A = 11, X = 12
};

enum commandsFullNames {
	QUIT = 'Q', SHUFFLE = 'S', UP = 'U', RIGHT = 'R', DOWN = 'D', LEFT = 'L',
	INTELLIGENT = 'I', SOLVEPUZZLE = 'V', PRINTREPORT = 'T', WRITETOFILE = 'E',
	READFROMFILE = 'O', MOVERANDOM = 'A', RESET = 'X'
};

class NPuzzle {
public:
	//NPuzzle constructor
	NPuzzle() : countObject(0), eachStepValues(), m_command() {}

	//functions from the draft
	void readFromFile();
	void writeToFile();

	//helper functions
	void buildNewTable();
	void playNPuzzleGame();

//	std::ostream& operator <<(std::ostream& out, const NPuzzle& nPuzzleObject) {
//		out << nPuzzleObject.countObject;
//		return out;
//	}

	//std::istream& operator <<() {


	//	return;
	//}

	class Board {
	public:
		//Board constructor
		Board() : m_num(0), m_nRow(), m_nColumn(), m_nNum(), m_count(0),
				  m_iMove(0), m_oper(), m_prevOper(0), m_iEmpty(), m_isError(0),
				  m_isDone(0), m_iObject(0) {
		}

		Board(int iObject, int prevOper) : m_num(0), m_nRow(), m_nColumn(), m_nNum(), m_count(0),
				  m_iMove(0), m_oper(), m_prevOper(prevOper),m_iEmpty(), m_isError(0),
				  m_isDone(0), m_iObject(iObject) {
		}

		//functions from the draft
		void print();
		void readFromFile();
		void writeToFile();
		void reset();
		void setSize();
		void move();
		int isSolved();
		int numberOfBoards() { return m_iObject; }
		char lastMove();
		void incrementNumberOfMoves() { ++m_iMove; }
		int numberOfMoves() { return m_iMove; }

		//helper functions
		void printStatus();
		void generateTable();
		void shuffleBoard();
		void getRegularMovement(const char& route);
		void getIntelligentMovement();
		void getIntelligentMovementV2(const int& route, int& isAvailable);
		void getRandomMovement();
		void getChosenRouteName();

		bool operator ==(const Board& otherObject) {
			int isSame = 1;
			for (int i = 0; i < m_nRow; ++i) {
				for (int j = 0; j < m_nColumn; ++j) {
					if (m_num[i][j] != otherObject.m_num[i][j])
						isSame = 0;
				}
			}
			return isSame;
		}

		int operator ()(int indexX, int indexY) {
			if (!((2 <= indexX && indexX <= m_nRow) && (2 <= indexY && indexY <= m_nColumn)))
				exit(0);
			return m_num[indexX][indexY];
		}

		Board& operator =(const Board& otherObject) {
			m_nRow = otherObject.m_nRow;
			m_nColumn = otherObject.m_nColumn;
			m_nNum = otherObject.m_nNum;
			m_count = otherObject.m_count;
			m_iMove = otherObject.m_iMove;
			m_oper = otherObject.m_oper;
			m_num = (int**)realloc(m_num, m_nRow * sizeof(*m_num));
			for (int i = 0; i < m_nRow; ++i) {
				m_num[i] = (int*)malloc(m_nColumn * sizeof(int));
				for (int j = 0; j < m_nColumn; ++j) {
					m_num[i][j] = otherObject.m_num[i][j];
				}
			}
			return *this;
		}

	private:
		int **m_num, m_nRow, m_nColumn, m_nNum, m_count, m_iMove;
		int m_oper, m_prevOper, m_iEmpty, m_isError, m_isDone;
		int m_sizes[2], m_iObject;
		std::string m_filePath;

		//function from the draft
		

		//helper functions
		void getFromFile();
		void saveToFile();
		int stringIntConverter(const std::string& numStr);
		void getEmptyIndex();
	};

private:
	int countObject, eachStepValues[5];
	char m_command;
	std::vector<Board> nPuzzleBoard;
	Board newBoard;

	//functions from the draft
	void print();
	void printReport();
	void shuffle();
	void reset();
	void setsize();
	void moveRandom();
	void moveIntelligent();
	void move();
	void solvePuzzle();

	//helper functions

	void init(int oper) {
		Board nextBoard(++countObject, oper);
		nPuzzleBoard.push_back(nextBoard);
	}
};

#endif /* INC_PART1_H_ */
