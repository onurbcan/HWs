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
	int menuChoice, gameFlag = 0; //game flag for lastly played version (resume/new game)
	char saveChoice = 'Y';
	NPuzzle resumeGame, newGame;
	srand(time(nullptr));

	while (1) {
		// initial menu screen
		while (1) {
			system("clear");
			cout << "Welcome to the N-Puzzle game." << endl;
			cout << "1) Resume" << endl;
			cout << "2) New game" << endl;
			cout << "0) Exit" << endl;
			cout << "Please enter your choice." << endl;
			cin >> menuChoice;
			if (!(menuChoice == 0 || menuChoice == 1 || menuChoice == 2))
				cout << menuChoice << " is an invalid choice. Please try again." << endl;
			else
				break;
		}
		switch (menuChoice) {
		case EXIT:
			system("clear");
			while (gameFlag != 0) {
				cout << "Would you like to save what you played so far to be ";
				cout << "loaded next time? (Y/N)" << endl;
				cin >> saveChoice;
				if (!(saveChoice == 'Y' || saveChoice == 'y' ||
						saveChoice == 'N' || saveChoice == 'n')) {
					cout << saveChoice << " is an invalid choice. ";
					cout << "Please enter Y for Yes or N for No" << endl;
				} else {
					break;
				}
			}
			if (saveChoice == 'Y' || saveChoice == 'y') {
				if (gameFlag == 1)
					resumeGame.writeToFile();
				else if (gameFlag == 2)
					newGame.writeToFile();
				else
					cout << "Sorry that you haven't played here. See you next time. " << endl;
			}
			cout << "Good bye!" << endl;
			break;
		case RESUME:
			gameFlag = 1;
			resumeGame.readFromFile();
			resumeGame.playNPuzzleGame();
			break;
		case NEWGAME:
			gameFlag = 2;
			newGame.buildNewTable();
			newGame.playNPuzzleGame();
			break;
		default:
			break;
		}
		if (menuChoice == 0)
			break;
	}
	return 0;
}
