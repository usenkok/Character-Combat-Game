/*********************************************************************
** Program name: medusa.hpp
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Definition of medusa classs
*********************************************************************/


#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"


class Medusa
	: public Character
{
private:
	bool glareInd; // Flag indicating if glare was activated

public:

	Medusa();
	~Medusa();
	int attack();
	void printSpecialAbility();
};
#endif