/*********************************************************************
** Program name:
** Author: Kelly Usenko
** Date: 5/14/2018
** Description:
**
*********************************************************************/


#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"

class Barbarian : public Character
{
private:

protected:

public:
	Barbarian();
	~Barbarian(); //Destructor
	void printSpecialAbility(); //Need to implement because pure abstract parent

};

#endif
