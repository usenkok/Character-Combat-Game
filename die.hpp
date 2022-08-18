
/*********************************************************************
** Program name: Die.cpp
** Author: Kelly Usenko
** Date: 4/22/2018
** Description: Main class defining dice characteristics (number of 
** sides) and contains roll dice function
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <climits>
#include <string>

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
using std::setfill;



class Die {
//private:

protected:
	int N;	 //integer representing number of sides of Die
	int nbr; //number for roll

public:
	Die(int);               //Default constructor takes an integer representing sides
	virtual ~Die();					//destructor
	virtual int rollDie();  //returns random integer between 1 and N
	int getSides();         //returns number of sides the Die has

};

#endif