/*
 * Part1.h
 *
 *  Created on: Jun 5, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

using namespace std;

void n_puzzle_game_oop();

class n_puzzle {
public:
	void print();
	void printReport(); //
	void readFromFile();
	void writeToFile();
	void shuffle(); //
	// shuffle'll use generate_table function
	void reset();
	void setsize();
	void moveRandom(); //
	void moveIntelligent(); //
	void move();
	void solvePuzzle(); //

	class board {
	public:
		void print(); //ok
		void readFromFile(); //ok
		int** get_from_file(std::string file_path, int *if_error, int *sizes, int *count); //ok
		void writeToFile(); //ok
		void save_to_file(string file_path, int *if_error, int **num, int *sizes, int count); //ok
		int string_int_converter(string num_str); //ok
		void reset(); //ok
		void setSize(); //ok
		int** generate_table(int n, int m, int n_num); //ok
		void move(char c); //ok
		void get_empty_index(int **num, int *i_empty); //ok
		void isSolved(); //ok

		int count = 0;
	private:
		int **num;
		int n, m;
		int n_num;
		int if_error = 0;
		int sizes[2];
		string file_path;

		int if_done = 0;
	};

	board new_board;


private:


};

//int** get_from_file(std::string file_path, int *if_error, int *sizes, int *count, int *n_num);
//int string_int_converter(std::string num_str);

//void save_to_file(std::string file_path, int *if_error, int **num, int *sizes, int count);
//int** generate_table(int n, int m, int n_num);

#endif /* INC_PART1_H_ */
