/*
 * Part1.h
 *
 *  Created on: Apr 21, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define GAME_LINE 2000
#define GAME_LENGTH 100

#define GENRE_OR_PLATFORM_LINE 20 // 10 and 12 elements, respectively
#define GENRE_OR_PLATFORM_LENGTH 20

#define FILE_LINE 2000
#define FILE_LINE_LENGTH 200

#define YEAR_LENGTH 5
#define NA_SALES_LENGTH 10
#define EU_SALES_LENGTH 10
#define GLOBAL_SALES_LENGTH 10
#define USER_SCORE_LENGTH 10

/*! File pointer to read the file */
FILE *fptr; //fptr file pointer read
/*! File pointer to write the file */
FILE *fptw; //fptw file pointer write
/*! File pointer to edit the file */
FILE *fpte; //fptw file pointer edit

/*! 1.0) Video games accounting */
void video_games(char *file_path);
void menu(int *menu_choice);
void menu_cases(int menu_choice);
void build_single_arrays(char *file_path, char *games[][GAME_LENGTH], char *genres[][GENRE_OR_PLATFORM_LENGTH], char *platforms[][GENRE_OR_PLATFORM_LENGTH]);
void sort_char_array(char *array[][20], int size);
void build_data_array(char *file_path, float games_data[FILE_LINE][FILE_LINE_LENGTH]);

/*! 6.0) File operations */
void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
