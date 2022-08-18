/*********************************************************************
** Program name: game.hpp
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Definitoin of game class
*********************************************************************/



#ifndef GAME_HPP
#define GAME_HPP

#include "barbarian.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

enum Outcome { NONE, TIE, PLAYER1, PLAYER2 };

class Game {

private:
	Character * playerOne;
	string playerOneString;
	int playerOneInflictedDamage;
	Character* playerTwo;
	string playerTwoString;
	int playerTwoInflictedDamage;
	int roundNbr;
	string attackDetailText;
	Outcome roundResult;
	string roundResultText;
	Outcome gameResult;
	string gameResultText;
	void setPlayerString(Character* charPlayer, int numPlayer);

public:
	Game();
	Game(CharacterType c1, CharacterType c2);
	~Game();
	void setPlayer1(Character* p1); // function allows setting player 1
	Character* getPlayer1();		// Function that returns player 1
	void setPlayer2(Character* p2); // function that allows setting player2
	Character* getPlayer2();		// Function that returns player 2
	void playRound();				// Function that implements a round -- 1 attack for each player
	void printBeginGame();			// Function that prints banner heading for game
	void playGame();				// Function that implements game series of rounds until character dies
	void printDeadCharacter(Character* whoDead, int deadPlayerNbr);
	void printAttackResults(Character* attacker, int playerNbr);
	void printRoundHeader();		// Prints heading for round
	void printRoundResults();		// Prints results of round
	void printGameResults();		// Prints winner of game

};

#endif