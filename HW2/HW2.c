/*
 ============================================================================
 Name        : HW2.c
 Author      : Onur
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part1.h"

int main(void) {
	int side1, side2, side3;
	side1 = 0;
	side2 = 0;
	side3 = 0;

	printf("The length of first side: \n");
	scanf("%d\n",&side1);
	printf("The length of second side: \n");
	scanf("%d\n",&side2);
	printf("The length of third side: \n");
	scanf("%d\n",&side3);

	if(draw_triangle(side1, side2, side3) == 1) printf("According to the triangle inequality theorem, this triangle can be drawn.\n");
	else printf("According to the triangle inequality theorem, this triangle cannot be drawn.\n");

	type_triangle(side1, side2, side3);
	printf("The perimeter of the triangle: %d\n", perimeter_triangle(side1, side2, side3));
	printf("The area of the triangle: %f", area_triangle(side1, side2, side3));


	return EXIT_SUCCESS;
}
