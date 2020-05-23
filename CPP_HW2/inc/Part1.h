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

int* generate_table(int n);
void print_table(int *num, int n);
void print_report();
void swap_elements(int *num, int oper, int n);
void get_intelligent_movement(int *num, int n, int *oper);
void get_intelligent_v2_movement(int *num, int n, int *oper);
void get_empty_index(int *num, int *i_empty);
void check_if_done(int *num, int *if_done);

int* get_from_file(std::string file_path);
void save_to_file(int *num, std::string file_path);

#endif /* INC_PART1_H_ */

