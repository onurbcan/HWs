/*
 * Part1.c
 *
 *  Created on: Apr 27, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

void menu() {
	int i, arr[500];
	generate_hofstadters_sequence(arr, 4);
	for (i = 1; i < 6; ++i)
		printf("%d ", arr[i]);

	return;
}

void generate_hofstadters_sequence(int *arr, int n) {
	if (n == 1) {
		arr[n] = 1;
		return;
	} else if (n == 2) {
		arr[n] = 1;
		generate_hofstadters_sequence(arr, n - 1);
	} else {
		arr[n] = arr[n - arr[n - 1]] + arr[n - arr[n - 2]];
		generate_hofstadters_sequence(arr, n - 1);
	}
	return;
}
