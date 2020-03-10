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
	unsigned int num1, num2, temp1, temp2, error;
	//error = 1;

	do{
		/*
		printf("First integer: ");
		scanf("%d",&num1);
		fflush(stdin);
		printf("Second integer: ");
		scanf("%d",&num2);
		fflush(stdin);
		printf("%d und %d\n", num1, num2);
		*/
		num1 = 1011;
		num2 = 1001;

		temp1 = num1;
		temp2 = num2;

		do{
			/*
			if(temp1 % 10 != 0)
				printf("Integers should be binary, please enter 2 new integers.\n");
			else if(temp1 % 10 != 1)
				printf("Integers should be binary, please enter 2 new integers.\n");
			else if(temp2 % 10 != 0)
				printf("Integers should be binary, please enter 2 new integers.\n");
			else if(temp2 % 10 != 1)
				printf("Integers should be binary, please enter 2 new integers.\n");
			*/
			error = 1;

			temp1 /= 10;
			temp2 /= 10;
			printf("%d and %d\n", temp1, temp2); //bu satırı bastı

			if((temp1 == 0) && (temp2 == 0)){
				error = 0; //removes error flag
				printf("here2 and %d\n", error); //ama buraya gelmedi yine
				break;
			}
			else if(temp1 == 0){
				error = 1;
				printf("Integers should have the same length, please enter 2 new integers.\n");
				break;
			}
			else if(temp2 == 0){
				error = 1;
				printf("Integers should have the same length, please enter 2 new integers.\n");
				break;
			}
			else printf("here4");
			printf("here5");
		} while(error != 0);
		//if(temp1 == 0 && temp2 == 0)
			//error = 0;
		//printf("%d", error);
	} while(error != 0);


	printf("%d AND %d = %d", num1, num2, andop(num1, num2));
}

int andop(int a, int b){
	//int result, mult;
	//result = 0;
	//mult = 1;
	/*
	while(a > 0){
		if(a % 10 == 1 && b % 10 == 1)
			result += (1 * mult);
		else
			mult *= 10;

		mult *= 10;
	}
	*/
	return 0;
}
