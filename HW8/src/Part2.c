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
 * void install_pipes (int visited[N][N], int x, int y, int orientation)
 * where orientation is the start orientation of the first L-shaped pipe, x and
 * y are the coordinates of the start position and visited is the field. An
 * example output should be like the following:
 * O1, O4, O6, O2 ...
 *
 *  Created on: Apr 29, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Part2.h"

void l_shaped_pipe_orientation() {
	int i, j, board[N][N];
	srand(time(NULL));
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			board[i][i] = 0;
		}
	}
	install_pipes(board, 0, 0, 1, 0);
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			printf("%2d", board[i][i]);
		}
		printf("\n");
	}
	return;
}

void install_pipes(int visited[N][N], int x, int y, int orientation, int count) {
	if (count == 3)
		return;
	else {
		visited[x][y] = count;

		while(1) {
			orientation = (rand() % 8) + 1;
			next_l_pipe_orientations(orientation, &x, &y);
			if (!((-1 < x && x < 8) || (-1 < y && y < 8) || visited[x][y] == 0)) {
				/* revert movement;
				 * if x or y is invalid coordinate,
				 * if target is already visited before. */
				if (orientation == 1 || orientation == 2 || orientation == 5 || orientation == 6)
					next_l_pipe_orientations(orientation + 2, &x, &y);
				else
					next_l_pipe_orientations(orientation - 2, &x, &y);
				continue;
			} else {
				/* quit loop;
				 * if x or y is not invalid coordinate */
				break;
			}
		}
		//while(!(-1 < x && x < 8) || !(-1 < y && y < 8));
		++count;
		install_pipes(visited, x, y, orientation, count);
	}
}

void next_l_pipe_orientations(int orientation, int *x, int *y) {
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
