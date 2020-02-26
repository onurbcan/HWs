/*
 * Part2.c
 *
 *  Created on: Feb 26, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "Part2.h"

void FindNewtonianRoot(){
	int a, b, c, i, j = 0;
	float g, f, df, diff = 0;
	float o[6][2];

	printf("enter a of the equation:");
	scanf("%d",&a);
	printf("enter b of the equation:");
	scanf("%d",&b);
	printf("enter c of the equation:");
	scanf("%d",&c);
	printf("enter the initial guess:");
	scanf("%f",&g);

	for(i = 0 ; i < 6 ; i++){
		f = (a * g * g) + (b * g) + c;
		df = (2 * a * g) + b;
		o[i][0]  = g;
		o[i][1]  = f;
		g = g - (f / df);
	}

	printf("Step\t x\t f(x)\t\t Difference\n");

	for(j = 1 ; j < 6 ; j++){
		diff = o[j][0] - g;
		printf("x%d:\t %.4f\t %.5f\t %.4f\n", j, o[j][0], o[j][1], diff);
	}
}
