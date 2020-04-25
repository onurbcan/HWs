/*
 * Part1.c
 * Description: Part 0: The program reads a text file named ‘Video_Games.txt’.
 * Every row of this text file includes several informations about a single
 * game. You are asked to read every row as a string and decompose these
 * informations which are separated by commas.
 * • The program should keep the names of the games in a one-dimensional string
 * array.
 * • The program should keep the names of the genres & platforms in two
 * different one-dimensional string arrays. Please be sure that the elements are
 * not overlapping! I.e. there shouldn’t be more than one ‘simulation’ in the
 * array just because there are more than one simulation games.
 * • The program should keep the data of every single game in a two-dimensional
 * float array. This array should include 7 different data for every game,
 * including genre&platform. The genre/platform cell should point the index of
 * the genre/platform array which stores the names of the related genre/
 * platform.
 * 	 For example;
 * 	 If the genre of the game is ‘simulation’ and the index of the string
 *  ‘simulation’ in the array of genres is 5, then the cell which shows the
 *  genre of the game should be ‘5.0’ in the float array.
 * 	 Be careful! Some of the games has no value for ‘global_sales’ data. They
 *  have a string ‘not_available’ instead of a float number. Store them in the
 *  float array wisely cause you will need that information later on!
 * • The float array shouldn’t include any information about the name of the
 * games since they are stored in a string array with the same indices.
 *
 * Part 1: (10 pts) The program should support 8 different operations.
 * Therefore, there should be a menu as below. The program should terminate if
 * and only if the user enters ‘8’ as the input. The menu should appear again
 * and again if an input is invalid or if the previously requested operation is
 * done. If the menu appears because of an invalid input, there should be an
 * error message too.
 * Part 2: (20 pts) 0 th and the 1 st operations are almost the same. If the
 * user enter ‘0’ (or ‘1’) as input, then the program should list the genres (or
 * the platforms) as strings.
 * Part 3: (15 pts) 2 nd operation lists the games according to an information
 * received from the user. Firstly, the program asks for a ‘year’, after that
 * the program asks ‘until that year or since that year?’. Finally the program
 * lists the names of the all games which released until/since that year. Don’t
 * forget that the program should handle the invalid year or period values. I.e.
 * if the oldest game was released in 1995 and the user wants to print the game
 * which released until 1996, the program should show an error message and asks
 * for new values since there is no game before 1996.
 * Part 4: (15 Pts) The 3 rd operation asks for a game name from the user. If
 * the input matches with a name from the name array, then the program prints
 * all information of that game. If the input doesn’t match with any element of
 * the name array, then it should give an error message and ask for a new input.
 * If the ‘global_sales’ information of that game was ‘not_available’ when the
 * program read it, then the users should see it as ‘Not Available’.
 * Part 5: (10 pts) 4 th operation basically calculates and prints the average
 * of the user scores of all games.
 * Part 6: (10 pts) 5 th operation asks a game name and prints either the game
 * was more populer in NA or EU according to the sales. If the sales are equal,
 * specify that. Again, if the game name is not in the database, the program
 * should ask for another name.
 * Part 7: (20 pts) 6 th and 7 th operations are printing the frequences of
 * every genre/platform. I.e. they prints the number of games for every genre/
 * platform.
 *
 * ❖ You can assume that;
 * 	➢ The longest game name has 100 characters
 * 	➢ The longest genre or platform name has 20 characters.
 * 	➢ The longest row of the text file has 200 characters
 * ❖ You are not allowed to use any library other than;
 * 	➢ <stdio.h>
 * 	➢ <string.h>
 * 	➢ <stdlib.h>
 * ❖ You can use the ‘strtod’ function from <stdlib.h> library to parse a string
 * to float.
 * ❖ Some games are released on different platforms, which means some of the
 * game names are the same. When you are search for a game with the name of it,
 * pick the first one you find.
 * ❖ You can write your own functions to make things easier.
 * ❖ Don’t forget that the program shouldn’t terminate when an operation is
 * done.
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
 * The Video games accounting */
void video_games(char *file_path){
	int menu_choice;
    char *names[GAME_LINE];
    char *genres[GENRE_LINE];
	char *platforms[PLATFORM_LINE];
    float games_data[GAME_LINE][GAME_DATA_ELEMENTS];

	build_arrays(file_path, names, genres, platforms, games_data);
	system("clear");
	do {
		menu(&menu_choice);
		menu_cases(menu_choice, names, genres, platforms, games_data);
	} while (menu_choice != 8);
	return;
}

