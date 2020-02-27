/*
 * Part1.c
 *
 *  Created on: Feb 25, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part1.h"

void FindRoot(){
	int a, b, c;
	float x1, x2, delta;

	a = 0;
	b = 0;
	c = 0;

	x1 = 0;
	x2 = 0;
	delta = 0;

	printf("enter a of the equation:");
	scanf("%d",&a);
	printf("enter b of the equation:");
	scanf("%d",&b);
	printf("enter c of the equation:");
	scanf("%d",&c);

	delta = (b * b) - (4 * a * c);
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);

	if(delta < 0) printf("Roots are complex numbers");
	else {
		printf("x1: %.2f\n",x1);
		printf("x2: %.2f\n",x2);
	}
}
