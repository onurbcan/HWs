/*
 * Part1.c
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
	} while(operation != 0 && operation != 1);

}

int sum(int n, int flag){
	int i, sum;
	sum = 0;

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
	int i, mult;
	mult = 1;

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
