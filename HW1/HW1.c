/*
 ============================================================================
 Name        : HW1.c
 Author      : onur
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int a, b;

	printf("Enter the first integer:");
	scanf("%d",&a);
	printf("Enter the second integer:");
	scanf("%d",&b);

	if((a % b) == 0){
		printf("Closest number to %d that is multiple of %d is itself.\n", a, b);
	}
	else{
		printf("Closest number to %d that is multiple of %d is %d.\n", a, b, FindMultipleClosest(a,b));
	}

	printf("Operation Completed!");
	return EXIT_SUCCESS;
}
