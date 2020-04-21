/*
 * Part1.h
 *
 *  Created on: Apr 21, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define GAME_LENGTH 100
#define GENRE_LENGTH 20
#define PLATFORM_LENGTH 20
#define FILE_LINE_LENGTH 200
#define FILE_LINE 2002

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

/*! 6.0) File operations */
void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
