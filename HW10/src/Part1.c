/*
 * Part1.c
 *
 *  Created on: May 11, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Part1.h"

void geometrical_shapes() {
	//menu();

	//printf("Please enter the parameters\n");
//	scanf("%d %d %s", &geometry.geo_point.coor_y, &geometry.geo_point.coor_x, geometry.name);
//	printf("%d %d %s\n", geometry.geo_point.coor_y, geometry.geo_point.coor_x, geometry.name);
	build_data();
	return;
}

void build_data() {
//void build_arrays(char *file_path, int *if_error, int *names_total, int *genres_total, int *platforms_total, char names[GAME_LINE][GAME_LENGTH], char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]) {
	//int i_games = 0, i_genres = 0, i_platforms = 0;
	//int if_error;
	int flag_op = 0, i = 0;
    char temp_str[150], file_out_path[15], num_data[5], num_actions[5];
    char temp_y[10], temp_x[10], temp_name[10];
    struct geometry geometry[100];
    //char all_table[GAME_LINE][FILE_LINE_LENGTH];

	open_file_read("files/commands.txt");

	/* checks if file is empty
	c = fgetc(fptr);
	if (c == EOF) {
		if_error = 1;
		printf("%d\n", if_error);
		return;
	}
	*/

	while (fgets(temp_str, FILE_LINE_LENGTH, fptr) != NULL) {
		strtok(temp_str, "\r");
		strtok(temp_str, "\n");
		strtok(temp_str, "/"); // remove comments at the end of lines
		if (strcmp(temp_str, "data") == 0) {
			fgets(num_data, FILE_LINE_LENGTH, fptr);
			fgets(temp_str, FILE_LINE_LENGTH, fptr);
			strtok(temp_str, "\r");
			strtok(temp_str, "\n");
			strtok(temp_str, "/"); // remove comments at the end of lines
			flag_op = 0;
		} else if (strcmp(temp_str, "actions") == 0) {
			fgets(file_out_path, FILE_LINE_LENGTH, fptr);
			strtok(file_out_path, "\r");
			strtok(file_out_path, "\n");
			strtok(temp_str, "/"); // remove comments at the end of lines

			fgets(num_actions, FILE_LINE_LENGTH, fptr);
			strtok(num_actions, "\r");
			strtok(num_actions, "\n");
			strtok(temp_str, "/"); // remove comments at the end of lines

			fgets(temp_str, FILE_LINE_LENGTH, fptr);
			strtok(temp_str, "\r");
			strtok(temp_str, "\n");
			strtok(temp_str, "/"); // remove comments at the end of lines
			flag_op = 1;
		} else if (strcmp(temp_str, "\r") == 0) {
			flag_op = 2;
		}
//		else if (strcmp(temp_str, "\4") == 0)
//			break;
		printf("%ld\n", strlen(temp_str));
		switch (flag_op) {
		/* (0): data operation */
		case (0):
			if (!(64 < temp_str[0] && temp_str[0] < 123)) {
				sscanf(temp_str, "%s %s %s", temp_y, temp_x, temp_name);
				geometry[i].point.coor_y = string_float_converter(temp_y);
				geometry[i].point.coor_x = string_float_converter(temp_x);
				geometry[i].name = temp_name;
				printf("%f\n", geometry[i].point.coor_y);
				printf("%f\n", geometry[i].point.coor_x);
				printf("%s\n", geometry[i].name);
				++i;
			} else {

			}
			printf("%s\n", temp_str);
			break;
		/* (1): actions operation */
		case (1):
			printf("%s\n", temp_str);
			break;
		/* (2): empty line operation */
		case (2):
			break;
		default:
			break;
		}

//		if (strcmp(flag_str, "data") == 0) {
//			printf("correct\n");
//			printf("%s\n", temp_str);
//		} else if (strcmp(flag_str, "actions") == 0) {
//			printf("correct2\n");
//			printf("%s\n", temp_str);
//		} else if (strcmp(flag_str, "new_line") == 0) {
//			printf("correct3\n");
//			printf("%s\n", temp_str);
//		} else {
//			printf("%s\n", temp_str);
//		}
	}
	close_file(fptr);
	return;
//	while (fgets(all_table[i_games], FILE_LINE_LENGTH, fptr) != NULL) {
//		/* builds names array
//		 * checks if the token data is valid */
//
//		strcpy(names[i_games], strtok(all_table[i_games], ","));
//		if (names[i_games] == NULL) {
//			*if_error = 1;
//			return;
//		}
//
//		/* checks if the token data is valid
//		 * builds genres array and genres column of game data
//		 */
//		temp_str = strtok(NULL, ",");
//		if (temp_str == NULL) {
//			*if_error = 1;
//			return;
//		}
//	}
}

/* Converts string value to float and returns also in this type */
float string_float_converter(char *num_str) {
	int i, d, p, if_dec = 0, to_power = 0;
	float num = 0, multiplier;

	if (strcmp(num_str, "not_available") == 0)
		return (-1);

	/* checks if there is decimal part */
	for (d = 0; d < strlen(num_str); ++d) {
		if (num_str[d] == '.') {
			if_dec = 1;
			break;
		}
	}
	if (if_dec) {
		for (i = d - 1; i >= 0; --i) {
			multiplier = 1;
			for (p = 0; p < to_power; ++p)
				multiplier *= 10;
			num += ((num_str[i] - 48) * multiplier);
			++to_power;
		}
		to_power = 0;
		for (i = d + 1; i < strlen(num_str); ++i) {
			multiplier = 0.1;
			for (p = 0; p < to_power; ++p)
				multiplier /= 10;
			num += ((num_str[i] - 48) * multiplier);
			++to_power;
		}
	} else {
		for (i = strlen(num_str) - 1; i >= 0; --i) {
			multiplier = 1;
			for (p = 0; p < to_power; ++p)
				multiplier *= 10;
			num += ((num_str[i] - 48) * multiplier);
			++to_power;
		}
	}
	return (num);
}


void menu() {



	return;
}


/* Opens the file to be read using the address and file name (together with
 * file type) in the parameter path.*/
void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

/* Opens the file to be written using the address and file name (together with
 * file type) in the parameter path. */
void open_file_write(char *file_path) {
	if ((fptw = fopen(file_path, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

/* Opens the file to be edited using the address and file name (together with
 * file type) in the parameter path. */
void open_file_edit(char *file_path) {
	if ((fpte = fopen(file_path, "a+")) == NULL) {
		printf("Error! File not edited.");
		exit(1);
	}
	return;
}

/* Closes the file using the file pointer in the parameter. */
void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}
