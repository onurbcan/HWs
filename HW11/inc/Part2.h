/*
 * Part2.h
 *
 *  Created on: May 22, 2020
 *      Author: onur
 */

#ifndef INC_PART2_H_
#define INC_PART2_H_

typedef struct differences {
	int n1, n2;
	struct differences *next;
} diff;

void compare_two_arguments(char *file_path, char *file_path_2);

#endif /* INC_PART2_H_ */