/** 2.1) Build arrays (for names and game_data)
 * 		The program reads a text file using file_path. Every row of this text file
 * includes several information about a single game. Every row is read as a
 * string and these information which are separated by commas is decomposed.
 * 		The program keeps the names of the games in a one-dimensional string
 * array.
 * 		The program keeps the names of the genres & platforms in two different
 * one-dimensional string arrays and these elements are not overlapping. I.e.
 * there is no more than one ‘simulation’ in the array just because there are
 * more than one simulation games.
 * 		The program keeps the data of every single game in a two-dimensional
 * float array. This array includes 7 different data for every game, including
 * genre&platform. The genre/platform cell points the index of the genre/
 * platform array which stores the names of the related genre/platform.
 * 	 For example;
 * 	 If the genre of the game is ‘simulation’ and the index of the string
 *  ‘simulation’ in the array of genres is 5, then the cell which shows the
 *  genre of the game is ‘5.0’ in the float array.
 * 	 However some of the games has no value for ‘global_sales’ data. They have a
 * 	string ‘not_available’ instead of a float number. These are stored in the
 * 	float array wisely as (-1) because this information is used later on.
 * 		The float array does not include any information about the name of the
 * games since they are stored in a string array with the same indices. */
void build_arrays(char *file_path, char **names, char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]) {
	int i_games = 0, i_genres = 0, i_platforms = 0;
    char c, *temp_str;
    char all_table[GAME_LINE][FILE_LINE_LENGTH];

	open_file_read(file_path);

	/* removes the first line which is for column titles */
    while (c != '\n') {
    	c = fgetc(fptr);
    }

	while (fgets(all_table[i_games], FILE_LINE_LENGTH, fptr) != NULL) {
		/* builds names array */
		names[i_games] = strtok(all_table[i_games], ",");

		/* builds genres array
		 * and genres column of game data
		 */
		temp_str = strtok(NULL, ",");
		build_single_arrays(i_games, &i_genres, 0, temp_str, genres, game_data);

		/* builds platforms array
		 * and platforms column of game data
		 */
		temp_str = strtok(NULL, ",");
		build_single_arrays(i_games, &i_platforms, 1, temp_str, platforms, game_data);

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

		//Debug
		//printf("%d: %f %f %f %f %f %f %f\n", i_games, game_data[i_games][0], game_data[i_games][1], game_data[i_games][2],game_data[i_games][3],game_data[i_games][4], game_data[i_games][5], game_data[i_games][6]);
		//printf("%d: %s\n", i_games, names[i_games]);

		++i_games;
	}
	close_file(fptr);

	/* Debug
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
	*/
	return;
}

/** 2.2) Build single arrays (for genres and platforms)
 * Genres and platforms arrays and related columns of game_data array built
 * using the separate build_single_arrays function.
 */
void build_single_arrays(int i_games, int *i_array, int game_data_index, char *str, char **array, float game_data[][GAME_DATA_ELEMENTS]) {
	int temp, same;

	/* checks not to write an already written genre or platform */
	if (*i_array == 0) {
		game_data[i_games][game_data_index] = (float)*i_array;
		array[*i_array] = str;
		++*i_array;
	} else {
		same = 0;
		temp = *i_array - 1;
		while (temp >= 0) {
			if (strcmp(str, array[temp]) == 0) {
				same = 1;
				break;
			}
			--temp;
		}
		if (!same) {
			game_data[i_games][game_data_index] = (float)*i_array;
			array[*i_array] = str;
			++*i_array;
		} else {
			game_data[i_games][game_data_index] = (float)temp;
		}
	}
	return;
}

/** 3.1) Menu screen
 * The program supports 8 different operations. Therefore, there is a menu as
 * below. The program terminates if and only if the user enters ‘8’ as the
 * input. The menu appears again and again if an input is invalid or if the
 * previously requested operation is done. If the menu appears because of an
 * invalid input, there is an error message too. */
void menu(int *menu_choice) {
	printf("------------------------MENU-----------------------------\n");
	printf("| %d) %-50s |\n", 0, "List of the genres");
	printf("| %d) %-50s |\n", 1, "List of the platforms");
	printf("| %d) %-50s |\n", 2, "List of the games through the years");
	printf("| %d) %-50s |\n", 3, "All information of a single game");
	printf("| %d) %-50s |\n", 4, "Average of the user score");
	printf("| %d) %-50s |\n", 5, "Geographical information of a single game");
	printf("| %d) %-50s |\n", 6, "Frequences of the genres");
	printf("| %d) %-50s |\n", 7, "Frequences of the platforms");
	printf("| %d) %-50s |\n", 8, "Exit");
	printf("---------------------------------------------------------\n");

	printf("\nPlease select an operation: ");
	scanf("%d", menu_choice);
	printf("\n");
	return;
}

