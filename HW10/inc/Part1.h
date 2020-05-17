/*
 * Part1.h
 *
 *  Created on: May 11, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define PI 3.14159265 //PI constant
#define N_OBJECTS 100 // maximum possible objects
#define FILE_LINE_LENGTH 100 // maximum length of a line

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write
FILE *fpte; //fpte file pointer edit

struct geo_point {
	float coor_y;
	float coor_x;
};

struct geo_line {
	char point[5];
};

struct geo_polygon {
	char point[5];
	char line[5];
};

struct geometry {
	struct geo_point point;
	struct geo_line line[2];
	struct geo_polygon polygon[20];
	char name[5];
	int n_objects;
};

/* reading and writing files */
void geometrical_objects(char *input_file_path);
void remove_line_extras(char *temp_str);
void get_struct_index(char *cmp_str, struct geometry geometry[N_OBJECTS], int *index);
float string_float_converter(char *num_str);

/* actions */
float calculate_distance(char *str_1, char *str_2, struct geometry geometry[N_OBJECTS]);
float calculate_angle(char *str_1, char *str_2, struct geometry geometry[N_OBJECTS]);
float calculate_length(char *str, struct geometry geometry[N_OBJECTS]);
float calculate_area(char *str, struct geometry geometry[N_OBJECTS]);

/* file operations */
void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
