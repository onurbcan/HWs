/*
 * Part3.h
 *
 *  Created on: Mar 23, 2020
 *      Author: onur
 */

#ifndef INC_PART3_H_
#define INC_PART3_H_

#define OUR_X_COORDINATE 6
#define OUR_Y_COORDINATE 6

int temp_X, temp_Y;

void track_machine();
void refresh_position (int *X, int *Y, double *D, double *R);

#endif /* INC_PART3_H_ */
