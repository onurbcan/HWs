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
 *  Created on: Apr 29, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part3.h"

void text_duplicate_letter_cleaner() {
	char *str = {"Thiis is not completely misspelled butt we wannnnt to fix it"};
	printf("%s", remove_duplicates(str));

	return;
}

char* remove_duplicates(char* str) {
	if (str[0] == '\0')
		return "+";
	else
		remove_duplicates(str);
}
