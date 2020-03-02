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
#include "Part1.h"
#include "Part2.h"
#include "Part3.h"
#include <math.h>

int main(void) {
	FindRoot();
	FindNewtonianRoot();
	FindMultipleClosestFunction();

	printf("Operation Completed!");
	return EXIT_SUCCESS;
}
