/*
 * Part1.c
 *
 *  Created on: Apr 21, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Part1.h"

/*! \mainpage HW7 Documentation
 *
 * This project is the implementation of Video games accounting.
 */

/** 1.0) Video games accounting
 * The Video games accounting 
 */
void video_games(char *file_path){
	int i, i_words = 0;
    //int year[FILE_LINE],na_sales[FILE_LINE],eu_sales[FILE_LINE],global_sales[FILE_LINE],user_score[FILE_LINE]
    char c;
    char all_games[FILE_LINE][FILE_LINE_LENGTH], games[FILE_LINE][GAME_LENGTH];
    char genres[FILE_LINE][GENRE_LENGTH], platforms[FILE_LINE][PLATFORM_LENGTH];
	open_file_read(file_path);

    while (c != '\n') {
    	c = fgetc(fptr);
    }

    while (fptr != EOF) {
    	fscanf(fptr, "%s, %s, %s, ", games, genres, platforms)

    }

	while (fgets(all_games[i_words], FILE_LINE_LENGTH, fptr) != NULL) {
		strtok(all_games[i_words], "\n");
		++i_words;
	}
    for (i = 0; i < 10; ++i) {
        printf("%s\n", all_games[i]);
    }
	close_file(fptr);
}

/** 6.1) Open file read
 * Opens the file to be read using the address and file name (together with
 * file type) in the parameter path. */
void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

/** 6.2) Open file write
 * Opens the file to be written using the address and file name (together with
 * file type) in the parameter path. */
void open_file_write(char *file_path) {
	if ((fptw = fopen(file_path, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

/** 6.3) Open file edit
 * Opens the file to be edited using the address and file name (together with
 * file type) in the parameter path. */
void open_file_edit(char *file_path) {
	if ((fpte = fopen(file_path, "a+")) == NULL) {
		printf("Error! File not edited.");
		exit(1);
	}
	return;
}

/** 6.4) Close file
 * Closes the file using the file pointer in the parameter. */
void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}
