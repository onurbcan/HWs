/*
 * Part3.c
 * Description: Write a recursive function that removes duplicated characters in
 * a given string. For example; Let the given string is “Thiis is not completely
 * misspelled butt we wannnnt to fix it”. The string becomes “This is not
 * completely mispeled but we want to fix it” after the function was performed
 * on it. Get the string from user. You can specify a maximum length for the
 * input string. The function prototype is given as:
 * char* remove_duplicates (char* str)
 *
 * You can use the ONLY 1 loop or auxiliary function in the recursion solution
 * of part-3 and this function or loop must be related to shifting the text.
 *
 *  Created on: Apr 29, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part3.h"

void text_duplicate_letter_cleaner() {
	int i;
	char str[TEXT_LENGTH + 1];
	do {
		printf("Please enter the text (up to 500 characters) to be removed its duplicated characters:\n");
		printf("(for e.g: Thiis is not completely misspelled butt we wannnnt to fix it)\n");
		scanf("%[^\n]", str);
		for (i = TEXT_LENGTH; i >= 0; --i) {
			if (str[i] == '\0')
				break;
		}
		if (i == 0)
			printf("Error occured!");
	} while (i == 0);
	remove_duplicates(str);
	printf("%s", str);
	return;
}

char* remove_duplicates(char* str) {
	int i;

	if (*str != '\0') {
		if (*str == *(str + 1)) {
			i = 0;
			while (*(str + i) != '\0') {
				*(str + i) = *(str + i + 1);
				++i;
			}
			remove_duplicates(str);
		} else {
			remove_duplicates(str + 1);
		}
	}
	return str;
}
