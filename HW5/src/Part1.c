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
	int menu_choice
	char continue_choice;

	printf("**********Daily Press**********\n\n");
	printf("Today's news are listed for you:\n\n");

	printf("What do you want to do?\n");
	printf("a.Read a new\n");
	printf("b.List the readed news\n");
	printf("c.Get decrypted information from the news\n");
	scanf("%d",&menu_choice);

	printf("Readed news are listed below:");
	printf("Do you want to continue? Yes(y)/No(n):");
	printf("Good Bye");
	return;
}

void read_news(char buffer[500], char file_path[10], int is_Only_Title) {
	switch(is_Only_Title){
	case 0:

		break;
	case 1:

		break;
	}
	return;
}
