/*
 * Part2.c
 * Description: Write a function that takes two arguments holding a large number
 * of integers. The first argument is an array allocated from the heap, and the
 * second is a linked list (use the same declarations and assumptions for these
 * arrays as in Part 1). It is assumed that these two arguments are holding the
 * same sequence of integers. However, for some reason, a few of the entries are
 * entered wrong. For example:
 * Dynamic array	: {11, 2, 35, 14, 17, 67, 55, 98, 32, 22}
 * Linked list		: {11, 2, 35, 13, 17, 67, 55, 99, 32, 22}
 * Your function will find the difference in the entries and return them in a
 * separate array of “struct { int n1, n2; }”. This array is expected to be
 * created dynamically (no fixed array declarations).
 * You are asked to figure out a way both to generate these arrays and to change
 * some of the values dynamically and finally print out the array that has been
 * returned from the function. The program should perform Part 1 and Part 2
 * respectively.
 *
 *  Created on: May 22, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part2.h"

void compare_two_arguments() {
	int i;
	int num[5] = {1, 3, 3, 5, 5};
	n *root;
	root = (n*)malloc(sizeof(n));
	n *iter = root;
	iter->num = 0;

	diff *d_root;
	d_root = (diff*)malloc(sizeof(diff));
	diff *d_iter = d_root;

	for (i = 0; i < 5; ++i) {
		iter->next = (n*)malloc(sizeof(n));
		iter = iter->next;
		iter->num = (i + 1);
		printf("%d\n", num[i]);
	}
	iter->next = NULL;
	iter = root->next;
	while (iter != NULL) {
		printf("%d\n", iter->num);
		iter = iter->next;
	}
	iter = root->next;
	for (i = 0; i < 5; ++i) {
		if (num[i] != iter->num) {
			d_iter->next = (diff*)malloc(sizeof(diff));
			d_iter = d_iter->next;
			d_iter->n1 = num[i];
			d_iter->n2 = iter->num;
			d_iter->next = NULL;
		}
		iter = iter->next;
	}
	d_iter = d_root->next;
	while (d_iter != NULL) {
		printf("n1: %d, n2: %d\n", d_iter->n1, d_iter->n2);
		d_iter = d_iter->next;
	}
	return;
}
