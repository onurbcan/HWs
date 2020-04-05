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
#include <math.h>
#include "Part1.h"

void menu() {
	do {
		printf("**********Daily Press**********\n\n");
		printf("Today's news are listed for you:\n\n");
		print_news(0, 1, 0); //0 to print all news and 1 to print only titles
	} while (menu_cases());
	printf("Good Bye");
	return;
}

int menu_cases() {
	char c, menu_choice, continue_choice;
	int news_choice, readed_news, all_news_index = number_of_news();

	printf("\n");
	printf("What do you want to do?\n");
	printf("a.Read a news\n");
	printf("b.List the readed news\n");
	printf("c.Get decrypted information from the news\n");
	do {
		scanf("%c", &menu_choice);
		while(getchar() != '\n');
		switch (menu_choice) {
		case ('a'):
			printf("Which news text would you like to read?\n");
			do {
				scanf("%d", &news_choice);
			} while (news_choice > all_news_index || news_choice <= 0);
			print_news(news_choice, 0, 0);
			//readed news calculated by converting news_choice to ASCII value
			readed_news = news_choice + 48;
			append_file("files/all_news_id.txt", readed_news);
			break;
		case ('b'):
			printf("Readed news are listed below:\n");
			open_file_read("files/readed_news_id.txt"); //fptr file pointer read
			do {
				c = getc(fptr);
				if(c == '\n' || c == EOF)
					continue;
				printf("%c", c);
			} while (c != EOF);
			close_file(fptr);
			break;
		case ('c'):
			printf("Which news would you like to decrypt?\n");
			do {
				scanf("%d", &news_choice);
			} while (news_choice > all_news_index || news_choice <= 0);
			print_news(news_choice, 0, 0);


			break;
		default:
			break;
		}
	} while(!(menu_choice == 'a' || menu_choice == 'b' || menu_choice == 'c'));
	printf("\nDo you want to continue? Yes(y)/No(n):\n");
	do {
		scanf("%c", &continue_choice);
		while(getchar() != '\n');
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

void print_news(int news_choice, int is_only_title, int is_decrypt) {
	int news_index, //index variable to print news
			buffer_length, //value that returns from read_news function
			buffer_magic_length, //value that returns from print_arrays function
			all_news_index = number_of_news(); //amount of all news
	char buffer[500], buffer_magic[10]; //, file_path[15];

	//if news_choice flag carries 0, loop to print all news performed
	if (news_choice == 0)
		news_index = 1;
	//else only news_choice is printed
	else
		news_index = news_choice;

	do {
		switch (news_index) {
		case (1):
			//file_path[15] = "files/1.txt";
			buffer_length = read_news(buffer, "files/1.txt", is_only_title);
			if (is_only_title)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer_magic, buffer, buffer_length);
			if(is_decrypt)
				read_magic_numbers(buffer_magic, buffer);
			break;
		case (2):
			//file_path[15] = "files/2.txt";
			buffer_length = read_news(buffer, "files/2.txt", is_only_title);
			if (is_only_title)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer_magic, buffer, buffer_length);
			break;
		case (3):
			//file_path[15] = "files/3.txt";
			buffer_length = read_news(buffer, "files/3.txt", is_only_title);
			if (is_only_title)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer_magic, buffer, buffer_length);
			break;
		case (4):
			//file_path[15] = "files/4.txt";
			buffer_length = read_news(buffer, "files/4.txt", is_only_title);
			if (is_only_title)
				printf("Title of %d. news: ", news_index);
			print_arrays(buffer_magic, buffer, buffer_length);
			break;
		default:
			break;
		}
		//if all news to be printed, continue the loop
		if (news_choice == 0)
			++news_index;
		//else break the loop
		else
			break;
	} while (news_index <= all_news_index);
	return;
}

void print_arrays(char buffer_magic[], char buffer[], int length) {
	int i, j = 0;
	for (i = 0; i < length; ++i) {
		printf("%c", buffer[i]);
		if(buffer[i] == '#') {
			buffer_magic[j] = buffer[i+1];
			++j;
		}
	}
	return;
}

int read_news(char buffer[], char file_path[], int is_only_title) {
	int i = 0;
	char c;

	open_file_read(file_path); //fptr file pointer read
	switch (is_only_title) {
	case 0:
		do {
			c = getc(fptr);
			if(c == EOF)
				continue;
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

int number_of_news() {
	int amount, temp_amount;

	open_file_read("files/all_news_id.txt");
	amount = getc(fptr);
	while (temp_amount != EOF) {
		temp_amount = getc(fptr);
		if (temp_amount > amount && temp_amount != '\n')
			amount = temp_amount;
	}
	close_file(fptr);
	//converting ASCII value to decimal by decrementing 48
	amount -= 48;
	return amount;
}

void append_file(char* file_path, char c) {
	char current_c;
	int write_flag = 1;

	open_file_read("files/readed_news_id.txt"); //fptr file pointer read
	do {
		current_c = getc(fptr);
		if(current_c == '\n' || current_c == EOF)
			continue;
		else if(c == current_c)
			write_flag = 0;
	} while (current_c != EOF);
	close_file(fptr);

	open_file_edit("files/readed_news_id.txt"); //fpte file pointer read
	if(write_flag)
		fprintf(fpte, "\n%c", c);
	close_file(fpte);
	return;
}

void read_magic_numbers(char buffer_magic[10], char buffer_news[500]) {
	int i = 0;
	double sum = 0;

	while(buffer_magic[i] != '\0') {
		//sum += g_func(f_func(buffer_magic[i]), i);
		++i;
	}
	//printf("%f", g_func(f_func(1), 1));
	return;
}

double f_func(int x) {
	return pow(x, 3) - pow(x, 2) + 2;
}

double g_func(double f(int x), int a) {
	//return pow(f_func(x), 2);
	return 0;
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

void open_file_edit(char *file_path) {
	if ((fpte = fopen(file_path, "a+")) == NULL) {
		printf("Error! File not edited.");
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
