/*
 * Part1.c
 * Description: Lets do some exercises to reinforce your recursion skills. You
 * are asked to write a function that allows to do some useful operations on
 * Hofstadter's Q-Sequence. The formula of these sequences is shown below:
 * Q(n) = Q (n − Q(n − 1)) + Q(n − Q(n − 2))
 * Q(1) = Q(2) = 1
 *
 * You must write four operational functions and one menu function to
 * successfully do this part. The function takes an empty, fixed-sized (define
 * the size of the array as 500 and use it where you needed) integer array that
 * is used by the array operations in the menu:
 *
 * • Fill array: The option takes an integer number (n) from the user and fills
 * the array with first n items of the Hofstadter's Q-Sequence. The array items
 * that out of the range (n) should be zero. The function prototype of this part
 * is shown below:
 * void generate_hofstadters_sequence (int *arr, int n)
 *
 * • Find biggest number: The function finds the maximum valued item in the
 * array recursively. The function prototype of this part is shown below:
 * int find_max (int arr[], int index, int max_value)
 *
 * • Calculate sum: The function calculates the sum of items in the array
 * recursively. The function prototype of this part is shown below:
 * int sum_array (int arr[])
 *
 * • Calculate standard deviation: The function calculates the mean and the
 * standard deviation of the array recursively. The function returns standard
 * deviation by default and the mean value returns by reference.
 * double std_array (int arr[], double *mean, int n, int index)
 *
 * • Exit: Terminates the menu function. The menu should work until user select
 * this option. Don’t forget to print the calculated/found values after the
 * recursive functions done their jobs on option 2,3 and 4.
 *
 *  Created on: Apr 27, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part1.h"

/** 1.1.0) Hofstadter's Q-Sequence
 * Hofstadter's Q-Sequence generation and operations */
void hofstadters_q_sequence(){
	int i, first_turn = 1, menu_choice, arr[ARRAY_TOTAL_LENGTH], n;

	for (i = 1; i <= ARRAY_TOTAL_LENGTH; ++i)
		arr[i] = 0;
	do {
		hqs_menu(&menu_choice, &first_turn);
		hqs_menu_cases(menu_choice, arr, &n);
	} while (menu_choice != 5);
	return;
}

/** 1.2.1) Menu screen
 * The program supports 4 different operations. Therefore, there is a menu as
 * below. The program terminates if and only if the user enters ‘5’ as the
 * input. The menu appears again and again if an input is invalid or if the
 * previously requested operation is done. If the menu appears because of an
 * invalid input, there is an error message too. */
void hqs_menu(int *menu_choice, int *first_turn) {
	do {
		printf("-------------------------MENU--------------------------------------\n");
		printf("| %d) %-60s |\n", 1, "Fill Hofstadter's Q-Sequence array");
		printf("| %d) %-60s |\n", 2, "Find the greatest number in the array");
		printf("| %d) %-60s |\n", 3, "Calculate the sum of the array");
		printf("| %d) %-60s |\n", 4, "Calculate the mean and the standard deviation of the array");
		printf("| %d) %-60s |\n", 5, "Exit");
		printf("-------------------------------------------------------------------\n");

		printf("\nPlease select an operation: ");
		scanf("%d", menu_choice);
		printf("\n");
		if (*first_turn == 1 && (!(*menu_choice == 1 || *menu_choice == 5)))
			printf("First operation has to be fill array (no. 1) or exit (no. 5).\nPlease try again accordingly.\n\n");
	} while (*first_turn == 1 && (!(*menu_choice == 1 || *menu_choice == 5)));
	*first_turn = 0;
	return;
}

/** 1.2.2) Menu case operations
 * Each menu cases are operated in switch cases */
