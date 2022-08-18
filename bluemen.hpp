/*********************************************************************
** Program name: bluemen.hpp
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Definition of bluemen class
*********************************************************************/


#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "character.hpp"


class Bluemen
	: public Character
{
private:
	bool lostDefenseInd;


public:
	Bluemen();
	~Bluemen();
	void printCharacterInfo();
	void printSpecialAbility();
	int defend(int attackerAmnt);
};

#endif
