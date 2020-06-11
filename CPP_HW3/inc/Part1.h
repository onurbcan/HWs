/*
 * Part1.h
 *
 *  Created on: Jun 5, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

void n_puzzle_game_oop();

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
	void move();
	void solvePuzzle();

	//helper functions
	void menu();
	void play_n_puzzle_game();
	void convert_command();

	class board {
	public:
		void print();
		void readFromFile();
		void writeToFile();
		void reset();
		void setSize();
		void move(char route);
		void isSolved();

		//getters and setters
		int getCount() { return count; }
		void setCount(int count_value);
		int getDone() { return if_done; }
		void setDone(int done_value);

		//helper functions
		void get_from_file();
		void save_to_file();
		int string_int_converter(std::string num_str);
		void generate_table();
		void get_empty_index();
		void shuffle_board();
		void get_intelligent_movement(char &route);
		void get_intelligent_movement_v2(char &route);
		void get_random_movement(char &route);

	private:
		int **num = 0, n, m, n_num;
		int i_empty;
		int count = 0, if_error = 0, if_done = 0;
		int sizes[2];
		std::string file_path;
	};

private:
	int oper, menu_choice;
	char command, route, save_choice;

	board new_board;
};

#endif /* INC_PART1_H_ */
