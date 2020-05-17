/*
 * Part1.c
 * Description: In this assignment, you are going to use structures to describe
 * and perform computations on simple 2D geometric objects placed on Euclidean
 * space (coordinate system). You will be using points, lines, and polygons. You
 * will read the definitions of a given set of geometric structures and actions
 * to be performed on them from an input file. The results of the actions will
 * be printed into an ouput file.
 *
 * Input File:
 * The input file has two parts: data and actions.
 * • Data:
 * ◦ Data part starts with keyword “data” (a single line).
 * ◦ It is followed by a number indicating the number of 2D objects to be read.
 * ◦ Following each line will have a 2D object definition. See below for
 * definition of 2D objects.
 * ◦ You can assume that there will be at least 1 and at most 100 2D objects.
 * ◦ You can assume that the object names are unique (no replications).
 * • Actions:
 * ◦ Action part starts with keyword “actions” (a single line).
 * ◦ It is followed by a file name indicating where the results of the actions
 * will be output.
 * ◦ This is followed by a number indicating the number of actions.
 * ◦ Following each line will have an action. See below for definition of 2D
 * actions and what they should generate.
 * • Comments:
 * ◦ Any part of the input file can include a comment which should be discarded
 * during reading. The comments starts with “\\” and ends at the end of the
 * line.
 * Example input and output files are provided as attachments.
 *
 * 2D Objects: There are three kinds of geometric objects.
 * • Point: A point is defined by its two coordinates and a name. I.e.,
 * ◦ 100.0 100.0 P1 // A point at location (100,100) with name “P1”.
 * ◦ 200.0 200.0 P2 // A point at location (100,100) with name “P2”.
 * • Line: A line is defined by two points and a name. I.e.,
 * ◦ P1 P2 L12 // The line named “L12” defined by two end points “P1” and “P2P).
 * • Polygons: A circularly connected set of lines with at most 20 components.
 * It can be defined either by connecting a set of points or a set of lines.
 * I.e.,
 * ◦ P1 P2 P3 P4 PG4 // The polygon “PG4” defined by four lines connecting first
 * “P1” and “P2”, second “P2” and “P3”, third “P3” and “P4” and finaly “P4” and
 * “P1”.
 * ◦ L12 L23 L31 P4 PG3 // The polygon “PG3” defined by three lines “L12”, “P23”
 * and “L31” in the given order.
 *
 * Actions: The following actions can be defined over the 2D objects provided in
 * the data part of the file.
 * • Distance: Print the distance between two points. For example, the following
 * action should result in the given output.
 * ◦ Distance P1 P2 // Print out the distance between points “P1” and “P2”.
 * Distance(P1,P2) = 12.0
 * • Distance: Print the distance between a point and a line. For example, the
 * following action should result in the given output.
 * ◦ Distance P1 L12 // Print out the distance between point “P1” and line
 * “L12”.
 * Distance(P1,L12) = 1.1
 * • Angle: Print the angle (in degrees) between two lines. For example, the
 * following action should result in the given output.
 * ◦ Angle L1 L2 // Print out the angle between lines “L1” and “L2”.
 * Angle(L1,L2) = 81.0
 * • Length: Print the length of a given line. For example, the following
 * actions should result in the given output.
 * ◦ Length L1 // Print out the length of line “L1”.
 * Length(L1) = 5.8
 * • Length: Print the length (circumference) of a given polygon. For example,
 * the following actions should result in the given output.
 * ◦ Length PG1 // Print out the circumference of the polygon “PG1”.
 * Length(PG1) = 15.2
 * • Area: Print the area of a given polygon. For example, the following actions
 * should result in the given output.
 * ◦ Area PG1 // Print out the area of the polygon “PG1”
 * Area(PG1) = 144.4
 * We strongly encourage you to use structures and nested structures and arrays.
 * While grading we will also look for the use of pass by reference (using as
 * default parameter passing strategy. Your grade will also be affected by your
 * choice of design. Finally,  if you can not implement a given functionality,
 * print NOT_IMPLEMENTED in the output file.
 *
 * <- commands.txt:
 * data
 * 10
 * 0.0   0.0 P1	// A point at location (0,0) with name “P1”.
 * 100.0   0.0 P2	// A point at location (100,0).
 * 100.0 100.0 P3
 * 0.0 100.0 P4
 * P1 P2 L12 // A line from P1 to P2.
 * P2 P3 L23
 * P3 P4 L34
 * P4 P1 L41
 * P1 P2 P3 P4 PG1     // A polygon with vertices P1, P2, P3 and P4.
 * L12 L23 L34 L41 PG2 // A polygon with edges L12, L23, L34 and L41.
 *
 * actions
 * outputs.txt
 * 7
 * Distance P1 P2 // Prints the distance between P1 and P2.
 * Distance P1 P3
 * Angle L12 L23
 * Angle L12 L34
 * Length PG1
 * Area PG1
 * Area PG2
 *
 * -> files/outputs.txt:
 * Distance(P1,P2) = 100.0
 * Distance(P1,P3) = 141.4
 * Angle(L12,L23) = 90.0
 * Angle(L12,L34) = 0.0
 * Length(PG1) = 400.0
 * Area(PG1) = 10000.0
 * Area(PG2) = 10000.0
 *
 *  Created on: May 11, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Part1.h"

void geometrical_objects(char *input_file_path) {
	int n_oper = 0, n_act = 0, i = 0, i_polygon;
	int length_temp_str, object_index_first, object_index_last, length_object_name;
	float result;
	char c, temp_str[FILE_LINE_LENGTH], object_name[5];
	char output_file_path[25] = "files/", output_file_name[15], num_data[5], num_actions[5];
	char temp_x[10], temp_y[10], *temp_polygon;
	char *action, *act_obj_1, *act_obj_2;
    struct geometry geometry[N_OBJECTS];

	open_file_read(input_file_path);

	/* checks if file is empty */
	c = fgetc(fptr);
	if (c == EOF) {
		printf("Error occurred! File is empty. Please check the file.\n");
		return;
	}

	while (fgets(temp_str, FILE_LINE_LENGTH, fptr) != NULL) {
		remove_line_extras(temp_str);
		/* decides if the file section is for data */
		if (strcmp(temp_str, "ata") == 0) {
			fgets(num_data, FILE_LINE_LENGTH, fptr);
			remove_line_extras(num_data);

			fgets(temp_str, FILE_LINE_LENGTH, fptr);
			remove_line_extras(temp_str);
			n_oper = 1;
		/* decides if the file section is for actions */
		} else if (strcmp(temp_str, "actions") == 0) {
			fgets(output_file_name, FILE_LINE_LENGTH, fptr);
			remove_line_extras(output_file_name);
			strcat(output_file_path, output_file_name);
			open_file_write(output_file_path);

			fgets(num_actions, FILE_LINE_LENGTH, fptr);
			remove_line_extras(num_actions);

			fgets(temp_str, FILE_LINE_LENGTH, fptr);
			remove_line_extras(temp_str);
			n_oper = 2;
		/* decides if the file section is for empty line */
		} else if (strcmp(temp_str, "\r") == 0) {
			n_oper = 0;
		}

		switch (n_oper) {
		/* (1): data operation */
		case (1):
			length_temp_str = strlen(temp_str);
			object_index_last = 0;
			/* gets the name of the object at the end of the line before comment section */
			while (1) {
				if ((47 < temp_str[length_temp_str] && temp_str[length_temp_str] < 123) && object_index_last == 0)
					object_index_last = length_temp_str;
				else if (temp_str[length_temp_str] == 32 && object_index_last > 0) {
					object_index_first = length_temp_str + 1;
					break;
				}
				--length_temp_str;
			}
			length_object_name = object_index_last - object_index_first + 1;
			strncpy(object_name, temp_str + object_index_first, length_object_name);
			object_name[length_object_name] = '\0';
			strcpy(geometry[i].name, object_name);

			/* if point */
			if (object_name[0] == 'P' && object_name[1] != 'G') {
				sscanf(temp_str, "%s %s %*s", temp_x, temp_y);
				geometry[i].point.coor_x = string_float_converter(temp_x);
				geometry[i].point.coor_y = string_float_converter(temp_y);
				geometry[i].n_objects = 2;
			/* if line */
			} else if (object_name[0] == 'L') {
				sscanf(temp_str, "%s %s %*s", temp_x, temp_y);
				strcpy(geometry[i].line[0].point, temp_x);
				strcpy(geometry[i].line[1].point, temp_y);
				geometry[i].n_objects = 2;
			/* if polygon */
			} else if (object_name[0] == 'P' && object_name[1] == 'G') {
				i_polygon = 0;
				/* if polygon with vertices */
				if (temp_str[0] == 'P') {
					strcpy(geometry[i].polygon[i_polygon].point, strtok(temp_str, " "));
					while (1) {
						temp_polygon = strtok(NULL, " ");
						if (strcmp(temp_polygon, object_name) == 0)
							break;
						++i_polygon;
						strcpy(geometry[i].polygon[i_polygon].point, temp_polygon);
					}
				/* if polygon with edges */
				} else if (temp_str[0] == 'L') {
					strcpy(geometry[i].polygon[i_polygon].line, strtok(temp_str, " "));
					while (1) {
						temp_polygon = strtok(NULL, " ");
						if (strcmp(temp_polygon, object_name) == 0)
							break;
						++i_polygon;
						strcpy(geometry[i].polygon[i_polygon].line, temp_polygon);
					}
				}
				geometry[i].n_objects = ++i_polygon;
			}
			++i;
			break;
		/* (2): actions operation */
		case (2):
			action = strtok(temp_str, " ");
			/* case distributor for actions */
			if (strcmp(action, "Distance") == 0) {
				n_act = 1;
			} else if (strcmp(action, "Angle") == 0) {
				n_act = 2;
			} else if (strcmp(action, "Length") == 0) {
				n_act = 3;
			} else if (strcmp(action, "Area") == 0) {
				n_act = 4;
			} else {
				n_act = 0;
			}
			/* switch case for actions */
			switch (n_act) {
			/* (1): Distance action */
			case (1):
				act_obj_1 = strtok(NULL, " ");
				act_obj_2 = strtok(NULL, " ");
				result = calculate_distance(act_obj_1, act_obj_2, geometry);
				fprintf(fptw, "%s(%s,%s) = %.1f\n", action, act_obj_1, act_obj_2, result);
				break;
			/* (2): Angle action */
			case (2):
				act_obj_1 = strtok(NULL, " ");
				act_obj_2 = strtok(NULL, " ");
				result = calculate_angle(act_obj_1, act_obj_2, geometry);
				fprintf(fptw, "%s(%s,%s) = %.1f\n", action, act_obj_1, act_obj_2, result);
				break;
			/* (3): Length action */
			case (3):
				act_obj_1 = strtok(NULL, " ");
				result = calculate_length(act_obj_1, geometry);
				fprintf(fptw, "%s(%s) = %.1f\n", action, act_obj_1, result);
				break;
			/* (4): Area action */
			case (4):
				act_obj_1 = strtok(NULL, " ");
				result = calculate_area(act_obj_1, geometry);
				fprintf(fptw, "%s(%s) = %.1f\n", action, act_obj_1, result);
				break;
			/* (0): Error action */
			default:
				printf("Error occurred! Please correct the action named %s\n", action);
				break;
			}
			break;
		default:
			break;
		}
	}
	close_file(fptr);
	close_file(fptw);
	return;
}

