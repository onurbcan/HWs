/*
 * Part1.h
 *
 *  Created on: Apr 27, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

/*! Total length of the Hofstadter's Q-Sequence array */
#define ARRAY_TOTAL_LENGTH 500

/*! 1.1.0) Hofstadter's Q-Sequence */
void hofstadters_q_sequence();

/*! 1.2.0) Menu */
void hqs_menu(int *menu_choice, int *first_turn);
void hqs_menu_cases(int menu_choice, int *arr, int *n);

/*! 1.3.0) Generate Hofstadter's sequence */
void generate_hofstadters_sequence(int *arr, int n);
int get_hfs_seq_element(int n);
void print_sequence(int *arr, int n);

/*! 1.4.0) Greatest element of the array */
int find_max(int arr[], int index, int max_value);

/*! 1.5.0) Sum of the array */
int sum_array(int arr[], int index);

/*! 1.6.0) Mean and standard deviation of the array */
double std_array(int arr[], double *mean, int n, int index);

#endif /* INC_PART1_H_ */
