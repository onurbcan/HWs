/*
 * Part1.c
 * Description: Stay Home Problem
 * As you know, everyone should stay at home because of the Covid-19 pandemic.
 * Cin Ali, who goes out before the curfew, must run to his home the fastest way
 * before the ban begins.
 *
 * Let's assume that Cin Ali is in the bakery at the intersection of Street 2
 * and Avenue 3, as shown in the diagram, and that he wants to return to his
 * home at the intersection of Street 1 and Avenue 1. Even though Cin Ali wants
 * to avoid getting out of the way, there are equally short cuts.
 * For example, there are three possible ways in this diagram, as follows:
 * • Move left, then left, then down.
 * • Move left then down, then left.
 * • Move down, then left, then left.
 * Your job in this issue is to write an recursive function: [Solutions made
 * without using the recursive function will not be evaluated!]
 * int numPathsHome(int street, int avenue)
 *
 * that returns the number of paths Cin Ali could take back to the origin from
 * the specified starting position, subject to the condition that Cin Ali
 * doesn’t want to take any unnecessary steps and can therefore only move west
 * or south (left or down in the diagram).
 *
 *  Created on: May 2, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

void number_of_route_alternatives() {
	int street, avenue;

	while (1) {
		build_sample_table();
		printf("\n\nPlease enter your y- and x- coordinates using the above table to get the number of route alternatives to get back H (Home).\n");
		printf("For e.g: 2 3, which is the sample coordinate on the table. You can exit any time using 1 1.\n");
		scanf("%d %d", &street, &avenue);
		system("clear");
		if (street == 1 && avenue == 1) {
			printf("Good bye!\n");
			break;
		} else if (street < 1 || avenue < 1) {
			printf("Error occurred! Your coordinates can only have positive numbers. Please try again accordingly.\n\n");
		} else {
			printf("Number of route alternatives from y:%d x:%d to get back home: %d\n\n", street, avenue, numPathsHome(street, avenue));
		}
		while (getchar() != '\n');
	}
	return;
}

void build_sample_table() {
	int i, j;

	for (i = 8; i >= 1; --i) {
		if (i <= 5)
			printf("%d ", i);
		else
			printf(". ");
		for (j = 1; j <= 8; ++j) {
			if (i == 1 && j == 1)
				printf("H ");
			else if (i == 2 && j == 3)
				printf("E ");
			else
				printf("* ");
		}
		printf("\n");
	}
	printf("  ");
	for (j = 1; j <= 8; ++j) {
		if (j <= 5)
			printf("%d ", j);
		else
			printf(". ");
	}
	return;
}

int numPathsHome(int street, int avenue) {
	if (street == 1 || avenue == 1)
		return (1);
	return numPathsHome(street - 1, avenue) + numPathsHome(street, avenue - 1);
}
