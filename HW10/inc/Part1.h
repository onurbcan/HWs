/*
 * Part1.h
 *
 *  Created on: May 11, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define PI 3.14159265
#define FILE_LINE_LENGTH 150

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write
FILE *fpte; //fpte file pointer edit

struct geo_point {
	float coor_y;
	float coor_x;
};

struct geo_line {
	char point[5];
	//struct geo_point point_1;
	//struct geo_point point_2;
};

struct geo_polygon {
	char point[5];
	char line[5];
	//struct geo_point point_1;
	//struct geo_point point_2;
};

/*
struct geo_lines_polygon {
	struct geo_line line;
};
*/

struct geometry {
	struct geo_point point;
	struct geo_line line[2];
	struct geo_polygon polygon[20];
	//struct geo_points_polygon points_polygon[20];
	//struct geo_lines_polygon lines_polygon[20];
	char name[5];
	int n_elements;
};

void geometrical_shapes();
void build_data();
float string_float_converter(char *num_str);
void menu();

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
