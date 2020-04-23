/*
 ============================================================================
 Name        : HW7.c
 Author      : Onur
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

int main(void) {
	/*! Video games accounting */
	video_games("files/Video_Games.txt");
	/*
	games_data[0][0] = 1000.2424;
	games_data[0][1] = (char)' ';
	games_data[0][2] = 25.595;
	printf("%f %f %f\n", games_data[0][0], games_data[0][1], games_data[0][2]);
	*/
	/*
	char tempp[20] = "0.01";
	float tempf = tempp[0];
	int i, j;
	for (i = 0; strlen(tempp); ++i) {
		while (tempp[0] == 0 && tempp[j] != '.') {

			++j;
		}

	}

	printf("%f", (float));
	*/

	return EXIT_SUCCESS;
}
