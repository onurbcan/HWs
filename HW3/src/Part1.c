/*
 * Part1.c
 * Description: In the main function, the program respectively request an Integer
 * (N), an operation flag, and finally a flag to decide if it is going to work on
 * odd / even numbers. The program will support only 2 operations, addition or
 * multiplication. According to the selection of the flags, the program will
 * calculate the sum/multiplication of the odd/even numbers between the range of
 * [1,N]. The addition and the multiplication operations should be done by using
 * two different functions. The operation selection should be determined by using
 * operation flag with switch-case, after that, the integer and the other flag
 * should be used to call the related function. If user enters invalid value for
 * the flags, the program should print an error message.
 *
 *  Created on: Mar 9, 2020
 *      Author: onur
 */
#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

void sum_mult_operation(){
	int n, operation, flag;

	do{
		printf("Enter an integer: ");
		scanf("%d",&n);
		printf("Please enter '0' for sum, '1' for multiplication\n");
		scanf("%d",&operation);
		printf("Please enter '0' to work on even numbers, '1' to work on odd numbers\n");
		scanf("%d",&flag);

		switch(operation){
			case SUM_OPERATION:
				sum(n, flag);
				break;
			case MULT_OPERATION:
				mult(n, flag);
				break;
			default:
				printf("Unsupported operation\n");
				break;
		}
		break;
	} while(operation != SUM_OPERATION && operation != MULT_OPERATION);

}

int sum(int n, int flag){
	int i, sum = 0;

	switch(flag){
		case EVEN_NUMBERS:
			for(i = 2 ; i < n ; i += 2){
				printf("%d ", i);
				sum += i;
				if(i == (n - 1) || i == (n - 2)) break;
				printf("+ ");
			}

			if(!(n % 2)){
				printf("+ %d ", n);
				sum += n;
			}

			printf("= %d\n", sum);
			break;

		case ODD_NUMBERS:
			for(i = 1 ; i < n ; i += 2){
				printf("%d ", i);
				sum += i;
				if(i == (n - 1) || i == (n - 2)) break;
				printf("+ ");
			}

			if(n % 2){
				printf("+ %d ", n);
				sum += n;
			}

			printf("= %d\n", sum);
			break;

		default:
			printf("Invalid value for odd/even selection\n");
			break;
	}
	return 0;
}

int mult(int n, int flag){
	int i, mult = 1;

	switch(flag){
		case EVEN_NUMBERS:
			for(i = 2 ; i < n ; i += 2){
				printf("%d ", i);
				mult *= i;
				if(i == (n - 1) || i == (n - 2)) break;
				printf("* ");
			}

			if(!(n % 2)){
				printf("* %d ", n);
				mult *= n;
			}

			printf("= %d\n", mult);
			break;

		case ODD_NUMBERS:
			for(i = 1 ; i < n ; i += 2){
				printf("%d ", i);
				mult *= i;
				if(i == (n - 1) || i == (n - 2)) break;
				printf("* ");
			}

			if(n % 2){
				printf("* %d ", n);
				mult *= n;
			}

			printf("= %d\n", mult);
			break;

		default:
			printf("Invalid value for odd/even selection\n");
			break;
	}
	return 0;
}
