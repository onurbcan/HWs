/*
 * Part2.c
 *
 *  Created on: Feb 28, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part2.h"


void number_test(){
	int number, digit;

	printf("Enter a number (maximum 6 digits): ");
	scanf("%d",&number);

	printf("Your number has %d digits\n", number_length(number));

	printf("When your number is written 100 times next to each other, which digit of this number would you like to see?:\n");
	scanf("%d",&digit);

	printf("%dth digit of the big number sequence: %d", digit, find_digit(number, digit));
}

int number_length(int number){
	int log10eq; //log10 equivalent of the number
	log10eq = log10(number) + 1;

	return log10eq;
}

int find_digit(int number, int index){
	int numberofdigits, wisheddigit, result;
	//(actual) wished digit, converted into left-to-rigth order

	numberofdigits = number_length(number);
	wisheddigit = numberofdigits - (index % numberofdigits);
	if(wisheddigit == numberofdigits)
		wisheddigit = 0;
	result = (number / pow(10, wisheddigit));

	return result %= 10;
}

