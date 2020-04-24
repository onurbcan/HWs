/*
 * Part1.h
 *
 *  Created on: Apr 21, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define GAME_LINE 2000
#define GAME_DATA_ELEMENTS 7
#define GAME_LENGTH 100
#define FILE_LINE_LENGTH 200

#define GENRE_LINE 12
#define PLATFORM_LINE 10

/*! File pointer to read the file */
FILE *fptr; //fptr file pointer read
/*! File pointer to write the file */
FILE *fptw; //fptw file pointer write
/*! File pointer to edit the file */
FILE *fpte; //fptw file pointer edit

/*! 1.0) Video games accounting */
void video_games(char *file_path);
void menu(int *menu_choice);
void menu_cases(int menu_choice, char **games, char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]);
void build_arrays(char *file_path, char **games, char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]);
void sort_char_array(char *array[], int size);
float get_array_index(char *element, char *array[]);
float string_float_converter(char *num_str);

/*! 6.0) File operations */
void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
