/*
 * Part1.h
 *
 *  Created on: Apr 21, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

/*! Number of lines for file and games array */
#define GAME_LINE 2000
/*! Number of lines for genres array */
#define GENRE_LINE 12
/*! Number of lines for platforms array */
#define PLATFORM_LINE 10
/*! Number of columns for game_data array */
#define GAME_DATA_ELEMENTS 7

/*! Max. length of a file line*/
#define FILE_LINE_LENGTH 200
/*! Max. length of a game name */
#define GAME_LENGTH 100

/*! File pointer to read the file */
FILE *fptr; //fptr file pointer read
/*! File pointer to write the file */
FILE *fptw; //fptw file pointer write
/*! File pointer to edit the file */
FILE *fpte; //fptw file pointer edit

/*! 1.0) Video games accounting */
void video_games(char *file_path);

/*! 2.0) Initialization */
void build_arrays(char *file_path, int *if_error, int *names_total, int *genres_total, int *platforms_total, char names[GAME_LINE][GAME_LENGTH], char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]);
void build_single_arrays(int i_games, int *i_array, int game_data_index, char *str, char **array, float game_data[][GAME_DATA_ELEMENTS]);

/*! 3.0) Menu and menu case operations */
void menu(int *menu_choice);
void menu_cases(int menu_choice, int names_total, int genres_total, int platforms_total, char names[GAME_LINE][GAME_LENGTH], char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]);

/*! 4.0) Array and value operations */
float get_array_index(int names_total, char *element, char array[][GAME_LENGTH]);
float string_float_converter(char *num_str);
void float_string_converter(float num, char *num_str, int precision);

/*! 5.0) File operations */
void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
