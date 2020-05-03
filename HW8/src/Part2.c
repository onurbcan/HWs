/*
 * Part2.c
 * Description: Assume that we have a square field consisting of 8x8 blocks. We
 * want to install pipes for an irrigation system on this field. We have only an
 * L-shaped pipes (covering 3 blocks in one direction and 2 blocks in the
 * perpendicular direction) that can be connected to cover any given part of the
 * field. There are 8 possible placements of an L-pipe starting from a given
 * location. When starting from the block “S”, an L-shaped pipe can reach to the
 * blocks labeled “O1, O2, O3, O4, O5, O6, O7, O8” as shown in the figure above.
 * Each of these “O?” labels indicate a unique orientation of the pipe
 * placement.
 * Assume that the field is represented by an integer array of dimensions 8x8.
 * Initially this array has all 0’s indicating there are no pipes placed. The
 * action “At location [3,3] place an L pipe with orientation 4” will fill in
 * the field as shown on the left below. Another action “At location [1,4] place
 * an L pipe with orientation 5” will fill in the field as shown on the right
 * below.
 * Write a recursive function that prints all possible orientation sets that
 * covers the entire field with L-shaped pipes (starting from the top-left
 * corner of the field). Remember that one action covers only one field at a
 * time and the action can’t be done if the target block is already visited
 * before. The function prototype has given below:
 * void install_pipes (int visited[N][N], int x, int y, int orientation, int
 * count, int amount)
 * where amount is the number of orientation, count is the number of recursions,
 * orientation is the start orientation of the first L-shaped pipe, x and
 * y are the coordinates of the start position and visited is the field. An
 * example output should be like the following:
 * O1, O4, O6, O2 ...
 * Don't print stages, it is just an example for better understanding. You can
 * stop your recursive solution after 10 proper setups (NOT 10. PIPE, 10 full
 * setups that allow irrigating all fields) have been found and you can add an
 * integer parameter to function prototype for using as a counter.
 *
 *  Created on: Apr 29, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Part2.h"

/** 2.1.0) L-shaped Pipe Orientation
 * An N by N field is covered (to irrigate) by connecting L-shaped pipes
 * (covering 3 blocks in one direction and 2 blocks in the perpendicular
 * direction) */
void l_shaped_pipe_orientation() {
	int i, j, amount, board[N][N];

	srand(time(NULL));
	while (1) {
		printf("Please enter the amount of L-shaped pipe orientation on %dx%d board (or enter 0 to exit): ", N, N);
		scanf("%d", &amount);
		system("clear");
		/* 0 to exit */
		if (amount == 0) {
			printf("Good bye!\n");
			break;
		/* negative values are invalid */
		} else if (amount < 0) {
			printf("Error occurred! %d is invalid, amount value has to be a positive integer.\n", amount);
		/* operation for the positive values */
		} else {
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					board[i][j] = 0;
				}
			}
			printf("A proper set of %d orientations is:\n{", amount);
			install_pipes(board, 0, 0, 1, 1, amount);
			printf("}\n\nTheir locations are numbered respectively on the below board:\n");
			for (i = 0; i < N; ++i) {
				for (j = 0; j < N; ++j) {
					printf("%3d", board[i][j]);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return;
}

/** 2.2.0) Install pipes
 * Install pipes recursively for the given number of amount */
void install_pipes(int visited[N][N], int x, int y, int orientation, int count, int amount) {
	if (count == amount + 1) {
		return;
	} else {
		/* if statement to prevent printing the first orientation double */
		if (count != 1)
			printf("O%d", orientation);
		/* if statement to prevent printing extra commas */
		if (!(count == 1 || count == amount))
			printf(", ");
		visited[y][x] = count;
		while (1) {
			/* if statement to prevent random generation for initial turn orientation */
			if (count != 1)
				orientation = (rand() % 8) + 1;
			next_l_shaped_pipe_target(orientation, &x, &y);
			if (!((-1 < y && y < 8) && (-1 < x && x < 8)) || !(visited[y][x] == 0 || (y != 0 && x != 0))) {
				/* revert movement;
				 * if x or y is invalid coordinate,
				 * if target is already visited before.
				 * if it in not the initial loop turn */
				if (orientation == 1 || orientation == 2 || orientation == 5 || orientation == 6)
					next_l_shaped_pipe_target(orientation + 2, &x, &y);
				else
					next_l_shaped_pipe_target(orientation - 2, &x, &y);
				continue;
			} else {
				/* quit loop;
				 * if x or y is not invalid coordinate */
				break;
			}
		}
		install_pipes(visited, x, y, orientation, count + 1, amount);
	}
}

/** 2.3.0) Next L-shaped pipe target
 * Return by reference next x and y coordinates for the given orientation which
 * is 8 different L distance neighbor target */
void next_l_shaped_pipe_target(int orientation, int *x, int *y) {
	switch(orientation) {
	case 1:
		*x += 1;
		*y += 2;
		break;
	case 2:
		*x -= 2;
		*y += 1;
		break;
	case 3:
		*x -= 1;
		*y -= 2;
		break;
	case 4:
		*x += 2;
		*y -= 1;
		break;
	case 5:
		*x += 2;
		*y += 1;
		break;
	case 6:
		*x -= 1;
		*y += 2;
		break;
	case 7:
		*x -= 2;
		*y -= 1;
		break;
	case 8:
		*x += 1;
		*y -= 2;
		break;
	default:
		break;
	}
	return;
}
