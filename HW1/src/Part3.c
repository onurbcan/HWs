/*
 * Part3.c
 *
 *  Created on: Feb 26, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part3.h"

void FindMultipleClosestFunction(){
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
}

int FindMultipleClosest(int a, int b){
	int a1, a2;
	a1 = a;
	a2 = a;

	while((a1 % b) != 0 || (a2 % b) != 0){
		--a1;
		++a2;
		if((a1 % b) == 0) return a1;
		if((a2 % b) == 0) return a2;
	}
	return a;
}
