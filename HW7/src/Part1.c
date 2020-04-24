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

    char *names[GAME_LINE];
    char *genres[GENRE_OR_PLATFORM_LINE];
	char *platforms[GENRE_OR_PLATFORM_LINE];
    float games_data[GAME_LINE][GAME_DATA_ELEMENTS];


	build_arrays(file_path, names, genres, platforms, games_data);

	/*
	int menu_choice;
	do {
		menu(&menu_choice);
		menu_cases(menu_choice);
	} while (menu_choice != 8);
	*/

	return;
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

void build_arrays(char *file_path, char **names, char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]) {
	int temp, same, i_games = 0, i_genres = 0, i_platforms = 0;
    char c, *temp_str;
    char all_table[FILE_LINE][FILE_LINE_LENGTH];

	open_file_read(file_path);

	//removes the first line which is for column titles
    while (c != '\n') {
    	c = fgetc(fptr);
    }

	while (fgets(all_table[i_games], FILE_LINE_LENGTH, fptr) != NULL) {
		//builds names array
		names[i_games] = strtok(all_table[i_games], ",");

		/* builds genres array
		 * and genres column of game data
		 */
		temp_str = strtok(NULL, ",");
		//checks not to write an already written genre
		if (i_genres == 0) {
			game_data[i_games][0] = (float)i_genres;
			genres[i_genres] = temp_str;
			++i_genres;
		} else {
			same = 0;
			temp = i_genres - 1;
			while (temp >= 0) {
				if (strcmp(temp_str, genres[temp]) == 0) {
					same = 1;
					break;
				}
				--temp;
			}
			if (!same) {
				game_data[i_games][0] = (float)i_genres;
				genres[i_genres] = temp_str;
				++i_genres;
			} else {
				game_data[i_games][0] = (float)temp;
			}
		}

		/* builds platforms array
		 * and platforms column of game data
		 */
		temp_str = strtok(NULL, ",");
		//checks not to write an already written platform
		if (i_platforms == 0) {
			game_data[i_games][1] = (float)i_platforms;
			platforms[i_platforms] = temp_str;
			++i_platforms;
		} else {
			same = 0;
			temp = i_platforms - 1;
			while (temp >= 0) {
				if (strcmp(temp_str, platforms[temp]) == 0) {
					same = 1;
					break;
				}
				--temp;
			}
			if (!same) {
				game_data[i_games][1] = (float)i_platforms;
				platforms[i_platforms] = temp_str;
				++i_platforms;
			} else {
				game_data[i_games][1] = (float)temp;
			}
		}

		/* builds year_of_release column of game data */
		temp_str = strtok(NULL, ",");
		game_data[i_games][2] = string_float_converter(temp_str);

		/* builds na_sales column of game data */
		temp_str = strtok(NULL, ",");
		game_data[i_games][3] = string_float_converter(temp_str);

		/* builds eu_sales column of game data */
		temp_str = strtok(NULL, ",");
		game_data[i_games][4] = string_float_converter(temp_str);

		/* builds global_sales column of game data */
		temp_str = strtok(NULL, ",");
		game_data[i_games][5] = string_float_converter(temp_str);

		/* builds user_score column of game data */
		temp_str = strtok(NULL, "\n");
		game_data[i_games][6] = string_float_converter(temp_str);

		printf("i_games: %d: %f %f %f %f %f %f %f\n", i_games, game_data[i_games][0], game_data[i_games][1], game_data[i_games][2],game_data[i_games][3],game_data[i_games][4], game_data[i_games][5], game_data[i_games][6]);

		++i_games;
	}
	close_file(fptr);



    printf("i_games: %d, i_genres: %d, i_platforms: %d\n", i_games, i_genres, i_platforms);
    --i_genres;
    while (i_genres >= 0) {
    	printf("%d: %s\n", i_genres, genres[i_genres]);
    	--i_genres;
    }
    printf("\n");
    --i_platforms;
    while (i_platforms >= 0) {
    	printf("%d: %s\n", i_platforms, platforms[i_platforms]);
    	--i_platforms;
    }

	return;
}

void sort_char_array(char *array[], int size) {
	int i, j;
	char *temp;

	for (i = 0; i < size - 1; ++i) {
		for (j = i + 1; j < size; ++j) {
			if (strcmp(array[i], array[j]) > 0) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return;
}

float get_array_index(char *element, char *array[]) {
	int i = 0;

	for (i = 0; i < GENRE_OR_PLATFORM_LENGTH; ++i) {
		if (strcmp(element, array[i]) == 0)
			return (i);
	}
	return (i);
}

float string_float_converter(char *num_str) {
	int i, d, p, if_dec = 0, to_power = 0;
	float num = 0, multiplier;

	if (strcmp(num_str, "not_available") == 0)
		return (-1);

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