/* Removes new line and comment characters from the line */
void remove_line_extras(char *temp_str) {
	strtok(temp_str, "\r");
	strtok(temp_str, "\n");
	strtok(temp_str, "/"); // removes comments at the end of lines
	return;
}

/* Gets index in the given struct using the submitted compare string */
void get_struct_index(char *cmp_str, struct geometry geometry[N_OBJECTS], int *index) {
	for (*index = 0; *index < N_OBJECTS; ++*index) {
		if (strcmp(cmp_str, geometry[*index].name) == 0)
			break;
	}
	return;
}

/* Converts string value to float and returns also in this type */
float string_float_converter(char *num_str) {
	int i, d, p, if_dec = 0, to_power = 0;
	float num = 0, multiplier;

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

/* Calculates distance between two points */
float calculate_distance(char *str_1, char *str_2, struct geometry geometry[N_OBJECTS]) {
	int i_geometry_1, i_geometry_2;
	float result;

	/* get the index for the point 1 */
	get_struct_index(str_1, geometry, &i_geometry_1);
	/* get the index for the point 2 */
	get_struct_index(str_2, geometry, &i_geometry_2);

	result = sqrt(pow((geometry[i_geometry_2].point.coor_x - geometry[i_geometry_1].point.coor_x),2) +
				pow((geometry[i_geometry_2].point.coor_y - geometry[i_geometry_1].point.coor_y),2));
	return (result);
}

/* Calculates angle between two lines */
float calculate_angle(char *str_1, char *str_2, struct geometry geometry[N_OBJECTS]) {
	int i_geometry_1, i_geometry_2;
	int i_point_1, i_point_2, i_point_3, i_point_4;
	float result;

	/* get the index for the line 1 */
	get_struct_index(str_1, geometry, &i_geometry_1);
	/* get the index for the line 2 */
	get_struct_index(str_2, geometry, &i_geometry_2);
	/* get the index for the point 1.1 */
	get_struct_index(geometry[i_geometry_1].line[0].point, geometry, &i_point_1);
	/* get the index for the point 1.2 */
	get_struct_index(geometry[i_geometry_1].line[1].point, geometry, &i_point_2);
	/* get the index for the point 2.1 */
	get_struct_index(geometry[i_geometry_2].line[0].point, geometry, &i_point_3);
	/* get the index for the point 2.2 */
	get_struct_index(geometry[i_geometry_2].line[1].point, geometry, &i_point_4);

	result = remainder(((atan2(geometry[i_point_4].point.coor_y - geometry[i_point_3].point.coor_y,
			geometry[i_point_4].point.coor_x - geometry[i_point_3].point.coor_x) * 180.0 / PI) -
				(atan2(geometry[i_point_2].point.coor_y - geometry[i_point_1].point.coor_y,
			geometry[i_point_2].point.coor_x - geometry[i_point_1].point.coor_x) * 180.0 / PI)),180);
	if (result < 0)
		result *= -1;
	return (result);
}

/* Calculates length of a polygon */
float calculate_length(char *str, struct geometry geometry[N_OBJECTS]) {
	int i, i_next, i_geometry;
	float result = 0.0;

	/* get the index for the polygon */
	get_struct_index(str, geometry, &i_geometry);
	for (i = 0; i < geometry[i_geometry].n_objects; ++i) {
		i_next = (i + 1) % geometry[i_geometry].n_objects;

		result += calculate_distance(geometry[i_geometry].polygon[i].point,
				geometry[i_geometry].polygon[i_next].point, geometry);
	}
	return (result);
}

/* Calculates area of a polygon formed with points or lines */
float calculate_area(char *str, struct geometry geometry[N_OBJECTS]) {
	int i, i_next, i_geometry, i_line;
	float result = 1.0;

	/* get the index for the polygon */
	get_struct_index(str, geometry, &i_geometry);
	/* if polygon formed with points */
	if (geometry[i_geometry].polygon[0].point[0] > 0) {
		for (i = 0; i < geometry[i_geometry].n_objects; ++i) {
			i_next = (i + 1) % geometry[i_geometry].n_objects;

			result *= calculate_distance(geometry[i_geometry].polygon[i].point,
					geometry[i_geometry].polygon[i_next].point, geometry);
		}
	/* if polygon formed with lines */
	} else if (geometry[i_geometry].polygon[0].line[0] > 0) {
		for (i = 0; i < geometry[i_geometry].n_objects; ++i) {
			/* get the index for the line */
			get_struct_index(geometry[i_geometry].polygon[i].line, geometry, &i_line);

			result *= calculate_distance(geometry[i_line].line[0].point,
					geometry[i_line].line[1].point, geometry);
		}
	}
	return (sqrt(result));
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
