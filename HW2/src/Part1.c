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

int draw_triangle(int side1, int side2, int side3){
	if(side3 > (side1 + side2) || side2 > (side1 + side3) || side1 > (side2 + side3)) return 0;
	else return 1;
}

void type_triangle(int side1, int side2, int side3){

	if(side1 == side2 && side2 == side3) printf("It is a Equilateral Triangle\n");
	if(side1 == side2 || side2 == side3 || side1 == side3) printf("It is a Isosceles Triangle\n");
	if(pow(side1,2) == (pow(side2,2) + pow(side3,2)) || pow(side2,2) == (pow(side1,2) + pow(side3,2)) || pow(side3,2) == (pow(side1,2) + pow(side2,2))) printf("It is a Right-Angled Triangle\n");
	else printf("It is a Scalene Triangle\n");

}

int perimeter_triangle(int side1, int side2, int side3){
	return side1 + side2 + side3;
}

double area_triangle(int side1, int side2, int side3){
	double hop;
	hop = (side1 + side2 + side3) / 2; //half of the perimeter
	return sqrt(hop * (hop - side1) * (hop - side2) * (hop - side3));
	//return 0;
}

