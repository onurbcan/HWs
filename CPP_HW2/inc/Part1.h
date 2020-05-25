/*
 * Part1.h
 *
 *  Created on: May 23, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

void n_puzzle_game_v2();
void convert_command(char c, int *oper);
int* generate_table(int n, int m, int n_num);
void print_table(int *num, int n, int m);
void print_report(int count, int if_done);

int* resume_screen(int *n, int *m, int *count);
int* new_game_screen(int *n, int *m, int *n_num);
void play_n_puzzle_game(int *num, int *n, int *m, int *n_num, int *count);
void swap_elements(int oper, int *num, int *n, int *m, int *count);

void get_intelligent_movement(int *num, int n, int m, int *oper);
void get_intelligent_movement_v2(int *num, int n, int m, int *oper);
void get_empty_index(int *num, int *i_empty);
void check_if_done(int *num, int *if_done);
int string_int_converter(std::string num_str);

int* get_from_file(std::string file_path, int *if_error, int *sizes, int *count);
void save_to_file(std::string file_path, int *if_error, int *num, int *sizes, int count);

#endif /* INC_PART1_H_ */

