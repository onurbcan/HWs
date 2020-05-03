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

/** 3.1.0) Text Duplicate Letter Cleaner
 * The string with duplicated characters is obtained from user with a length
 * limit of 500 characters. If the user exceeds this limit, error message is
 * displayed and the program waits for a new text. */
void text_duplicate_letter_cleaner() {
	char str[TEXT_LENGTH + 1];

	while (1) {
		printf("Please enter the text (up to 500 characters) to be removed its duplicated characters, or 0 to exit:\n");
		printf("(for e.g: Thiis is not completely misspelled butt we wannnnt to fix it)\n");
		scanf("%[^\n]", str);
		system("clear");
		if (str[0] == '0') {
			printf("Good bye!\n");
			break;
		} else if (if_valid_text(str)) {
			printf("Error occurred! Text should be no more than 500 characters.\n\n");
			while(getchar() != '\n');
			continue;
		} else {
			printf("Input:\n%s\n\n", str);
			remove_duplicates(str);
			printf("Output:\n%s\n\n", str);
			while(getchar() != '\n');
		}
	}
	return;
}

/** 3.2.0) Check if a valid text
 * The text is checked if it has less than 500 characters. If so, if_valid_text
 * function returns 1, otherwise 0. */
int if_valid_text(char* str) {
	int i;

	for (i = TEXT_LENGTH; i > 0; --i) {
		if (str[i] == '\0')
			break;
	}
	if (i == 0) {
		return (1);
	} else {
		return (0);
	}
}

/** 3.3.0) Remove duplicates
 * A recursive function is developed to remove duplicated characters in a given
 * string. When a duplicated character is found, rest of the string is shifted
 * until the end of it using for-loop. This process is repeated all over the
 * string recursively. Let the given string is “Thiis is not completely
 * misspelled butt we wannnnt to fix it”. Then the output string is “This is not
 * completely mispeled but we want to fix it” after the function was performed
 * on it.*/
char* remove_duplicates(char* str) {
	int i;

	if (*str != '\0') {
		if (*str == *(str + 1)) {
			i = 0;
			for (i = 0; *(str + i) != '\0'; ++i)
				*(str + i) = *(str + i + 1);
			remove_duplicates(str);
		} else {
			remove_duplicates(str + 1);
		}
	}
	return str;
}
