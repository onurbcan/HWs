/*
 * Part1.h
 *
 *  Created on: Jun 5, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

enum menuOptions {
	EXIT = 0, RESUME = 1, NEWGAME = 2
};

enum commands {
	Q = -1, S = 0, U = 1, R = 2, D = 3, L = 4, I = 5, V = 6, T = 7, E = 8,
	O = 9, N = 10, A = 11, X = 12,
	q = -1, s = 0, u = 1, r = 2, d = 3, l = 4, i = 5, v = 6, t = 7, e = 8,
	o = 9, n = 10, a = 11, x = 12
};

class NPuzzle {
public:
	//NPuzzle constructor
	//NPuzzle() : m_command() {}

	//functions from the draft
	void readFromFile();
	void writeToFile();

	//helper functions
	void buildNewTable();
	void playNPuzzleGame();

	class Board {
	public:
		//Board constructor
		Board() : m_num(0), m_nRow(), m_nColumn(), m_nNum(), m_count(0), m_oper(),
				  m_iEmpty(), m_isError(0), m_isDone(0) {}

		//functions from the draft
		void print();
		void readFromFile();
		void writeToFile();
		void reset();
		void setSize();
		void move();

		//helper functions
		void printStatus();
		void generateTable();
		void shuffleBoard();
		void getRegularMovement(commands& route);
		void getIntelligentMovement();
		void getIntelligentMovementV2();
		void getRandomMovement();

	private:
		int **m_num, m_nRow, m_nColumn, m_nNum, m_count;
		int m_oper, m_iEmpty, m_isError, m_isDone;
		int m_sizes[2];
		std::string m_filePath;

		//function from the draft
		void isSolved();

		//helper functions
		void getFromFile();
		void saveToFile();
		int stringIntConverter(std::string num_str);
		void getEmptyIndex();
	};

private:
	commands m_command;
	Board nPuzzleBoard;

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
};

#endif /* INC_PART1_H_ */
