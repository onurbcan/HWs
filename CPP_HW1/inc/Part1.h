/*
 * Part1.h
 *
 *  Created on: May 16, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

void n_puzzle_game();
void generate_table(int *num, int n);
void print_table(int *num, int n);
void convert_command(char c, int *oper);
void get_empty_index(int *num, int n, int *i_empty);
void get_intelligent_movement(int *num, int n, int *oper);
void swap_elements(int *num, int oper, int n);
void check_if_done(int *num, int n, int *if_done);

#endif /* INC_PART1_H_ */
