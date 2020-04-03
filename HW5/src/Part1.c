/*
 * Part1.c
 * Description: Every day, 4 reliable and encrypted news texts are presented to
 * the heads of state selected from thousands of Covid-19 related news.
 * (Selected news of today is in the news folder.) The first line of news texts
 * always includes the title of the news. The other lines are the content of the
 * news text.
 * -> First of all, you should list the headlines of news texts to produce the
 * following output.
 * -> Then, you should print the menu containing the actions that can be performed
 * on the screen.
 * -> If the user chooses the option 'a', you should ask which news text you want
 * to read and then print the news text on the screen depending on that choice.
 * After the news text is displayed, the user should be asked if he wants to
 * continue reading. If it wants to continue, the initial menu should be
 * displayed, otherwise the program should be finished.
 *
 * Assume that the size of the text in the text files will be a maximum of 500
 * characters.
 * You should perform all selection operations within a menu () function, but
 * for all other operations that should be done depending on these selections,
 * you should design the functions whose prototype is given below.
 *
 * void menu()
 *
 * to read the news from the folder:
 * [This function reads the entire news text when the value of is_Only_title is
 * 0, and only the title of the news text when 1 arrives.]
 *
 * void read_news(char buffer[500], char file_path[10], int is_Only_Title)
 *
 *  Created on: Mar 31, 2020
 *      Author: onur
 */

#include <stdio.h>
#include <stdlib.h>
#include "Part1.h"

void menu() {
	do {
		printf("**********Daily Press**********\n\n");
		printf("Today's news are listed for you:\n\n");
		print_news(1); //1 to print only titles
	} while (menu_cases());
	printf("Good Bye");
	return;
}

int menu_cases() {
	char c, menu_choice, continue_choice;

	printf("\n");
	printf("What do you want to do?\n");
	printf("a.Read a new\n");
	printf("b.List the readed news\n");
	printf("c.Get decrypted information from the news\n");
	scanf("%c", &menu_choice);
	switch (menu_choice) {
	case ('a'):
		break;
	case ('b'):
		printf("Readed news are listed below:\n");
		open_file_read("files/readed_news_id.txt"); //fptr file pointer read
		do {
			c = getc(fptr);
			printf("%c", c);
		} while (c != EOF);
		close_file(fptr);
		break;
	case ('c'):
		//printf("Which news would you like to decrypt? ");
		break;
	default:
		break;
	}
	printf("Do you want to continue? Yes(y)/No(n):");
	do {
		scanf("%c", &continue_choice);
		if (continue_choice == 'N' || continue_choice == 'n') {
			//returns (0) to continue while loop in menu function
			return (0);
		} else if (continue_choice == 'Y' || continue_choice == 'y') {
			//returns (1) to continue while loop in menu function
			return (1);
		}
	} while (!(continue_choice == 'N' || continue_choice == 'n'
			|| continue_choice == 'Y' || continue_choice == 'y'));
	return (1);
}

void print_news(int only_titles) {
	int news_index, array_length;
	char buffer[500]; //, file_path[10];

	for (news_index = 1; news_index <= 4; ++news_index) {
		switch (news_index) {
		case (1):
			array_length = read_news(buffer, "files/1.txt", only_titles);
			if (only_titles)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer, array_length);
			break;
		case (2):
			array_length = read_news(buffer, "files/2.txt", only_titles);
			if (only_titles)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer, array_length);
			break;
		case (3):
			array_length = read_news(buffer, "files/3.txt", only_titles);
			if (only_titles)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer, array_length);
			break;
		case (4):
			array_length = read_news(buffer, "files/4.txt", only_titles);
			if (only_titles)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer, array_length);
			break;
		}
	}
	return;
}

void print_arrays(char buffer[], int length) {
	int i;
	for (i = 0; i < length; ++i) {
		printf("%c", buffer[i]);
	}
	return;
}

int read_news(char buffer[], char file_path[], int is_Only_Title) {
	int i = 0;
	char c;

	open_file_read(file_path); //fptr file pointer read
	switch (is_Only_Title) {
	case 0:
		do {
			c = getc(fptr);
			buffer[i] = c;
			++i;
		} while (c != EOF);
		break;
	case 1:
		do {
			c = getc(fptr);
			buffer[i] = c;
			++i;
		} while (c != '\n');
		break;
	}
	close_file(fptr);
	return (i);
}

void open_file_read(char *file_path) {
	if ((fptr = fopen(file_path, "r")) == NULL) {
		printf("Error! File not found.");
		exit(1);
	}
	return;
}

void open_file_write(char *file_path) {
	if ((fptw = fopen(file_path, "w")) == NULL) {
		printf("Error! File not created.");
		exit(1);
	}
	return;
}

void close_file(FILE *file_pointer) {
	if (fclose(file_pointer) != 0) {
		printf("Error! File not closed.");
		exit(1);
	}
	return;
}