/** 3.2) Menu cases and related operations
 * 		0th and the 1st operations are almost the same. If the user enter ‘0’
 * (or ‘1’) as input, then the program lists the genres (or the platforms)
 * as strings.
 * 		2nd operation lists the games according to an information received from
 * the user. Firstly, the program asks for a ‘year’, after that the program asks
 * ‘until that year or since that year?’. Finally the program lists the names of
 * the all games which released until/since that year. The program handles also
 * the invalid year or period values. I.e. if the oldest game was released in
 * 1985 and the user wants to print the game which released until 1984, the
 * program shows an error message and asks for new values since there is no game
 * before 1985.
 * 		3rd operation asks for a game name from the user. If the input matches
 * with a name from the name array, then the program prints all information of
 * that game. If the input doesn’t match with any element of the name array,
 * then it gives an error message and asks for a new input. If the
 * ‘global_sales’ information of that game is ‘not_available’ when the program
 * read it, then the user sees it as ‘not available’.
 * 		4th operation basically calculates and prints the average of the user
 * scores of all games.
 * 		5th operation asks a game name and prints either the game is more
 * populer in NA or EU according to the sales. If the sales are equal, it
 * specifies that. Again, if the game name is not in the database, the program
 * asks for another name.
 * 		6th and 7th operations are printing the frequences of every genre/
 * platform. I.e. they prints the number of games for every genre/ platform. */
void menu_cases(int menu_choice, char **names, char **genres, char **platforms, float game_data[][GAME_DATA_ELEMENTS]) {
	int i, index, year, choice, temp;
	float temp_f;
	char game_name[GAME_LENGTH], temp_c[15];
	system("clear");
	switch (menu_choice) {
	case 0:
		printf("List of the genres:\n\n");
		for (i = 0; i < GENRE_LINE; ++i)
			printf("%d: %s\n", i, genres[i]);
		printf("\n");
		break;
	case 1:
		printf("List of the platforms:\n\n");
		for (i = 0; i < PLATFORM_LINE; ++i)
			printf("%d: %s\n", i, platforms[i]);
		printf("\n");
		break;
	case 2:
		do {
			do {
				printf("Enter a year (or -1 to quit): ");
				scanf("%d", &year);
				if (year == -1) {
					printf("\n");
					break;
				}
				else if (!(1985 <= year && year <= 2005))
					printf("There is no game until 1985 or since 2005. Please try again accordingly.\n");
			} while (!(1985 <= year && year <= 2005));
			if (year == -1)
				break;
			do{
				printf("Until (0) or since (1) %d (or -1 to quit): ", year);
				scanf("%d", &choice);
				if (choice == -1)
					break;
				else if (!(choice == 0 || choice == 1))
					printf("%d is an invalid choice. It should be either 0 or 1. Please try again.\n", choice);
			} while (!(choice == 0 || choice == 1));
			printf("\n");
			if (choice == -1)
				break;
			else if ((year == 1985 && choice == 0) || (year == 2005 && choice == 1)) {
				if (choice == 0)
					printf("There is no game until 1985. Please try again accordingly.\n\n");
				else
					printf("There is no game since 2005. Please try again accordingly.\n\n");
			}
		} while ((year == 1985 && choice == 0) || (year == 2005 && choice == 1));
		/* if any of year or choice is -1, then break the case */
		if (year == -1 || choice == -1)
			break;
		index = 0;
		switch (choice) {
		case 0:
			printf("Games until %d are:\n\n", year);
			for (i = 0; i < GAME_LINE; ++i) {
				if (game_data[i][2] <= year) {
					printf("%d: %s\n", index, names[i]);
					++index;
				}
			}
			break;
		case 1:
			printf("Games since %d are:\n\n", year);
			for (i = 0; i < GAME_LINE; ++i) {
				if (game_data[i][2] >= year) {
					printf("%d: %s\n", index, names[i]);
					++index;
				}
			}
			break;
		default:
			break;
		}
		printf("\nTotal %d results listed above.\n\n", index);
		break;
	case 3:
		do {
			printf("Please enter the name of the game: ");
			scanf("%s", game_name);
			printf("\n");
			index = get_array_index(game_name, names);
			if (index >= GAME_LINE)
				printf("%s is an invalid game name. Please try again.\n\n", game_name);
		} while (index >= GAME_LINE);

		/* simply prints proved name value (string) */
		printf("%-13s\t%s\n", "Name:", game_name);

		/* finds relevant genre value (string) from genres array */
		temp = game_data[index][0];
		printf("%-13s\t%s\n", "Genre:", genres[temp]);

		/* finds relevant platform value (string) from platforms array */
		temp = game_data[index][1];
		printf("%-13s\t%s\n", "Platform:", platforms[temp]);

		/* converts year_of_release value (without precision) to string */
		temp_f = game_data[index][2];
		float_string_converter(temp_f, temp_c, 0);
		printf("%-13s\t%s\n", "Year:", temp_c);

		/* converts sales_na value (with precision) to string */
		temp_f = game_data[index][3];
		float_string_converter(temp_f, temp_c, 1);
		printf("%-13s\t%s\n", "Sales in NA:", temp_c);

		/* converts sales_eu value (with precision) to string */
		temp_f = game_data[index][4];
		float_string_converter(temp_f, temp_c, 1);
		printf("%-13s\t%s\n", "Sales in EU:", temp_c);

		/* converts total_sales value (with precision) to string */
		temp_f = game_data[index][5];
		float_string_converter(temp_f, temp_c, 1);
		printf("%-13s\t%s\n", "Total sales:", temp_c);

		/* converts user_score value (with precision) to string */
		temp_f = game_data[index][6];
		float_string_converter(temp_f, temp_c, 1);
		printf("%-13s\t%s\n", "User score:", temp_c);
		printf("\n");
		break;
	case 4:
		for (i = 0; i < GAME_LINE; ++i) {
			temp_f += game_data[i][6];
		}
		temp_f /= GAME_LINE;
		printf("Average of the user scores for all %d games: %f\n", GAME_LINE, temp_f);
		printf("\n");
		break;
	case 5:
		do {
			printf("Please enter the name of the game: ");
			scanf("%s", game_name);
			printf("\n");
			index = get_array_index(game_name, names);
			if (index >= GAME_LINE)
				printf("%s is an invalid game name. Please try again.\n", game_name);
		} while (index >= GAME_LINE);
		if (game_data[index][3] == game_data[index][4])
			printf("This game was equal popular in North America and Europe\n");
		else if (game_data[index][3] > game_data[index][4])
			printf("This game was more popular in North America\n");
		else
			printf("This game was more popular in Europe\n");
		printf("\n");
		break;
	case 6:
		printf("Frequences of the genres:\n\n");
		for (i = 0; i < GENRE_LINE; ++i) {
			temp = 0;
			for (index = 0; index < GAME_LINE; ++index) {
				if (game_data[index][0] == i)
					++temp;
			}
			printf("%-15s\t%d\n", genres[i], temp);
		}
		printf("\n");
		break;
	case 7:
		printf("Frequences of the platforms:\n\n");
		for (i = 0; i < PLATFORM_LINE; ++i) {
			temp = 0;
			for (index = 0; index < GAME_LINE; ++index) {
				if (game_data[index][1] == i)
					++temp;
			}
			printf("%-5s\t%d\n", platforms[i], temp);
		}
		printf("\n");
		break;
	case 8:
		printf("Good bye!\n");
		break;
	default:
		printf("Please try again.\n\n");
		break;
	}
	return;
}

