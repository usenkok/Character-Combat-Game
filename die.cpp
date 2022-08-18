
/*********************************************************************
** Program name: Die.cpp
** Author: Kelly Usenko
** Date: 4/22/2018
** Description: Die class that accepts a number of sides and randomly
** generates an int for a dice roll event.
*********************************************************************/

#include "die.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::cin;
using std::stoi;
using std::stod;
using std::getline;
using std::string;
using std::fixed;
using std::showpoint;
using std::left;
using std::right;
using std::setprecision;
using std::setw;

/******************************************************************
*                  Die::Die
* Default constructor sets number of sides with argument passed
/******************************************************************/

Die::Die(int i) {

	this->N = i;
}

/******************************************************************
*                  Die::~Die
* destructor
/******************************************************************/

Die::~Die()
{
	//destructor
}


/******************************************************************
*                  Die::rollDie
* Generates random number off of seed set in Game class. Returns
* in within range of number of sides die has.
/******************************************************************/

int Die::rollDie() {

	this->nbr = rand() % this->N + 1;

	return this->nbr;
}



/******************************************************************
*                  Die::getSides
* Returns an integer indicating how many sides the die has.
/******************************************************************/

int Die::getSides() {

	return this->N;
}

