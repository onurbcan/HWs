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
	READFROMFILE = 'O', MOVERANDOM = 'A', RESET = 'X', NOMOVE = 'S'
};

class NPuzzle {
public:
	//NPuzzle constructor
	NPuzzle() : m_countObject(0), m_eachStepValues(0), m_command() {}

	//functions from the draft
	void readFromFile();
	void writeToFile();

	//helper functions
	void buildNewTable();
	void playNPuzzleGame();

	//operator overloading methods
	friend std::ostream& operator >>(std::ostream& output, NPuzzle& nPuzzleObject) {
    	for (int i = 0; i < nPuzzleObject.nPuzzleBoard[0].m_nRow; ++i) {
    		for (int j = 0; j < nPuzzleObject.nPuzzleBoard[0].m_nColumn; ++j) {
    			output << nPuzzleObject.nPuzzleBoard[0].printElements(i, j);
    			output << " ";
    		}
    	}
        return output;
    }
    friend std::istream& operator <<(std::istream& input, NPuzzle& nPuzzleObject) {
    	int elementValue;
    	for (int i = 0; i < nPuzzleObject.nPuzzleBoard[0].m_nRow; ++i) {
    		for (int j = 0; j < nPuzzleObject.nPuzzleBoard[0].m_nColumn; ++j) {
    	    	input >> elementValue;
    			nPuzzleObject.nPuzzleBoard[0].editElements(i, j, elementValue);
    		}
    	}
    	return input;
    }

	class Board {
	public:
		//Board constructor
		Board() : m_nRow(), m_nColumn(), m_num(0), m_nNum(), m_count(0),
				  m_iMove(0), m_oper(), m_iRootBoard(0), m_prevMove(0),
				  m_iEmpty(), m_isError(0), m_isDone(0), m_iObject(0) {}
		//Board constructor with value initializations
		Board(int iObject, int iRootBoard, int prevMove) : m_nRow(),
				m_nColumn(), m_num(0), m_nNum(), m_count(0), m_iMove(0),
				m_oper(), m_iRootBoard(iRootBoard), m_prevMove(prevMove),
				m_iEmpty(), m_isError(0), m_isDone(0), m_iObject(iObject) {}

		//public variables
		int m_nRow, m_nColumn;

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
		int printElements(int iIndex, int jIndex);
		void editElements(int iIndex, int jIndex, int elementValue);

		void getPrevBoard(int& prevBoard); /* is it ok this way? or should the variable (m_iRootBoard) be public? */

		//operator overloading methods
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
			if (!((2 <= indexX && indexX <= m_nRow) &&
				  (2 <= indexY && indexY <= m_nColumn)))
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
		int **m_num, m_nNum, m_count, m_iMove;
		int m_oper, m_iRootBoard, m_prevMove, m_iEmpty, m_isError, m_isDone;
		int m_sizes[2], m_iObject;
		std::string m_filePath;

		//helper functions
		void getFromFile();
		void saveToFile();
		int stringIntConverter(const std::string& numStr);
		void getEmptyIndex();
	};

private:
	int m_countObject, *m_eachStepValues;
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
	void printPrevMove(int i);
	void init(int iRootBoard, int prevMove) {
		Board nextBoard(++m_countObject, iRootBoard, prevMove);
		nPuzzleBoard.push_back(nextBoard);
	}
};

#endif /* INC_PART1_H_ */
