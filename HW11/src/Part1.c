/*
 * Part1.c
 * Description: The program reads a text file named ‘list.txt’. This file
 * contains a great number of comma separated random positive integers (e.g.,
 * N=1000000). The program should read this file only once and store these
 * numbers in the given order. Reading the file once means that you cannot read
 * any portion of the file twice. This means that during reading you cannot use
 * large fixed-sized arrays. You will do this reading in two different ways,
 * hence two separate functions.
 * • ... read_array(char *filename, ...) : This function will do the task
 * described above. It will take a file name and return a dynamically allocated
 * integer array including the read numbers. You can indicate the end of the
 * array using the value -1. Your total memory (stack or heap) usage in this
 * function should not be more than 4*(N+1) + 1000 bytes (assuming 4-byte
 * integers are used). You are expected to write the fastest function possible.
 * You are expected to properly define the input arguments and return values for
 * this function.
 * Hint: Consider the method discussed during the class.
 * • ... read_linkedlist(char *filename, ...) : Similar to the first function
 * above, this function will read the given file and return the the sequence of
 * numbers read from the file in a linked list. Each node of the list should
 * only hold 1 integer and a pointer. Your total memory (stack or heap) usage in
 * this function should not be more than (4+4)*N + 1000 bytes (assuming 4-byte
 * integers and addresses are used). You are expected to write the fastest
 * function possible.
 * You are expected to properly define the input arguments and return values for
 * this function.
 *
 * Your program will call these two functions once for each. The returned array
 * and linked list will be sent to two other functions:
 * • float * stats_array(...) : Given the numbers in an array, this function
 * returns an array of 4 numbers. These are min, max, mean and std deviation of
 * these numbers. Make sure that you properly allocate the return array in the
 * function.
 * • float * stats_linkedlist(...) : Given the numbers in a linked list, this
 * function returns an array of 4 numbers. These are min, max, mean and std
 * deviation of these numbers. Make sure that you properly allocate the return
 * array in the function.
 *
 * Your main function will:
 * • Call the read_array and read_linkedlist functions each once.
 * • Measure the time taken for these functions. Here, you can use start() and
 * end() functions (returntype: clock_t) from the <time.h> library. These
 * functions will return the clock cycles that the program needed to run the
 * tasks. You can use CLOCKS_PER_SEC definition to convert it into seconds. The
 * screen output should have the type of seconds.
 * • Print the time required for each of these functions.
 * • Print the total memory in bytes required for each of the dynamic array and
 * linked list.
 * • Call the stats_array and stats_linkedlist functions.
 * • Measure the time taken for these two functions.
 * • Print the time required for each of these functions.
 * • Report the results of these two comparisons.
 *
 * Note that operating systems may cache during the file reading. Therefore,
 * when you test the speed of these functions, the order in which you call them
 * may give differing results. To prevent biasing one method over the other in
 * speed, repeat the above reading steps a few times in different orders. For
 * example make the following calls: read_array, read_linked_list,
 * read_linked_list, read_array, read_array, read_linked_list. And, average the
 * timing results of the last four calls.
 *
 * Other rules for this part:
 * ❖ You can assume that the length of the text of the file is 1.000.000.
 * ❖ You are not allowed to use any library other than stdio.h, string.h,
 * stdlib.h, time.h, math.h (only for sqrt() function).
 * ❖ You can use the ‘strtol’ function from <stdlib.h> library to parse a string
 * to int.
 * ❖ You can write your own functions to make things easier.
 *
 *  Created on: May 21, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Part1.h"

void array_vs_linkedlist(char *file_path) {
	clock_t start, end;
	double time_spent;
	float *results;
	int *num, menu_choice;
	n *root = (n*)malloc(sizeof(n));

	printf("Welcome to the Array vs Linked List performance competition.\n");
	do {
		printf("Please choose the method Array (1) or Linked List (2) for performance measurement. ");
		printf("You can quit entering 0 here.\n");
		scanf("%d", &menu_choice);
		//system("clear");
		switch (menu_choice) {
		case (0):
			break;
		case (1):
			// starts performance measurement
			start = clock();
			// performs Array method
			num = (int*)malloc(sizeof(int));
			num = read_array(file_path, num);
			results = stats_array(num);
			printf("%f\n", results[0]);
			free(num);
			// ends performance measurement
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time spent during Array method: %lf\n", time_spent);
			break;
		case (2):
			// starts performance measurement
			start = clock();
			// performs Linked List method
			root = read_linkedlist(file_path, root);
			results = stats_linkedlist(root);
			printf("%f\n", results[0]);
			// ends performance measurement
			end = clock();
			time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("Time spent during Linked List method: %lf\n", time_spent);
			break;
		default:
			printf("Error occurred! %d is an invalid choice. Please try again.\n", menu_choice);
			break;
		}
		while (getchar() != '\n');
	} while (menu_choice != 0);
	printf("Good bye!\n");
	return;
}

int* read_array(char *file_path, int *num) {
	int i, i_num = 0;
	char c, temp_str[10];

	open_file_read(file_path);
	c = fgetc(fptr);
	if (c == EOF) {
		printf("Error occurred! File is empty. Please try again.");
		return num;
	}
	while (c != EOF) {
		i = 0;
		while (c != ',') {
			temp_str[i] = c;
			c = fgetc(fptr);
			++i;
		}
		temp_str[i] = '\0';
		num[i_num] = string_int_converter(temp_str);
		++i_num;
		c = fgetc(fptr);
		num = (int*)realloc(num, (i_num + 1) * sizeof(int));
	}
	num[i_num] = -1;
	close_file(fptr);
	return (num);
}

n* read_linkedlist(char *file_path, n *root) {
	int i;
	char c, temp_str[10];
	n *iter = root;
	iter->num = 0;

	open_file_read(file_path);
	c = fgetc(fptr);
	if (c == EOF) {
		printf("Error occurred! File is empty. Please try again.");
		return (root);
	}
	while (c != EOF) {
		i = 0;
		while (c != ',') {
			temp_str[i] = c;
			c = fgetc(fptr);
			++i;
		}
		temp_str[i] = '\0';
		iter->next = (n*)malloc(sizeof(n));
		iter = iter->next;
		iter->num = string_int_converter(temp_str);
		c = fgetc(fptr);
	}
	iter->next = NULL;
	close_file(fptr);
	return (root);
}

float* stats_array(int *num) {
	int sum = 0, count = 0;
	float min = 999999, max = 0, mean, stdev = 0, results[4];

	while (num[count] != -1) {
		if (num[count] > max)
			max = (float)num[count];
		if (num[count] < min)
			min = (float)num[count];
		sum += num[count];
		++count;
	}
	results[0] = min;
	mean = (float)sum/(float)count;
	count = 0;
	while (num[count] != -1) {
		stdev += (float)((num[count] - mean) * (num[count] - mean));
		++count;
	}
	stdev = (float)sqrt(stdev)/(float)count;
	printf("max: %f, min: %f, mean: %f, stdev: %f\n", max, min, mean, stdev);
	return (results);
}

float* stats_linkedlist(n *root) {
	float min = 999999, max = 0, mean, stdev = 0, results[4];
	int sum = 0, count = 0;
	//prints linked list, except root which is NULL
	n *iter = root->next;

	while (iter != NULL) {
		if (iter->num > max)
			max = (float)iter->num;
		if (iter->num < min)
			min = (float)iter->num;
		sum += iter->num;
		++count;
		iter = iter->next;
	}
	results[0] = min;
	mean = (float)sum/(float)count;

	iter = root->next;
	while (iter != NULL) {
		stdev += (float)((iter->num - mean) * (iter->num - mean));
		iter = iter->next;
	}
	stdev = (float)sqrt(stdev)/(float)count;
	printf("max: %f, min: %f, mean: %f, stdev: %f\n", max, min, mean, stdev);
	return (results);
}

int string_int_converter(char *num_str) {
	int i, p, to_power = 0;
	int num = 0, multiplier;

	for (i = strlen(num_str) - 1; i >= 0; --i) {
		multiplier = 1;
		for (p = 0; p < to_power; ++p)
			multiplier *= 10;
		num += ((num_str[i] - 48) * multiplier);
		++to_power;
	}
	return (num);
}

void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
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
