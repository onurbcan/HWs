/*
 * Part1.h
 *
 *  Created on: Mar 31, 2020
 *      Author: onur
 */

#ifndef INC_PART1_H_
#define INC_PART1_H_

#define FIRST_TEXT_FILE "files/1.txt"
#define SECOND_TEXT_FILE "files/2.txt"
#define THIRD_TEXT_FILE "files/3.txt"
#define FORTH_TEXT_FILE "files/4.txt"
#define ALL_NEWS_TEXT_FILE "files/all_news_id.txt"
#define READED_NEWS_TEXT_FILE "files/readed_news_id.txt"

FILE *fptr; //fptr file pointer read
FILE *fptw; //fptw file pointer write
FILE *fpte; //fptw file pointer edit

void menu();
int menu_cases();
void print_news(int, int, int);
void print_arrays(char [], char[], int);
int read_news(char [], char [], int);
int number_of_news();
void append_file(char*, char);
void read_magic_numbers(char [], char []);
double f_func(int x);
double g_func(double f(int x), int a);

void open_file_read(char *file_path);
void open_file_write(char *file_path);
void open_file_edit(char *file_path);
void close_file(FILE *file_pointer);

#endif /* INC_PART1_H_ */
