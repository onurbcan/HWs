/*
 * Part2.h
 *
 *  Created on: Apr 29, 2020
 *      Author: onur
 */

#ifndef INC_PART2_H_
#define INC_PART2_H_

/*! x and y coordinate lengths of integer board array */
#define N 8

/*! 2.1.0) L-shaped Pipe Orientation */
void l_shaped_pipe_orientation();

/*! 2.2.0) Install pipes */
void install_pipes(int visited[N][N], int x, int y, int orientation, int count, int amount);

/*! 2.3.0) Next L-shaped pipe target */
void next_l_shaped_pipe_target(int orientation, int *x, int *y);

#endif /* INC_PART2_H_ */
