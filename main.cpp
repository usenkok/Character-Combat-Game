/*********************************************************************
** Program name:
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Main program initiating combat game
*********************************************************************/

#include "menuProj3.hpp"

#include "barbarian.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

#include "die.hpp"
#include "game.hpp"


int main()
{
	int menuChoice = 0;
	int characterOne = 0;
	int characterTwo = 0;
	int playAgainChoice = 0;

	srand((unsigned)time(NULL));


	printMainMenuTitle();

	do {

		printMenuOptions();

		getValidInteger(&characterOne, "\nPlease enter a character number for Player 1.", 0, 6);

		getValidInteger(&characterTwo, "\nPlease enter a character number for Player 2.", 0, 6);

		//begin game with chosen characters
		Game g1(static_cast<CharacterType>(characterOne), static_cast<CharacterType>(characterTwo));


		g1.playGame();

		printMenuPlayAgain();
		
		getValidInteger(&playAgainChoice, "\nPlease enter 1 or 2", 0, 3);

	} while (playAgainChoice != 2);

	cout << "\nGoodbye" << endl;

    return 0;
}

