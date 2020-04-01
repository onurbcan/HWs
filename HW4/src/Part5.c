/*
 * Part5.c
 * Description: Write a menu function to operate all the three parts. The menu
 * should work forever until the operator selects the exit option. Your menu
 * should seem as the figure below:
 *
 * The menu have to be in a function and your main function must contains only
 * the menu function (and may be SRAND() function). The function prototype is:
 *
 * void menu ()
 *
 *  Created on: Mar 29, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"
#include "Part2.h"
#include "Part3.h"
#include "Part4.h"
#include "Part5.h"

void menu() {
	int choice = 0;
	do {
		do {
			menu_screen();
			printf("Please make your choice:\n");
			scanf("%d", &choice);

			if (choice < 1 || choice > 5) {
				system("clear");
				printf("Invalid choice! Please try again.\n\n");
			}
		} while (choice < 1 || choice > 5);
		system("clear");
	} while (menu_cases(choice));
	return;
}

void menu_screen() {
	printf("1-) Decrypt and print encrypted_p1.img\n");
	printf("2-) Decrypt and print encrypted_p2.img\n");
	printf("3-) Switch on the tracking machine\n");
	printf("4-) Encrypt the message\n");
	printf("5-) Switch off\n");
	printf("\n");
	return;
}

int quit_case() {
	char quit_choice;

	do {
		while (getchar() != '\n');
		printf("Are you sure to switch off? Y/N\n");
		scanf("%c", &quit_choice);
		if (quit_choice == 'N' || quit_choice == 'n') {
			system("clear");
			//returns (1) to continue while loop in menu function
			return (1);
		} else if (quit_choice == 'Y' || quit_choice == 'y') {
			//returns (1) to stop while loop in menu function
			return (0);
		}
	} while (!(quit_choice == 'N' || quit_choice == 'n' || quit_choice == 'Y'
			|| quit_choice == 'y'));
	return (1);
}

int menu_cases(int menu_index) {
	int value = 1;
	switch (menu_index) {
	case (1):
		decrypt_and_print("files/encrypted_p1.img");
		break;
	case (2):
		deep_decrypt_and_print("files/encrypted_p2.img");
		break;
	case (3):
		track_machine();
		break;
	case (4):
		encrypt_messages("files/decrypted_p4.img");
		break;
	case (5):
		value = quit_case();
		break;
	default:
		break;
	}
	return value;
}
