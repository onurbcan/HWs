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
#include "Part3.h"

void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

void open_file_write() {
	if ((fptw = fopen("output.txt", "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}

void track_machine(){
	do{

	}while();

	return;
}

void refresh_position (int *X, int *Y, double *D, double *R){

	return;
}
