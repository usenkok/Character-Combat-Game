/*********************************************************************
** Program name: game.cpp
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Implementation of game class
*********************************************************************/

#include "game.hpp"

/******************************************************************
*                       Game::Game
* Default constructor to use if wanting to manually set players
/******************************************************************/
Game::Game()
{
	//initialize member attributes
	roundNbr = 1;
	playerOneInflictedDamage = 0;
	playerTwoInflictedDamage = 0;
	roundResult = NONE;
	gameResult = NONE;

}


/******************************************************************
*            Game::Game(CharacterType c1, CharacterType c2)
* Constructor to set player character types
/******************************************************************/

Game::Game(CharacterType c1, CharacterType c2)
{
	switch (c1)
	{
	case BARBARIAN: {playerOne = new Barbarian;
				  	 playerOneString = "Player 1 - Barbarian";}
				break;

	case VAMPIRE: {playerOne = new Vampire;
					playerOneString = "Player 1 - Vampire";}
				break;

	case BLUEMEN: {playerOne = new Bluemen;
					playerOneString = "Player 1 - Bluemen";}
				break;

	case MEDUSA: {playerOne = new Medusa;
		 			playerOneString = "Player 1 - Medusa";}
				break;

	case HARRY_POTTER: {playerOne = new HarryPotter;
				 		playerOneString = "Player 1 - Harry Potter";}
				break;
	}


	switch (c2)
	{
	case BARBARIAN: { playerTwo = new Barbarian;
					playerTwoString = "Player 2 - Barbarian";}
				break;

	case VAMPIRE: {playerTwo = new Vampire;
					playerTwoString = "Player 2 - Vampire";}
				break;

	case BLUEMEN: {playerTwo = new Bluemen;
					playerTwoString = "Player 2 - Bluemen";}
				break;

	case MEDUSA: { playerTwo = new Medusa;
					playerTwoString = "Player 2 - Medusa";}
				break;

	case HARRY_POTTER: {playerTwo = new HarryPotter;
						playerTwoString = "Player 2 - Harry Potter";}
				break;
	}

	roundNbr = 1;
	playerOneInflictedDamage = 0;
	playerTwoInflictedDamage = 0;
	roundResult = NONE;
	gameResult = NONE;

}

/******************************************************************
*                       Game::~Game
* destructor
/******************************************************************/
Game::~Game()
{
	//delete characters
	if (playerOne != NULL)
	{
		delete playerOne;
		playerOne = NULL;
	}

	if (playerTwo != NULL)
	{
		delete playerTwo;
		playerTwo = NULL;
	}
}


/******************************************************************
*         Game::setPlayerString(Character * charPlayer)
* For use with manually setting characters created outside this class
/******************************************************************/
void Game::setPlayerString(Character * charPlayer, int numPlayer)
{
	CharacterType c1 = charPlayer->getCharacterType();
	
	
	// set string according to player type
	if (numPlayer == 1)
	{

		switch (c1)
		{
		case BARBARIAN:		playerOneString = "Player 1 - Barbarian";
			break;

		case VAMPIRE:		playerOneString = "Player 1 - Vampire";
			break;

		case BLUEMEN:		playerOneString = "Player 1 - Bluemen";
			break;

		case MEDUSA:		playerOneString = "Player 1 - Medusa";
			break;

		case HARRY_POTTER: playerOneString = "Player 1 - Harry Potter";
			break;
		}
	}

	else if (numPlayer == 2)
	{
		switch (c1)
		{
		case BARBARIAN:		playerTwoString = "Player 2 - Barbarian";
			break;

		case VAMPIRE:		playerTwoString = "Player 2 - Vampire";
			break;

		case BLUEMEN:		playerTwoString = "Player 2 - Bluemen";
			break;

		case MEDUSA:		playerTwoString = "Player 2 - Medusa";
			break;

		case HARRY_POTTER: playerTwoString = "Player 2 - Harry Potter";
			break;
		}
	}
}


