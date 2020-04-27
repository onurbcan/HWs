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
#include "Part1.h"

/** 1.0) Video games accounting
 * The Video games accounting */
void hofstadters_q_sequence(){
	int menu_choice, arr[500];

	do {
		menu(&menu_choice);
		menu_cases(menu_choice, arr);
	} while (menu_choice != 5);
	return;
}

/** 1.1) Menu screen
 * The program supports 4 different operations. Therefore, there is a menu as
 * below. The program terminates if and only if the user enters ‘5’ as the
 * input. The menu appears again and again if an input is invalid or if the
 * previously requested operation is done. If the menu appears because of an
 * invalid input, there is an error message too. */
void menu(int *menu_choice) {
	printf("------------------------MENU-------------------\n");
	printf("| %d) %-40s |\n", 1, "Fill array");
	printf("| %d) %-40s |\n", 2, "Find biggest number");
	printf("| %d) %-40s |\n", 3, "Calculate sum");
	printf("| %d) %-40s |\n", 4, "Calculate standard deviation");
	printf("| %d) %-40s |\n", 5, "Exit");
	printf("-----------------------------------------------\n");

	printf("\nPlease select an operation: ");
	scanf("%d", menu_choice);
	printf("\n");
	return;
}

void menu_cases(int menu_choice, int *arr) {
	int i;

	//system("clear");
	switch (menu_choice) {
	case 1:
		generate_hofstadters_sequence(arr, 6);
		for (i = 1; i < 6; ++i)
			printf("%d ", arr[i]);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		printf("Good bye!\n");
		break;
	default:
		printf("Please try again.\n\n");
		break;
	}
}

void generate_hofstadters_sequence(int *arr, int n) {
	if (n == 1) {
		arr[n] = 1;
		return;
	} else if (n == 2) {
		arr[n] = 1;
		generate_hofstadters_sequence(arr, n - 1);
	} else {
		arr[n] = arr[n - arr[n - 1]] + arr[n - arr[n - 2]];
		generate_hofstadters_sequence(arr, n - 1);
	}
}
