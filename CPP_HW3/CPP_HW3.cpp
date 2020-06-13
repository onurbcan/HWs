//============================================================================
// Name        : CPP_HW3.cpp
// Author      : Onur
// Version     :
// Copyright   : 
// Description : N-Puzzle game (OOP)
//============================================================================

#include <iostream>
#include "Part1.h"
using namespace std;

int main() {
	int menu_choice, game_flag = 0; //game flag for lastly played version (resume/new game)
	char save_choice = 'Y';
	NPuzzle resume_game, new_game;
	NPuzzle::Board new_board;
	srand(time(nullptr));

	while (1) {
		// initial menu screen
		while (1) {
			system("clear");
			cout << "Welcome to the N-Puzzle game." << endl;
			cout << "1) Resume" << endl;
			cout << "2) New game" << endl;
			cout << "0) Quit" << endl;
			cout << "Please enter your choice." << endl;
			cin >> menu_choice;
			if (!(menu_choice == 0 || menu_choice == 1 || menu_choice == 2))
				cout << menu_choice << " is an invalid choice. Please try again." << endl;
			else
				break;
		}
		switch (menu_choice) {
		case (0):
			system("clear");
			while (game_flag != 0) {
				cout << "Would you like to save what you played so far to be ";
				cout << "loaded next time? (Y/N)" << endl;
				cin >> save_choice;
				if (!(save_choice == 'Y' || save_choice == 'y' ||
						save_choice == 'N' || save_choice == 'n')) {
					cout << save_choice << " is an invalid choice. ";
					cout << "Please enter Y for Yes or N for No" << endl;
				} else {
					break;
				}
			}
			if (save_choice == 'Y' || save_choice == 'y') {
				if (game_flag == 1)
					resume_game.writeToFile();
				else if (game_flag == 2)
					new_game.writeToFile();
				else
					cout << "Sorry that you haven't played here. See you next time. " << endl;
			}
			cout << "Good bye!" << endl;
			break;
		case (1):
			game_flag = 1;
			resume_game.readFromFile();
			resume_game.play_n_puzzle_game();
			break;
		case (2):
			game_flag = 2;
			new_game.build_new_table();
			new_game.play_n_puzzle_game();
			break;
		default:
			break;
		}
		if (menu_choice == 0)
			break;
	}
	return 0;
}
