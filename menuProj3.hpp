/*********************************************************************
** Program name: menuProj3.hpp
** Author: Kelly Usenko
** Date: 5/13/2018
** Description: Definiton of menu allowing user to choose characters
** to battle
*********************************************************************/


#ifndef MENUPROJ3_HPP
#define MENUPROJ3_HPP


#include "barbarian.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

#include "die.hpp"
#include "game.hpp"

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


//functions
void printMainMenuTitle(); //Prints menu title
void printMenuOptions();
void printMenuPlayAgain();
void getValidInteger(int *result);
void getValidInteger(int *result, string promptForUser, int minInt, int maxInt);
bool validateIntegerInput(string userInput, int minVal, int maxVal);

#endif
