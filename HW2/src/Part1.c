/*
 * Part1.c
 *
 *  Created on: Feb 28, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Part1.h"

void triangle_test(){
	int side1, side2, side3;

	printf("The length of first side:");
	scanf("%d",&side1);
	printf("The length of second side:");
	scanf("%d",&side2);
	printf("The length of third side:");
	scanf("%d",&side3);

	if(draw_triangle(side1, side2, side3) == 1)
		printf("According to the triangle inequality theorem, this triangle can be drawn.\n");
	else
		printf("According to the triangle inequality theorem, this triangle cannot be drawn.\n");

	type_triangle(side1, side2, side3);
	printf("The perimeter of the triangle: %d\n", perimeter_triangle(side1, side2, side3));
	printf("The area of the triangle: %.3f", area_triangle(side1, side2, side3));

}

int draw_triangle(int side1, int side2, int side3){
	//if a side is greater than the sum of other two sides then it's not a drawable triangle
	if(side3 > (side1 + side2) || side2 > (side1 + side3) || side1 > (side2 + side3))
		return 0;
	else
		return 1;
}

void type_triangle(int side1, int side2, int side3){
	if(side1 == side2 && side2 == side3)
		printf("It is a Equilateral Triangle\n");
	else if(side1 == side2 || side2 == side3 || side1 == side3)
		printf("It is a Isosceles Triangle\n");
	else if(pow(side1,2) == (pow(side2,2) + pow(side3,2)) || pow(side2,2) == (pow(side1,2) + pow(side3,2)) || pow(side3,2) == (pow(side1,2) + pow(side2,2)))
		printf("It is a Right-Angled Triangle\n");
	else
		printf("It is a Scalene Triangle\n");

}

int perimeter_triangle(int side1, int side2, int side3){
	return side1 + side2 + side3; //sum of all sides give the perimeter of a triangle
}

double area_triangle(int side1, int side2, int side3){
	double hop; //half of the perimeter
	hop = (double) (side1 + side2 + side3) / 2.0;
	return sqrt(hop * (hop - side1) * (hop - side2) * (hop - side3)); //area of the triangle
}