/** 4.1) Get array index
 * Returns the index value (in float type) of the element in the relevant
 * array */
float get_array_index(char *element, char *array[]) {
	int i = 0;

	for (i = 0; i < GAME_LINE; ++i) {
		if (strcmp(element, array[i]) == 0)
			return (i);
	}
	return (i);
}

/** 4.2) String float converter
 * Converts string value to float and returns also in this type */
float string_float_converter(char *num_str) {
	int i, d, p, if_dec = 0, to_power = 0;
	float num = 0, multiplier;

	if (strcmp(num_str, "not_available") == 0)
		return (-1);

	/* checks if there is decimal part */
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

/** 4.3) Float string converter
 * Converts float value to string by changing the input array in the parameter */
void float_string_converter(float num, char *num_str, int precision) {
	if (num < 0) {
		strcpy(num_str, "not available");
	} else {
		if (precision)
			sprintf(num_str, "%.2f", num);
		else
			sprintf(num_str, "%.0f", num);
	}
	return;
}

/** 5.1) Open file read
 * Opens the file to be read using the address and file name (together with
 * file type) in the parameter path.*/
void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

/** 5.2) Open file write
 * Opens the file to be written using the address and file name (together with
 * file type) in the parameter path. */
void open_file_write(char *file_path) {
	if ((fptw = fopen(file_path, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

/** 5.3) Open file edit
 * Opens the file to be edited using the address and file name (together with
 * file type) in the parameter path. */
void open_file_edit(char *file_path) {
	if ((fpte = fopen(file_path, "a+")) == NULL) {
		printf("Error! File not edited.");
		exit(1);
	}
	return;
}

/** 5.4) Close file
 * Closes the file using the file pointer in the parameter. */
void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}
