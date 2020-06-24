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
	NPuzzle() : m_eachStepValues(0), m_countObject(0), m_command() {}

	//functions from the draft
	void readFromFile();
	void writeToFile();

	//helper functions
	void buildNewTable();
	void playNPuzzleGame();

	class Board {
	public:
		//Board constructor
		Board() : m_num(0), m_nRow(), m_nColumn(), m_nNum(), m_count(0),
				  m_iMove(0), m_oper(), m_iRootBoard(0), m_prevMove(0),
				  m_iEmpty(), m_isError(0), m_isDone(0), m_iObject(0) {}
		//Board constructor with value initializations
		Board(int iObject, int iRootBoard, int prevMove) : m_num(0),
				m_nRow(), m_nColumn(), m_nNum(), m_count(0), m_iMove(0),
				m_oper(), m_iRootBoard(iRootBoard), m_prevMove(prevMove),
				m_iEmpty(), m_isError(0), m_isDone(0), m_iObject(iObject) {}

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
		void getPrevBoard(int& prevBoard);
		void getBoardSettings(int& nRow, int& nColumn);

		//operator overloading methods
		bool operator ==(const Board& otherObject);
		int operator ()(int indexX, int indexY);
		Board& operator =(const Board& otherObject);

	private:
		std::vector<int> m_sizes;
		std::vector<std::vector<int>> m_num;
		int m_nRow, m_nColumn, m_nNum, m_count, m_iMove, m_oper, m_iRootBoard;
		int m_prevMove, m_iEmpty, m_isError, m_isDone, m_iObject;
		std::string m_filePath;

		//helper functions
		void getFromFile();
		void saveToFile();
		int stringIntConverter(const std::string& numStr);
		void getEmptyIndex();
	};

private:
	std::vector<int> m_eachStepValues;
	int m_countObject;
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
	void init(int iRootBoard, int prevMove);

	//operator overloading methods
	friend std::ostream& operator >>(std::ostream& output, NPuzzle& nPuzzleObject);
    friend std::istream& operator <<(std::istream& input, NPuzzle& nPuzzleObject);
};

#endif /* INC_PART1_H_ */
