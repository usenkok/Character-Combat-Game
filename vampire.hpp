/*********************************************************************
** Program name: vampire.hpp
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Definition of vampire class
*********************************************************************/


#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"

class Vampire : public Character

{
private:
	Die* charmDie;
	bool charmInd;

public:

	Vampire();
	~Vampire();
	int defend(int d);
	void printSpecialAbility();
	void printCharmed();

};

#endif