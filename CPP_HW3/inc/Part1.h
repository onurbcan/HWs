/*
 * Part1.h
 *
 *  Created on: Jun 5, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

using namespace std;

//add last two to the classes
void n_puzzle_game_oop();
void convert_command(char c, int &oper);
//void play_n_puzzle_game(int *num, int *n, int *m, int *n_num, int *count);

class n_puzzle {
public:
	void print();
	void printReport();
	void readFromFile();
	void writeToFile();
	void shuffle();
	void reset();
	void setsize();
	void moveRandom();
	void moveIntelligent();
	void move(char c);
	void solvePuzzle();

	class board {
	public:
		void print();
		void readFromFile();
		void writeToFile();
		void reset();
		void setSize();
		void move(char c);
		void isSolved();

		//getters and setters
		int getCount() { return count; }
		void setCount(int count_value);
		int getDone() { return if_done; }
		void setDone(int done_value);

		//helper functions
		int** get_from_file(std::string file_path, int &if_error, int *sizes, int &count);
		void save_to_file(string file_path, int &if_error, int **num, int *sizes, int count);
		int string_int_converter(string num_str);
		int** generate_table(int n, int m, int n_num);
		void get_empty_index(int **num, int *i_empty);
		void shuffle_board();
		void get_intelligent_movement(char &oper);
		void get_intelligent_movement_v2(char &route);
		void get_random_movement(char &route);

	private:
		int **num, n, m, n_num;
		int count = 0, if_error = 0, if_done = 0;
		int sizes[2];
		string file_path;
	};

private:
	board new_board;
};

#endif /* INC_PART1_H_ */
