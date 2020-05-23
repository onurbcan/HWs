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

void generate_table(int *num, int n);
void print_table(int *num, int n);

int* get_from_file(std::string file_path);
void save_to_file(int *num, std::string file_path);

void cpp_open_file_edit(char *file_path);
void cpp_close_file_edit(std::fstream fio);

#endif /* INC_PART1_H_ */

