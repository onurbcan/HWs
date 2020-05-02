/*
 * Part4.c
 * Description: Write a menu function that allows to test all the three parts.
 * Menu function should work until user wants to exit. The function prototype
 * is:
 * void menu()
 *
 *  Created on: May 1, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"
#include "Part2.h"
#include "Part3.h"
#include "Part4.h"

/*! 4.1.0) Menu Screen
 * A menu function is developed to execute all three parts of the project. It
 * works until user wants to exit.*/
void menu() {
	int menu_choice, if_break = 0;
	while (1) {
		printf("----------------Welcome to Homework 8---------------\n");
		printf("|                                                  |\n");
		printf("|%-50s|\n", " 1) Execute Hofstadter's Q-Sequence");
		printf("|%-50s|\n", " 2) Execute L-shaped Pipe Orientation");
		printf("|%-50s|\n", " 3) Execute Text Duplicate Letter Cleaner");
		printf("|%-50s|\n", " 4) Exit");
		printf("----------------------------------------------------\n");
		printf("Please enter index of the program to execute: \n");
		scanf("%d", &menu_choice);
		menu_cases(menu_choice, &if_break);
		if (if_break == 1)
			break;
	}
	return;
}

/** 4.2.0) Menu Cases
 * Menu cases are written into a switch-case statement. In case of an error or
 * program termination, related messages are also printed here. */
void menu_cases(int menu_choice, int *if_break) {
	system("clear");
	switch(menu_choice) {
	case 1:
		hofstadters_q_sequence();
		break;
	case 2:
		l_shaped_pipe_orientation();
		break;
	case 3:
		text_duplicate_letter_cleaner();
		break;
	case 4:
		*if_break = 1;
		printf("Good bye!\n");
		break;
	default:
		printf("Error occurred! %d is an invalid choice, please try again.\n", menu_choice);
		break;
	}
	while(getchar() != '\n');
	printf("\n");
	return;
}
