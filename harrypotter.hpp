/*********************************************************************
** Program name: harrypotter.hpp
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Definition of harrypotter derived class
*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"

class HarryPotter
	: public Character
{
private:
	bool hogwartsInd;
	int hogwartsCount;

public:
	HarryPotter();
	~HarryPotter();
	int defend(int attackerAmnt);
	void printSpecialAbility();

};


#endif