/******************************************************************
*                       Game::setPlayer1(Character * p1)
* Assigns a character to Player 1 role
/******************************************************************/
void Game::setPlayer1(Character * p1)
{
	playerOne = p1;
	setPlayerString(p1, 1);
}

/******************************************************************
*                       Game::getPlayer1()
* Returns object that is assigned Player 1
/******************************************************************/

Character * Game::getPlayer1()
{
	return playerOne;
}

/******************************************************************
*                       Game::setPlayer2(Character * p2)
* Assigns a character to Player 2 role
/******************************************************************/

void Game::setPlayer2(Character * p2)
{
	playerTwo = p2;
	setPlayerString(p2, 2);
}


/******************************************************************
*                       Game::getPlayer2()
* Returns object that is assigned Player 2
/******************************************************************/
Character * Game::getPlayer2()
{
	return playerTwo;
}


/******************************************************************
*                       Game::playGame()
* Main function that coordinates game beginning, rounds, and game end
/******************************************************************/
void Game::playGame()
{
	//Print beginning game banner
	printBeginGame();

	//print player starting health stats
	printRoundResults();

	//game plays until a character dies (strength == 0, char status is DEAD or 0)
	while (playerOne->getHealthStatus() == ALIVE && playerTwo->getHealthStatus() == ALIVE)
	{
		playRound();
	}

	//Drop out of loop when a character dies. Print results
	printGameResults();
}



/******************************************************************
*                       Game::playRound()
* Main function driving logic of attacker and defender events
/******************************************************************/

void Game::playRound()
{
	//a round consists of two attacks
	//attack and defense player1/player2
	//attack and defense player2/player1

	printRoundHeader();

	//playerOne attacks first
	if (playerTwo->getHealthStatus() == ALIVE)
	{
		playerTwoInflictedDamage = playerTwo->defend(playerOne->attack());

		printAttackResults(playerOne, 1);

		printRoundResults();
		
		if (playerTwo->getHealthStatus() == DEAD)
		{	//Set winner to playerOne
			roundResult = PLAYER1;
			gameResult = PLAYER1;
			printDeadCharacter(playerTwo, 2);
		}
	}

	//Second player gets their turn if they are still with us
	if (playerTwo->getHealthStatus() == ALIVE)
	{
		playerOneInflictedDamage = playerOne->defend(playerTwo->attack());

		printAttackResults(playerTwo, 2);

		printRoundResults();

		if (playerOne->getHealthStatus() == DEAD)
		{   //set winner to playerTwo
			roundResult = PLAYER2;
			gameResult = PLAYER2;
			printDeadCharacter(playerOne, 1);
		}
	}
	
	//increment round number
	roundNbr++;

	//reset damage aggregated for round for printing purposes
	playerOneInflictedDamage = 0;
	playerTwoInflictedDamage = 0;
}



/******************************************************************
*                       Game::printBeginGame()
* Prints beginning game banner
/******************************************************************/
void Game::printBeginGame()
{
		cout << "``````````````````````````````````````````````````````````" << endl;
		cout << "```````````````````````BEGIN GAME`````````````````````````" << endl;
		cout << "``````````````````````````````````````````````````````````" << endl;	
}



