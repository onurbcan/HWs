/*
 * Part1.h
 *
 *  Created on: Apr 27, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

void hofstadters_q_sequence();
void menu(int *menu_choice);
void menu_cases(int menu_choice, int *arr);
void generate_hofstadters_sequence(int *arr, int n);
int find_max(int arr[], int index, int max_value);
int sum_array(int arr[], int index);
double std_array(int arr[], double *mean, int n, int index);

#endif /* INC_PART1_H_ */
