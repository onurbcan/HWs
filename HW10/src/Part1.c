/*
 * Part1.c
 *
 *  Created on: May 11, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
	int flag_op = 0, i = 0, i_polygon, length_temp_str, index_first, index_last, length_object_name, flag_act = 0;
    int i_geometry, i_geometry_2, i_temp, i_temp_2;
	int i_point, i_point_2, i_point_3, i_point_4;
	float res;
	char temp_str[150], object_name[5], file_out_path[15], num_data[5], num_actions[5];
    char *p_temp_str = temp_str;
    char temp_y[10], temp_x[10], *temp_polygon, *action, *act_elem_1, *act_elem_2;
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








		switch (flag_op) {
		/* (0): data operation */
		case (0):
			printf("%ld\n", strlen(temp_str));
			length_temp_str = strlen(temp_str);
			index_last = 0;
			while (1) {
				if ((47 < temp_str[length_temp_str] && temp_str[length_temp_str] < 123) && index_last == 0)
					index_last = length_temp_str;
				else if (temp_str[length_temp_str] == 32 && index_last > 0) {
					index_first = length_temp_str + 1;
					break;
				}
				--length_temp_str;
			}

			strncpy(object_name, p_temp_str + index_first, index_last - index_first + 1);
			length_object_name = index_last - index_first + 1;
			object_name[length_object_name] = '\0';

			strcpy(geometry[i].name, object_name);
			printf("%d: %s\n", i, geometry[i].name);

			/* if-statement for points */
			if (object_name[0] == 'P' && object_name[1] != 'G') {
				sscanf(temp_str, "%s %s %*s", temp_x, temp_y);
				geometry[i].point.coor_x = string_float_converter(temp_x);
				geometry[i].point.coor_y = string_float_converter(temp_y);
				geometry[i].n_elements = 2;
				printf("%f\n", geometry[i].point.coor_x);
				printf("%f\n", geometry[i].point.coor_y);
			/* if-statement for lines */
			} else if (object_name[0] == 'L') {
				sscanf(temp_str, "%s %s %*s", temp_x, temp_y);
				strcpy(geometry[i].line[0].point, temp_x);
				strcpy(geometry[i].line[1].point, temp_y);
				geometry[i].n_elements = 2;
				printf("%s\n", geometry[i].line[0].point);
				printf("%s\n", geometry[i].line[1].point);
			/* if-statement for polygons */
			} else if (object_name[0] == 'P' && object_name[1] == 'G') {
				i_polygon = 0;
				/* if-statement for polygon with vertices */
				if (temp_str[0] == 'P') {
					strcpy(geometry[i].polygon[i_polygon].point, strtok(temp_str, " "));
					printf("%s\n", geometry[i].polygon[i_polygon].point);
					while (1) {
						temp_polygon = strtok(NULL, " ");
						if (strcmp(temp_polygon, object_name) == 0)
							break;
						++i_polygon;
						strcpy(geometry[i].polygon[i_polygon].point, temp_polygon);
						printf("(i_pol)%d: %s\n", i_polygon, geometry[i].polygon[i_polygon].point);
					}
				/* if-statement for polygon with edges */
				} else if (temp_str[0] == 'L') {
					strcpy(geometry[i].polygon[i_polygon].line, strtok(temp_str, " "));
					printf("%s\n", geometry[i].polygon[i_polygon].line);
					while (1) {
						temp_polygon = strtok(NULL, " ");
						if (strcmp(temp_polygon, object_name) == 0)
							break;
						++i_polygon;
						strcpy(geometry[i].polygon[i_polygon].line, temp_polygon);
						printf("(i_pol)%d: %s\n", i_polygon, geometry[i].polygon[i_polygon].line);
					}
				}
				geometry[i].n_elements = ++i_polygon;
				printf("n_elem: %d\n", geometry[i].n_elements);
			}
			printf("str: %s\n", temp_str);
			++i;
			break;
		/* (1): actions operation */
		case (1):
			printf("%s\n", temp_str);

			action = strtok(temp_str, " ");

			if (strcmp(action, "Distance") == 0) {
				flag_act = 1;
			} else if (strcmp(action, "Angle") == 0) {
				flag_act = 2;
			} else if (strcmp(action, "Length") == 0) {
				flag_act = 3;
			} else if (strcmp(action, "Area") == 0) {
				flag_act = 4;
			}



			switch (flag_act) {
			/* Distance action */
			case (1):
				act_elem_1 = strtok(NULL, " ");
				act_elem_2 = strtok(NULL, " ");
				printf("elem: %s\n", act_elem_1);
				printf("elem: %s\n", act_elem_2);

				for (i_geometry = 0; i_geometry < 20; ++i_geometry) {
					if (strcmp(act_elem_1, geometry[i_geometry].name) == 0) {
						printf("i_geometry: %d\n", i_geometry);
						break;
					}
				}

				for (i_geometry_2 = 0; i_geometry_2 < 20; ++i_geometry_2) {
					if (strcmp(act_elem_2, geometry[i_geometry_2].name) == 0) {
						printf("i_geometry_2: %d\n", i_geometry_2);
						break;
					}
				}

				printf("res: %f\n", sqrt(pow((geometry[i_geometry_2].point.coor_x -
						geometry[i_geometry].point.coor_x),2) +
						pow((geometry[i_geometry_2].point.coor_y -
								geometry[i_geometry].point.coor_y),2)));

				break;
			/* Angle action */
			case (2):
				act_elem_1 = strtok(NULL, " ");
				act_elem_2 = strtok(NULL, " ");
				printf("elem: %s\n", act_elem_1);
				printf("elem: %s\n", act_elem_2);

				/* act_elem_1 */
				for (i_geometry = 0; i_geometry < 20; ++i_geometry) {
					if (strcmp(act_elem_1, geometry[i_geometry].name) == 0) {
						printf("i_geometry: %d\n", i_geometry);
						break;
					}
				}
				/* act_elem_2 */
				for (i_geometry_2 = 0; i_geometry_2 < 20; ++i_geometry_2) {
					if (strcmp(act_elem_2, geometry[i_geometry_2].name) == 0) {
						printf("i_geometry_2: %d\n", i_geometry_2);
						break;
					}
				}
				/* geometry[i_geometry].line[0].point */
				for (i_point = 0; i_point < 20; ++i_point) {
					if (strcmp(geometry[i_geometry].line[0].point, geometry[i_point].name) == 0) {
						printf("i_point: %d\n", i_point);
						break;
					}
				}
				/* geometry[i_geometry].line[1].point */
				for (i_point_2 = 0; i_point_2 < 20; ++i_point_2) {
					if (strcmp(geometry[i_geometry].line[1].point, geometry[i_point_2].name) == 0) {
						printf("i_point_2: %d\n", i_point_2);
						break;
					}
				}
				/* geometry[i_geometry_2].line[0].point */
				for (i_point_3 = 0; i_point_3 < 20; ++i_point_3) {
					if (strcmp(geometry[i_geometry_2].line[0].point, geometry[i_point_3].name) == 0) {
						printf("i_point_3: %d\n", i_point_3);
						break;
					}
				}
				/* geometry[i_geometry_2].line[1].point */
				for (i_point_4 = 0; i_point_4 < 20; ++i_point_4) {
					if (strcmp(geometry[i_geometry_2].line[1].point, geometry[i_point_4].name) == 0) {
						printf("i_point_4: %d\n", i_point_4);
						break;
					}
				}
				/*
				geometry[i_geometry].line[0].point
				geometry[i_geometry].line[1].point
				geometry[i_geometry_2].line[0].point
				geometry[i_geometry_2].line[1].point
				*/

				res = remainder(((atan2(geometry[i_point_4].point.coor_y - geometry[i_point_3].point.coor_y, geometry[i_point_4].point.coor_x - geometry[i_point_3].point.coor_x) * 180.0 / PI) -
						(atan2(geometry[i_point_2].point.coor_y - geometry[i_point].point.coor_y, geometry[i_point_2].point.coor_x - geometry[i_point].point.coor_x) * 180.0 / PI)),180);
				if (res < 0)
					res *= -1;
				printf("atan: %f\n", res);
				break;
			/* Length action */
			case (3):
				act_elem_1 = strtok(NULL, " ");
				printf("elem: %s\n", act_elem_1);
				res = 0;
				/* act_elem_1 */
				for (i_geometry = 0; i_geometry < 20; ++i_geometry) {
					if (strcmp(act_elem_1, geometry[i_geometry].name) == 0) {
						printf("i_geometry: %d\n", i_geometry);
						break;
					}
				}
				for (i_temp = 0; i_temp < geometry[i_geometry].n_elements; ++i_temp) {
					printf("%d: %s\n", i_temp, geometry[i_geometry].polygon[i_temp].point);
					i_temp_2 = (i_temp + 1) % geometry[i_geometry].n_elements;
					/* geometry[i_geometry].polygon[i_temp].point */
					for (i_point = 0; i_point < 20; ++i_point) {
						if (strcmp(geometry[i_geometry].polygon[i_temp].point, geometry[i_point].name) == 0) {
							printf("i_point: %d\n", i_point);
							break;
						}
					}
					/* geometry[i_geometry].polygon[i_temp + 1].point */
					for (i_point_2 = 0; i_point_2 < 20; ++i_point_2) {
						if (strcmp(geometry[i_geometry].polygon[i_temp_2].point, geometry[i_point_2].name) == 0) {
							printf("i_point_2: %d\n", i_point_2);
							break;
						}
					}
					res += sqrt(pow((geometry[i_point].point.coor_x -
							geometry[i_point_2].point.coor_x),2) +
								pow((geometry[i_point].point.coor_y -
							geometry[i_point_2].point.coor_y),2));

				}
				printf("res: %f\n", res);

				break;
			/* Area action */
			case (4):
				act_elem_1 = strtok(NULL, " ");
				printf("elem: %s\n", act_elem_1);
				res = 1;
				/* act_elem_1 */
				for (i_geometry = 0; i_geometry < 20; ++i_geometry) {
					if (strcmp(act_elem_1, geometry[i_geometry].name) == 0) {
						printf("i_geometry: %d\n", i_geometry);
						break;
					}
				}
				for (i_temp = 0; i_temp < geometry[i_geometry].n_elements; ++i_temp) {
					printf("%d: %s\n", i_temp, geometry[i_geometry].polygon[i_temp].point);
					i_temp_2 = (i_temp + 1) % geometry[i_geometry].n_elements;
					/* geometry[i_geometry].polygon[i_temp].point */
					for (i_point = 0; i_point < 20; ++i_point) {
						if (strcmp(geometry[i_geometry].polygon[i_temp].point, geometry[i_point].name) == 0) {
							printf("i_point: %d\n", i_point);
							break;
						}
					}
					/* geometry[i_geometry].polygon[i_temp + 1].point */
					for (i_point_2 = 0; i_point_2 < 20; ++i_point_2) {
						if (strcmp(geometry[i_geometry].polygon[i_temp_2].point, geometry[i_point_2].name) == 0) {
							printf("i_point_2: %d\n", i_point_2);
							break;
						}
					}
					res *= sqrt(pow((geometry[i_point].point.coor_x -
							geometry[i_point_2].point.coor_x),2) +
								pow((geometry[i_point].point.coor_y -
							geometry[i_point_2].point.coor_y),2));

				}
				printf("res: %f\n", sqrt(res));
				break;
			default:
				break;
			}
			break;
		/* (2): empty line operation */
		case (2):
			/*
			for (i = 0; i < 20; ++i)
				printf("n_elem: %d\n", geometry[i].n_elements);
			*/
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