void hqs_menu_cases(int menu_choice, int *arr, int *n) {
	double mean, stdev;

	system("clear");
	switch (menu_choice) {
	case 1:
		do {
			printf("Please enter the length (max. %d) of the Hofstadter's Q-sequence array: ", ARRAY_TOTAL_LENGTH);
			scanf("%d", n);
			if (!(0 < *n && *n < ARRAY_TOTAL_LENGTH + 1))
				printf("%d is an invalid array length. Please try again.\n", *n);
			printf("\n");
		} while (!(0 < *n && *n < ARRAY_TOTAL_LENGTH + 1));
		generate_hofstadters_sequence(arr, *n);
		print_sequence(arr, *n);
		break;
	case 2:
		print_sequence(arr, *n);
		printf("Max = %d\n", find_max(arr, *n, arr[*n]));
		break;
	case 3:
		print_sequence(arr, *n);
		printf("Sum = %d\n", sum_array(arr, *n));
		break;
	case 4:
		print_sequence(arr, *n);
		stdev = std_array(arr, &mean, *n, *n + 1);
		printf("%-9s = %8.2lf\n%-9s = %8.2lf\n", "Mean", mean, "Std. dev.", stdev);
		break;
	case 5:
		printf("Good bye!\n");
		break;
	default:
		printf("Please try again.\n");
		break;
	}
	printf("\n");
	return;
}

/** 1.3.1) Generate Hofstadter's Q-sequence array
 * The option takes an integer number (n) from the user and fills the array with
 * first n items of the Hofstadter's Q-Sequence. The array items that out of the
 * range (n) are zero. */
void generate_hofstadters_sequence(int *arr, int n) {
	if (n == 1) {
		arr[n] = 1;
		return;
	} else if (n == 2) {
		arr[n] = 1;
		generate_hofstadters_sequence(arr, n - 1);
	} else {
		arr[n] = get_hfs_seq_element(n - get_hfs_seq_element(n - 1)) + get_hfs_seq_element(n - get_hfs_seq_element(n - 2));
		generate_hofstadters_sequence(arr, n - 1);
	}
}

/** 1.3.2) Generate Hofstadter's Q-sequence element
 * Each single element of Hofstadter's Q-sequence calculated here */
int get_hfs_seq_element(int n) {
	if (n == 1 || n == 2) {
		return 1;
	} else {
		return get_hfs_seq_element(n - get_hfs_seq_element(n - 1)) + get_hfs_seq_element(n - get_hfs_seq_element(n - 2));
	}
}

/** 1.3.3) Print Hofstadter's Q-sequence
 * Print Hofstadter's Q-sequence array for each operation */
void print_sequence(int *arr, int n) {
	int i;
	printf("%d length Hofstadter's Q-Sequence array:\n", n);
	for (i = 1; i <= n; ++i)
		printf("%d ", arr[i]);
	printf("\n\n");
	return;
}

/** 1.4.1) Greatest element of the array
 * The function finds the maximum valued item in the array recursively. */
int find_max(int arr[], int index, int max_value) {
	if (index == 0) {
		return (max_value);
	} else {
		if (arr[index] > max_value)
			max_value = arr[index];
		return find_max(arr, index - 1, max_value);
	}
}

/** 1.5.1) Sum of the array
 * The function calculates the sum of items in the array recursively. */
int sum_array(int arr[], int index) {
	if (index == 1)
		return arr[index];
	else
		return arr[index] + sum_array(arr, index - 1);
}

/** 1.6.1) Mean and standard deviation of the array
 * The function calculates the mean and the standard deviation of the array
 * recursively. Additionally, it returns standard deviation by default and the
 * mean value is returned by reference. */
double std_array(int arr[], double *mean, int n, int index) {
	if (index == 1) {
		return (arr[index] - *mean) * (arr[index] - *mean);
	} else if (index == n + 1) {
		/* additional case to calculate mean before stdev operation */
		*mean = sum_array(arr, n) / (double)n;
		return sqrt(std_array(arr, mean, n, index - 1));
	} else {
		return ((arr[index] - *mean) * (arr[index] - *mean)) + std_array(arr, mean, n, index - 1);
	}
}
