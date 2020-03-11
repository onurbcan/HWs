/*
 * Part3.c
 * Description: Write a complete program describing all the tasks below.
 * In the main function, 2 integers are requested from the user. These integers
 * will work as decimal numbers but you are expected to work on them as binary
 * numbers and implement AND logical operator without using “&”. To do this,
 * 1. The program should check if the integers are binary or not (their digits
 * must be 0, 1). If the integers are not binary, the program should ask for
 * new integers again and again until it obtains a proper pair.
 * 2. The program should check if the integers’ lengths (number of digits) are
 * the same or not. If the lengths are not the same, the program should ask for
 * new integers again and again until it obtains a proper pair.
 * 3. After obtaining a decent integer pair (2 binary numbers with the same
 * length), the program should implement logical AND operation on these
 * integers, without using ‘&’ operator. Here, there should be a function which
 * calculates the result of the AND operation and returns it to the main(). And
 * the result should be printed in the main() function.
 *
 *  Created on: Mar 9, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part3.h"

void and_operation(){
	int num1, num2, temp1, temp2, error1, error2;

	do{
		error1 = 0; //error flag for binary check
		error2 = 0; //error flag for length check

		printf("First integer: ");
		scanf("%d",&num1);
		printf("Second integer: ");
		scanf("%d",&num2);

		temp1 = num1; //temporary variables to check num1 and num2 for errors
		temp2 = num2; //temporary variables to check num1 and num2 for errors

		do{
			if(temp1 % 10 != 0){
				if(temp1 % 10 != 1){
					printf("Integers should be binary, please enter 2 new integers.\n");
					error1 = 1; //error1 flag active here
				}
			}
			else if(temp2 % 10 != 0){
				if(temp2 % 10 != 1){
					printf("Integers should be binary, please enter 2 new integers.\n");
					error1 = 1; //error1 flag active here
				}
			}

			temp1 /= 10;
			temp2 /= 10;

			if(temp1 == 0){
				if(temp2 == 0){
					error2 = 0; //deactivates error2 flag
				}
				else{
					error2 = 1; //error2 flag active here
					printf("Integers should have the same length, please enter 2 new integers.\n");
				}
				break;
			}
			else if(temp2 == 0){
				error2 = 1; //error2 flag active here
				printf("Integers should have the same length, please enter 2 new integers.\n");
				break;
			}
		} while(temp1 != 0 || temp2 != 0);

	} while(error2 == 1 || error1 == 1); //to continue loop if any of the errors occur

	printf("%d AND %d = %d", num1, num2, andop(num1, num2));
}

int andop(int a, int b){
	int result, mult;
	result = 0; //result to be returned
	mult = 1; //decimal multiplier

	while(a > 0){
		if(a % 10 == 1){
			if(b % 10 == 1){
				result += (1 * mult);
				/*
				 * if both a and b have 1 for a certain decimal, 1 is added to
				 * the related decimal of the result variable
				 */
			}
		}
		a /= 10; //to get next decimal of a
		b /= 10; //to get next decimal of b
		mult *= 10; //to move decimal pointer for result variable
	}
	return (result);
}
