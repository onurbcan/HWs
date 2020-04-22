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
	int menu_choice;

    char *games[GAME_LINE][GAME_LENGTH];
    char *genres[GENRE_OR_PLATFORM_LINE][GENRE_OR_PLATFORM_LENGTH];
	char *platforms[GENRE_OR_PLATFORM_LINE][GENRE_OR_PLATFORM_LENGTH];

	float *games_data[FILE_LINE][FILE_LINE_LENGTH];


	do {
		menu(&menu_choice);
		menu_cases(menu_choice);
	} while (menu_choice != 8);

	build_single_arrays(file_path, games, genres, platforms);

	build_data_array(file_path, games_data);



}

void menu(int *menu_choice) {
	printf("%d: List of the genres\n", 0);
	printf("%d: List of the platforms\n", 1);
	printf("%d: List of the games through the years\n", 2);
	printf("%d: All information of a single game\n", 3);
	printf("%d: Average of the user score\n", 4);
	printf("%d: Geographical information of a single game\n", 5);
	printf("%d: Frequence of the genres\n", 6);
	printf("%d: Frequence of the platforms\n", 7);
	printf("%d: Exit\n", 8);

	printf("Please select an operation: ");
	scanf("%d", menu_choice);

	return;
}

void menu_cases(int menu_choice) {
	switch (menu_choice) {
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		printf("Good bye!\n");
		break;
	default:
		printf("Please try again.\n\n");
	}
	return;
}

void build_single_arrays(char *file_path, char *games[][GAME_LENGTH], char *genres[][GENRE_OR_PLATFORM_LENGTH], char *platforms[][GENRE_OR_PLATFORM_LENGTH]) {
	int i, temp, same, i_games = 0, i_genres = 0, i_platforms = 0;
    char c;
    char all_table[FILE_LINE][FILE_LINE_LENGTH];

	open_file_read(file_path);

	//removes the first line which is for column titles
    while (c != '\n') {
    	c = fgetc(fptr);
    }

	while (fgets(all_table[i_games], FILE_LINE_LENGTH, fptr) != NULL) {
		//builds games array
		games[i_games][0] = strtok(all_table[i_games], ",");

		//builds genres array
		genres[i_genres][0] = strtok(NULL, ",");
		//checks not to write an already written genre
		if (i_genres == 0)
			++i_genres;
		else {
			same = 0;
			temp = i_genres - 1;
			while (temp >= 0) {
				if (strcmp(*genres[i_genres], *genres[temp]) == 0) {
					same = 1;
					break;
				}
				--temp;
			}
			if (!same)
				++i_genres;
		}

		//builds platforms array
		platforms[i_platforms][0] = strtok(NULL, ",");
		//checks not to write an already written platform
		if (i_platforms == 0)
			++i_platforms;
		else {
			same = 0;
			temp = i_platforms - 1;
			while (temp >= 0) {
				if (strcmp(*platforms[i_platforms], *platforms[temp]) == 0) {
					same = 1;
					break;
				}
				--temp;
			}
			if (!same)
				++i_platforms;
		}

		strtok(NULL, "\n");
		++i_games;
	}
	close_file(fptr);

    sort_char_array(genres, i_genres);
    sort_char_array(platforms, i_platforms);

    printf("i_games: %d, i_genres: %d, i_platforms: %d\n", i_games, i_genres, i_platforms);
    --i_genres;
    while (i_genres >= 0) {
    	printf("%d: %s\n", i_genres, *genres[i_genres]);
    	--i_genres;
    }
    printf("\n");
    --i_platforms;
    while (i_platforms >= 0) {
    	printf("%d: %s\n", i_platforms, *platforms[i_platforms]);
    	--i_platforms;
    }

	return;
}

void sort_char_array(char *array[][GENRE_OR_PLATFORM_LENGTH], int size) {
	int i, j;
	char temp[GENRE_OR_PLATFORM_LENGTH];

	for (i = 0; i < size; ++i) {
		for (j = i + 1; j < size; ++j) {
			if (strcmp(*array[i], *array[j]) > 0) {
				strcpy(temp, *array[i]);
				strcpy(*array[i], *array[j]);
				strcpy(*array[j], temp);
			}
		}
	}
	return;
}

void build_data_array(char *file_path, float games_data[FILE_LINE][FILE_LINE_LENGTH]) {
	int i, temp, same, i_games = 0, i_genres = 0, i_platforms = 0;
    char c;
    char all_table[FILE_LINE][FILE_LINE_LENGTH];

	open_file_read(file_path);

	//removes the first line which is for column titles
    while (c != '\n') {
    	c = fgetc(fptr);
    }

	while (fgets(all_table[i_games], FILE_LINE_LENGTH, fptr) != NULL) {
		//eliminates game name
		strtok(all_table[i_games], ",");

		//builds genres array
		games_data[i_genres][0] = strtok(NULL, ",");
		//checks not to write an already written genre
		if (i_genres == 0)
			++i_genres;
		else {
			same = 0;
			temp = i_genres - 1;
			while (temp >= 0) {
				if (strcmp(*genres[i_genres], *genres[temp]) == 0) {
					same = 1;
					break;
				}
				--temp;
			}
			if (!same)
				++i_genres;
		}

		//builds platforms array
		platforms[i_platforms][0] = strtok(NULL, ",");
		//checks not to write an already written platform
		if (i_platforms == 0)
			++i_platforms;
		else {
			same = 0;
			temp = i_platforms - 1;
			while (temp >= 0) {
				if (strcmp(*platforms[i_platforms], *platforms[temp]) == 0) {
					same = 1;
					break;
				}
				--temp;
			}
			if (!same)
				++i_platforms;
		}

		strtok(NULL, "\n");
		++i_games;
	}
	close_file(fptr);

    sort_char_array(genres, i_genres);
    sort_char_array(platforms, i_platforms);

    printf("i_games: %d, i_genres: %d, i_platforms: %d\n", i_games, i_genres, i_platforms);
    --i_genres;
    while (i_genres >= 0) {
    	printf("%d: %s\n", i_genres, *genres[i_genres]);
    	--i_genres;
    }
    printf("\n");
    --i_platforms;
    while (i_platforms >= 0) {
    	printf("%d: %s\n", i_platforms, *platforms[i_platforms]);
    	--i_platforms;
    }
}

/*
void get_array_index(char *element[] ,char *array[][GENRE_OR_PLATFORM_LENGTH]) {


}
*/

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
