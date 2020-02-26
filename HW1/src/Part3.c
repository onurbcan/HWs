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

int FindMultipleClosest(int a, int b){
	int a1, a2 = 0;
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
