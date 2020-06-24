//============================================================================
// Name        : CPP_HW4.cpp
// Author      : Onur
// Version     :
// Copyright   :
// Description : N-Puzzle game (OOPv2)
//============================================================================

#include <iostream>
#include "Part1.h"
using namespace std;

int main() {
	int menuChoice, gameFlag = EXIT; //game flag for lastly played version (resume/new game)
	char saveChoice = YES;
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
			if (!(menuChoice == EXIT || menuChoice == RESUME || menuChoice == NEWGAME))
				cout << menuChoice << " is an invalid choice. Please try again." << endl;
			else
				break;
		}
		switch (menuChoice) {
		case EXIT:
			system("clear");
			while (gameFlag != EXIT) {
				cout << "Would you like to save what you played so far to be ";
				cout << "loaded next time? (Y/N)" << endl;
				cin >> saveChoice;
				if (aVALUE <= saveChoice && saveChoice <= zVALUE)
					saveChoice -= LOWERCASEUPPERCASEDIFFERENCE;
				if (!(saveChoice == YES || saveChoice == NO)) {
					cout << saveChoice << " is an invalid choice. ";
					cout << "Please enter Y for Yes or N for No" << endl;
				} else {
					break;
				}
			}
			system("clear");
			if (saveChoice == YES) {
				if (gameFlag == RESUME)
					resumeGame.writeToFile();
				else if (gameFlag == NEWGAME)
					newGame.writeToFile();
				else
					cout << "Sorry that you haven't played here. See you next time. " << endl;
			}
			cout << "Good bye!" << endl;
			break;
		case RESUME:
			gameFlag = RESUME;
			resumeGame.readFromFile();
			resumeGame.playNPuzzleGame();
			break;
		case NEWGAME:
			gameFlag = NEWGAME;
			newGame.buildNewTable();
			newGame.playNPuzzleGame();
			break;
		default:
			break;
		}
		if (menuChoice == EXIT)
			break;
	}
	return 0;
}