/******************************************************************
*                       Game::printAttackResults
* Prints results of attack.
/******************************************************************/
void Game::printAttackResults(Character* attacker, int playerNbr)
{	

	//Check what arguments were sent for who the attacker and defender were for the given round
	if (playerNbr == 1) //Player 1 attacked Player 2
	{

		cout << "              Attacker: " << playerOneString << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << playerOneString  << " attacks with " << playerOne->getAttackAmnt() << " points." << endl;
		
		//Print player one special ability if it occured during attack
		playerOne->printSpecialAbility();

		cout << playerTwoString <<" defends with " << playerTwo->getDefenseAmnt() << " points." << endl;

		//Print player two special ability if it occured during defense
		playerTwo->printSpecialAbility();

		//Output calculation
		cout << "\nAttack - Defense - Armor" << endl;
		cout << setw(6)
			 << playerOne->getAttackAmnt() << " - "
			 << setw(7) << playerTwo->getDefenseAmnt() << " - "
			 << setw(5) << playerTwo->getArmor()
			 << setw(3) << " = " << playerTwoInflictedDamage << endl;
		if (playerTwoInflictedDamage == 0)
		{
			cout << "RESULT: No damage done (Inflicted damage = 0)" << endl;
		}
		else if (playerTwoInflictedDamage < 0)
		{
			cout << "RESULT: No damage done (negative inflicted damage)" << endl;
		}
		else if (playerTwoInflictedDamage > 0)
		{
			cout  << "RESULT: " << playerTwoString << " loses " << playerTwoInflictedDamage << " strength points." << endl;
		}
			
	}
	else if (playerNbr == 2) //Player 2 attacked Player 1
	{
		
		cout << "              Attacker: " << playerTwoString << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << playerTwoString << " attacks with " << playerTwo->getAttackAmnt() << " points." << endl;
		
		// Print player two special ability if it occured during attack
		playerTwo->printSpecialAbility();

		cout << playerOneString << " defends with " << playerOne->getDefenseAmnt() << " points." << endl;

		// Print player one special ability if it occured during defense
		playerOne->printSpecialAbility();
		
		//Output calculation
		cout << "\nAttack - Defense - Armor" << endl;
		cout << setw(6)
			<< playerTwo->getAttackAmnt() << " - "
			<< setw(7) << playerOne->getDefenseAmnt() << " - "
			<< setw(5) << playerOne->getArmor()
			<< setw(3) << " = " << playerOneInflictedDamage << endl;

		if (playerOneInflictedDamage == 0)
		{
			cout << "RESULT: No damage done (Inflicted damage = 0)" << endl;
		}
		else if (playerOneInflictedDamage < 0)
		{
			cout << "RESULT: No damage done (negative inflicted damage)" << endl;
		}
		else if (playerOneInflictedDamage > 0)
		{
			cout << "RESULT: " << playerOneString  << " loses " << playerOneInflictedDamage << " strength points." << endl;
		}
	}
}

/******************************************************************
* Game::printRoundHeader()
* Print header indicating which round number is occuring
/******************************************************************/

void Game::printRoundHeader()
{
	//Display which round we're in
	cout << "\n........................................................." << endl;
	cout << "|                      " << "Round " << roundNbr << "                          |" << endl;
	cout << ".........................................................\n\n" << endl;
	
}

/******************************************************************
* Game::printDeadCharacter(Character * whoDead, int deadPlayerNbr)
* If a player dies, round/game is over and output which player is dead
/******************************************************************/

void Game::printDeadCharacter(Character * whoDead, int deadPlayerNbr)
{
	if (deadPlayerNbr == 1)
	{
		cout << "\n" << playerOneString << " has died." << endl;
	}
	else if (deadPlayerNbr == 2)
	{
		cout << "\n" << playerTwoString << " has died." << endl;
	}
}


/******************************************************************
*                       Game::printRoundResults
* Output character attributes after attack and defense
/******************************************************************/
void Game::printRoundResults()
{
	//print results of round. include:
	// 1. Attacker Type
	// 2. Defender type, armor, strength point
	// 3. the attacker's attack dice roll
	// 4. The defender's defend dice roll
	// 5. The total inflicted damage calculation
	// 6. The defender's updated strength point amount after subtracting damage.
	
	cout << "\n              Character Health Status" << endl;

	cout << playerOneString;
	playerOne->printCharacterInfo();

	cout << playerTwoString;
	playerTwo->printCharacterInfo();

	cout << "\n\n" << endl;

}


/******************************************************************
*                       Game::printGameResults
* Print who the winner was
/******************************************************************/
void Game::printGameResults()
{
	switch (gameResult)
	{
	case NONE: cout << "no winner set" << endl;
		break;
	case TIE: cout << "game is tied" << endl;
		break;
	case PLAYER1: cout << playerOneString << " wins!\n" << endl;
		break;
	case PLAYER2: cout << playerTwoString << " wins!\n" << endl;
		break;
	}
}
