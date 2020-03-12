/*
 * Part2.c
 * Description: Write a complete program which takes an integer N from the user
 * and checks the every integer from 2 to that number if they are prime or not.
 * The primality testing is made by a function with the following information:
 * A is prime if A is not dividible by any integer X where X is;
 * 1 < X ≤ √A
 * This operation should be done in a function, the function should return a
 * flag if the integer is prime, or should return the least divisor of that
 * integer if it is not a prime. In the main function, you should use a loop to
 * check every A between 1 < A < N, obtain a result by using the function and
 * finally print it. Only ‘for’ loops should be used. You are allowed to use
 * sqrt() function from math library to calculate the square root.
 *
 *  Created on: Mar 9, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part2.h"

void check_prime(){
	int num, i;

	printf("Please enter an integer: ");
	scanf("%d", &num);

	for(i = 2 ; i < num ; ++i){
		if(isprime(i))
			printf("%d is not a prime number, it is divisible by %d\n", i, isprime(i));
			//for different than 0 flag from the function, together with divider
		else
			printf("%d is a prime number\n", i); //for 0 flag from the function
		printf("\n");
	}
}

int isprime(int a){
	int i, flag = 0; //this is set 0 to make 2 (exceptional) as a prime number;
	double root_a;

	root_a = sqrt(a); //control range for the prime check

	for(i = 2 ; i <= root_a ; ++i){
		if(a % i){
			if(flag > 0)
				break;
				/* this if case is to keep -not a prime number- if it is already
				 * not a prime number
				 */
			else
				flag = 0; //0 flag for prime numbers
		}
		else
			flag = i; //different than 0 flag, to return divider
	}
	return flag;
}
