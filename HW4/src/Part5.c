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
#include "Part5.h"

void menu() {
	int choice;

	printf("1-) Decrypt and print encrypted_p1.img\n");
	printf("2-) Decrypt and print encrypted_p2.img\n");
	printf("3-) Switch on the tracking machine\n");
	printf("4-) Encrypt the message\n");
	printf("5-) Switch off\n");
	printf("\n");

	do {
		printf("Please make your choice:\n");
		scanf("%d", &choice);
		if (choice < 1 || choice > 5)
			printf("Invalid choice! Please try again.\n");
	} while (choice < 1 || choice > 5);
	menu_cases(choice);
	return;
}

void menu_cases(int menu_index) {
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
		break;
	}
	return;
}
