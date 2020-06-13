/*
 * Part1.h
 *
 *  Created on: Jun 5, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

class NPuzzle {
public:
	//NPuzzle constructor
	NPuzzle() : oper(), command(), route() {}

	//functions from the draft
	void readFromFile();
	void writeToFile();

	//helper functions
	void build_new_table();
	void play_n_puzzle_game();

	class Board {
	public:
		//this Board constructor is for resume_game since values has not obtained yet, they are not set
		Board() : num(0), n(), m(), n_num(), i_empty(), count(0), if_error(0), if_done(0) {}
		//this Board constructor is for new_game since values has obtained before initialization, they are set
		//Board(int count_value) : num(0), n(), m(), n_num(), i_empty(), count(count_value), if_error(0), if_done(0) {}

		//functions from the draft
		void print();
		void readFromFile();
		void writeToFile();
		void reset();
		void setSize();
		void move(char route);

		//get methods
		int getCount() const { return count; }
		int getDone() const { return if_done; }

		//set methods
		void setN(int n_value) { n = n_value; }
		void setM(int m_value) { m = m_value; }
		void setN_num(int n_num_value) { n_num = n_num_value; }

		//helper functions
		void generate_table();
		void shuffle_board();
		void get_intelligent_movement(char &route);
		void get_intelligent_movement_v2(char &route);
		void get_random_movement(char &route);


	private:
		int **num, n, m, n_num, i_empty;
		int count, if_error, if_done;
		int sizes[2];
		std::string file_path;

		//function from the draft
		void isSolved();

		//helper functions
		void get_from_file();
		void save_to_file();
		int string_int_converter(std::string num_str);
		void get_empty_index();
	};

private:
	int oper;
	char command, route;
	Board new_board;

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
	void convert_command();
};

//global functions
//void n_puzzle_game_oop();
//void resume_game_menu(NPuzzle& resume_game);
//void new_game_menu(NPuzzle& new_game);

#endif /* INC_PART1_H_ */
