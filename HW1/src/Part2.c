/*
 * Part2.c
 *
 *  Created on: Feb 26, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part2.h"

void FindNewtonianRoot(){
	int a, b, c, i, j;
	float g, f, df, diff;
	float output[COLUMN_SIZE_OF_ARR][ROW_SIZE_OF_ARR];

	a = 0;
	b = 0;
	c = 0;
	i = 0;
	j = 0;

	g = 0;
	f = 0;
	df = 0;
	diff = 0;

	printf("enter a of the equation:");
	scanf("%d",&a);
	printf("enter b of the equation:");
	scanf("%d",&b);
	printf("enter c of the equation:");
	scanf("%d",&c);
	printf("enter the initial guess:");
	scanf("%f",&g);

	for(i = 0 ; i < COLUMN_SIZE_OF_ARR ; i++){
		f = (a * g * g) + (b * g) + c;
		df = (2 * a * g) + b;
		output[i][0]  = g;
		output[i][1]  = f;
		g = g - (f / df);
	}

	printf("Step\t x\t f(x)\t\t Difference\n");

	for(j = 1 ; j < COLUMN_SIZE_OF_ARR ; j++){
		diff = output[j][0] - g;
		printf("x%d:\t %.4f\t %.5f\t %.4f\n", j, output[j][0], output[j][1], diff);
	}
}
