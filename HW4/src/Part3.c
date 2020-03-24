/*
 * Part3.c
 * Description: We want to make a machine to track the position of the enemy
 * camp. The machine should have an interface that is shown below:
 * The O is our position and it is constant. E represents the enemies’ current
 * position. X and Y is the current axes of the position of the enemy camp. R
 * shows the distance between current position and the last position of the
 * enemy camp. D is the distance of enemy to our camp. The machine should work
 * until the operator gives ‘E’ command to machine and it have to refresh the
 * view of screen on each ‘R’ command. The prototype of the function of that
 * machine is shown below:
 *
 * void track_machine ()
 *
 * You have to refresh parameters by another function. The function prototype
 * is:
 *
 * void refresh_position (int *X, int Y*, double *D, double *R)
 *
 * The battlefield consists of 11x11 positions and our camps is on the position
 * (6, 6). Initial position of enemy is (0, 0) and next positions of the enemy
 * camp should be generated randomly.
 *
 *  Created on: Mar 23, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Part3.h"

void track_machine() {
	int X = 0, Y = 0;
	double D, R;
	char command;

	refresh_position(&X, &Y, &D, &R);
	printf(
			"Enemies X position: %d, Y position: %d, Displacement: %f, Distance to our camp: %f\n",
			X, Y, D, R);
	do {
		printf("Command (R / E) waiting...: ");
		scanf("%c", &command);
		printf("\n");
	} while (command != 'R' && command != 'E'); //to get a valid command
	return;
}

void refresh_position(int *X, int *Y, double *D, double *R) {
	int i, j;

	srand(time(NULL));

	temp_X = *X;
	temp_Y = *Y;

	*X = (rand() % 11) + 1;
	*Y = (rand() % 11) + 1;

	for (i = 1; i <= 11; ++i) { //y - coordinate
		for (j = 1; j <= 11; ++j) { //x - coordinate
			if (i == OUR_X_COORDINATE && j == OUR_Y_COORDINATE) {
				printf("O\t");
			} else if (i == *X && j == *Y) {
				printf("E\t");
			} else {
				printf(".\t");
			}
		}
		printf("\n");
	}

	*D = sqrt(pow((*X - temp_X), 2) + pow((*Y - temp_Y), 2)); //distance between current position and the last position of the enemy camp
	*R = sqrt(
			pow((*X - OUR_X_COORDINATE), 2) + pow((*Y - OUR_Y_COORDINATE), 2)); //distance of enemy to our camp

	return;
}
