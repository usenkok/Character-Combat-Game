/*********************************************************************
** Program name: medusa.cpp
** Author: Kelly Usenko
** Date: 5/14/2018
** Description: Implementation of Medusa class
*********************************************************************/

#include "medusa.hpp"



/******************************************************************
*                       Medusa::Medusa
* Constructor
/******************************************************************/
Medusa::Medusa()
{
	this->attackAmnt = 0;
	this->attackRounds = 2;
	this->attackRange = 6;

	this->defenseAmnt = 0;
	this->defenseRounds = 1;
	this->defenseRange = 6;

	this->name = "Medusa";
	this->armor = 3;
	this->strength = 12;

	this->healthStatus = ALIVE;
	this->charType = MEDUSA;
	this->specialAbility = true;
	this->glareInd = false;

	//create attack and defense die
	this->attackDie = new Die(attackRange);
	this->defenseDie = new Die(defenseRange);

}


/******************************************************************
*                       Medusa::~Medusa
* Destructor
/******************************************************************/

Medusa::~Medusa()
{
	if (this->attackDie != NULL)
	{
		delete this->attackDie;
	}
	if (this->defenseDie != NULL)
	{
		delete this->defenseDie;
	}
}


/******************************************************************
*                       Medusa::attack()
*  Override of attack function to account for Medusa's special ability
* if she rolls a 12
/******************************************************************/

int Medusa::attack()
{
	this->attackAmnt = 0; //reset
	this->glareInd = false;

	//roll die and return combined total
	for (int i = 0; i < this->attackRounds; i++)
	{
		this->attackAmnt += this->attackDie->rollDie();
	}

	if (this->attackAmnt == 12)
	{
		this->attackAmnt = 999;
		this->glareInd = true;
	}
	
	return this->attackAmnt;
}


/******************************************************************
*                       Medusa::printSpecialAbility()
* Adds additional print statement if special ability activated
/******************************************************************/
void Medusa::printSpecialAbility()
{
	if (this->glareInd)
	{
		cout << "\n................... GLARE ..................." << endl;
		
		//reset glare
		this->glareInd = false;
	}
}
