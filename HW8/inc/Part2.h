/*
 * Part2.h
 *
 *  Created on: Apr 29, 2020
 *      Author: onur
 */

#ifndef INC_PART2_H_
#define INC_PART2_H_

#define N 8

void l_shaped_pipe_orientation();
void install_pipes(int visited[N][N], int x, int y, int orientation, int count);
void next_l_pipe_orientations(int orientation, int *x, int *y);

#endif /* INC_PART2_H_ */
